mod odd_module {
    pub const CONSTANT: i32 = 123;
}

mod even_module {
    pub const CONSTANT: i32 = 246;
}

mod getter_function {
    pub fn get_constant(value: u32) -> i32 {
        if value % 2 != 0 {
            // use crate::odd_module::CONSTANT;
            // return CONSTANT;
            super::odd_module::CONSTANT
        } else {
            super::even_module::CONSTANT
        }
    }
}

use std::cell::RefCell;
use std::collections::{HashSet, LinkedList, VecDeque};
use std::fmt::{Debug, Display, Formatter};
use std::hash::Hash;
use std::ops::Add;
use std::rc::Rc;
use crate::getter_function::get_constant;

trait CloneAndDouble {
    fn clone_and_double(&self) -> Self;
}

impl<T: Clone + Add<Output = T>> CloneAndDouble for T {
    fn clone_and_double(&self) -> Self {
        self.clone() + self.clone()
    }
}

trait Unknown {
    fn serialize(&self) -> String;
}

impl Unknown for i32 {
    fn serialize(&self) -> String {
        self.to_string()
    }
}

impl Unknown for String {
    fn serialize(&self) -> String {
        self.clone()
    }
}

impl<T: Debug> Unknown for Vec<T> {
    fn serialize(&self) -> String {
        // let mut result = String::new();
        // for v in self {
        //     result.push_str(format!("{:?}", v).as_str());
        // }
        // return  result;
        format!("{:?}", self)
    }
}

#[allow(dead_code)]
fn get_vec<T: Unknown>() -> Vec<T> {
    Vec::<T>::new()
}

#[allow(dead_code)]
fn get_vec_2() -> Vec<Box<dyn Unknown>> {
    Vec::new()
}

#[allow(dead_code)]
fn print_vec(input: &Vec<Box<dyn Unknown>>) {
    for v in input {
        println!("{:?}", v.serialize());
    }
}

struct BinIter {
    n: u32,
    l: usize
}

impl BinIter {
    fn new(n: u32, l: usize) -> Self {
        Self { n, l }
    }
}

impl Iterator for BinIter {
    type Item = bool;

    //meme implementation. experimenting with rust
    fn next(&mut self) -> Option<Self::Item> {
        let binary = format!("{:b}", self.n);

        return if self.l == 0 {
            None
        } else if binary.chars().nth(self.l-1).unwrap() == '0' {
            self.l -= 1;
            Some(false)
        } else {
            self.l -= 1;
            Some(true)
        }
    }
}

struct Node<T> {
    element: T,
    prev: Option<Rc<RefCell<Node<T>>>>,
    next: Option<Rc<RefCell<Node<T>>>>
}

struct List<T> {
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
    size: usize
}

impl<T: PartialEq> PartialEq for Node<T> {
    fn eq(&self, other: &Self) -> bool {
        self.element == other.element
    }
}

impl<T: Display> Display for Node<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.element)
    }
}

impl<T: PartialEq> PartialEq for List<T> {
    fn eq(&self, other: &Self) -> bool {
        let mut current_head = self.head.clone();
        let mut other_current_head = other.head.clone();

        loop {
            if let (Some(current_node), Some(other_current_node)) = (current_head, other_current_head) {
                if current_node.borrow().element != other_current_node.borrow().element {
                    return false;
                }
                current_head = current_node.borrow().next.clone();
                other_current_head = other_current_node.borrow().next.clone();
            } else {
                return false;
            }
        }
    }
}

impl<T: Display> Debug for List<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        let mut current_head = self.head.clone();
        write!(f, "[List]->")?;
        loop {
            if let Some(current_node) = current_head {
                write!(f, "[{}]->", current_node.borrow())?;
                current_head = current_node.borrow().next.clone();
            } else {
                write!(f, "[None]")?;
                break;
            }
        }
        Ok(())
    }
}

impl<T: Display> Display for List<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        let mut current_head = self.head.clone();
        loop {
            if let Some(current_node) = current_head {
                write!(f, "[{}]", current_node.borrow())?;
                current_head = current_node.borrow().next.clone();
            } else { break }
        }
        Ok(())
    }
}

impl<T> Node<T> {
    fn new(element: T) -> Node<T> {
        Node {
            element,
            prev: None,
            next: None
        }
    }
}

//memory leak ?
impl<T: Clone + Display> List<T> {
    fn new() -> List<T> {
        List {
            head: None,
            tail: None,
            size: 0
        }
    }

    fn print_list(&self) {
        println!("{}", self);
    }

    fn push(&mut self, element: T) {
        let new_head = Rc::new(RefCell::new(Node::new(element)));
        match self.head.take() {
            None => {
                self.head = Some(Rc::clone(&new_head));
                self.tail = Some(Rc::clone(&new_head));

                self.size = 1;
            }
            Some(current_head) => {
                current_head.borrow_mut().prev = Some(Rc::clone(&new_head));
                new_head.borrow_mut().next = Some(Rc::clone(&current_head));
                self.head = Some(new_head);

                self.size += 1;
            }
        }
    }

    fn pop(&mut self) -> Option<T> {
        return match self.head.take() {
            None => { None }
            Some(current_head) => {
                match current_head.borrow_mut().next.take() {
                    None => {
                        self.head = None;
                        self.tail = None;
                    }
                    Some(new_head) => {
                        new_head.borrow_mut().prev = None;
                        self.head = Some(new_head);
                    }
                }

                self.size -= 1;
                Some(current_head.borrow().element.clone())
            }
        }
    }

    fn push_back(&mut self, element: T) {
        let new_tail = Rc::new(RefCell::new(Node::new(element)));
        match self.tail.take() {
            None => {
                self.head = Some(Rc::clone(&new_tail));
                self.tail = Some(Rc::clone(&new_tail));

                self.size = 1;
            }
            Some(current_tail) => {
                current_tail.borrow_mut().next = Some(Rc::clone(&new_tail));
                new_tail.borrow_mut().prev = Some(Rc::clone(&current_tail));
                self.tail = Some(new_tail);

                self.size += 1;
            }
        }
    }

    fn pop_back(&mut self) -> Option<T> {
        return match self.tail.take() {
            None => { None }
            Some(current_tail) => {
                match current_tail.borrow_mut().prev.take() {
                    None => {
                        self.head = None;
                        self.tail = None;
                    }
                    Some(new_tail) => {
                        new_tail.borrow_mut().next = None;
                        self.tail = Some(new_tail);
                    }
                }

                self.size -= 1;
                Some(current_tail.borrow().element.clone())
            }
        }
    }
}

#[derive(Clone, PartialEq, Eq, Hash)]
struct GraphNode<T: Hash + PartialEq + Eq> {
    value: T,
    adj_nodes: Vec<Rc<GraphNode<T>>>
}

struct Graph<T: Hash + PartialEq + Eq> {
    nodes: Vec<Rc<GraphNode<T>>>
}

impl<T: Hash + PartialEq + Eq> GraphNode<T> {
    fn new(value: T, adj_nodes: Vec<Rc<GraphNode<T>>>) -> Rc<GraphNode<T>> {
        Rc::new(GraphNode { value, adj_nodes })
    }

    fn get_value(&self) -> &T {
        &self.value
    }
}

impl<T: Hash + PartialEq + Eq + Debug> Debug for GraphNode<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "[value: {:?}, ", self.value)?;
        let mut adj_nodes = String::new();
        adj_nodes.push_str("adjacents: [");
        for adj_node in &self.adj_nodes {
            adj_nodes.push_str(format!("{:?}, ", adj_node.value).as_str());
        }
        adj_nodes.push_str("]]");
        write!(f, "{adj_nodes}")
    }
}

impl<T: Hash + PartialEq + Eq> Graph<T> {
    fn new(nodes: Vec<Rc<GraphNode<T>>>) -> Graph<T> {
        Graph {
            nodes
        }
    }

    fn dfs(&self, root: Rc<GraphNode<T>>) -> Vec<Rc<GraphNode<T>>> {
        let mut visited = HashSet::<Rc<GraphNode<T>>>::new();
        let mut history = Vec::<Rc<GraphNode<T>>>::new();
        let mut stack = VecDeque::<Rc<GraphNode<T>>>::new();

        stack.push_front(root.clone());
        while !stack.is_empty() {
            let current_node = stack.pop_front().unwrap();
            if visited.insert(Rc::clone(&current_node)) {
                history.push(Rc::clone(&current_node));
                for adj_node in current_node.adj_nodes.iter() { //rev() to simulate the recursive version
                    stack.push_front(Rc::clone(&adj_node));
                }
            }
        }

        return history;
    }
}

trait Task {
    fn execute(&self) -> usize;
}

struct SumTask {
    n1: usize,
    n2: usize
}
struct LenTask {
    s: String
}

impl SumTask {
    fn new(n1: usize, n2: usize) -> Self {
        Self { n1, n2 }
    }
}

impl LenTask {
    fn new(s: String) -> Self {
        Self { s }
    }
}

impl Task for SumTask {
    fn execute(&self) -> usize {
        self.n1 + self.n2
    }
}

impl Task for LenTask {
    fn execute(&self) -> usize {
        self.s.len()
    }
}

struct Tasker {
    queue: Rc<RefCell<LinkedList<Box<dyn Task>>>>
}
struct Executer {
    queue: Rc<RefCell<LinkedList<Box<dyn Task>>>>
}

impl Tasker {

    fn new() -> Self {
        Self {
            queue: Rc::new(RefCell::new(LinkedList::<Box<dyn Task>>::new()))
        }
    }

    fn get_tasker(&self) -> Tasker {
        Self {
            queue: Rc::clone(&self.queue)
        }
    }

    fn get_executer(&self) -> Executer {
        Executer {
            queue: Rc::clone(&self.queue)
        }
    }

    fn schedule_task(&mut self, task: Box<dyn Task>) {
        self.queue.borrow_mut().push_back(task);
    }
}

impl Executer {
    fn execute_task(&mut self) -> Option<usize> {
        return match self.queue.borrow_mut().pop_front() {
            None => { None }
            Some(t) => { Some(t.execute()) }
        }
    }
}

fn main() {
    println!("{}", get_constant(1));

    let bin = BinIter::new(8, 4);
    for b in bin {
        match b {
            true => { print!("1") }
            false => { print!("0") }
        }
    }
    println!();

    let mut double_linked_list = List::new();

    double_linked_list.push(1);
    double_linked_list.push(2);
    double_linked_list.push(3);
    double_linked_list.push(4);

    double_linked_list.print_list();
    println!("{:?}", double_linked_list);

    match double_linked_list.pop() {
        None => {}
        Some(v) => { println!("{v}") }
    }
    println!("{:?}", double_linked_list);
    match double_linked_list.pop() {
        None => { println!("None") }
        Some(v) => { println!("{v}") }
    }
    println!("{:?}", double_linked_list);

    double_linked_list.push_back(3);
    double_linked_list.push_back(4);

    println!("{:?}", double_linked_list);

    match double_linked_list.pop_back() {
        None => { println!("None") }
        Some(v) => { println!("{v}") }
    }
    println!("{:?}", double_linked_list);
    match double_linked_list.pop_back() {
        None => { println!("None") }
        Some(v) => { println!("{v}") }
    }
    println!("{:?}", double_linked_list);

    let (node2, node9, node6) = (
        GraphNode::new(2, vec![]),
        GraphNode::new(9, vec![]),
        GraphNode::new(6, vec![]),

    );
    let node5 = GraphNode::new(5, vec![node6.clone()]);
    let node1 = GraphNode::new(1, vec![node2.clone(), node5.clone(), node9.clone()]);
    let nodes = vec![node1.clone(), node2, node5, node9, node6];

    let graph = Graph::new(nodes);
    for node in graph.dfs(node1.clone()) {
        println!("{:?}", node);
    }

    let mut tasker = Tasker::new();
    tasker.schedule_task(Box::new(SumTask::new(0, 1)));
    tasker.schedule_task(Box::new(SumTask::new(2, 1)));
    tasker.schedule_task(Box::new(LenTask::new("Ciao".to_string())));
    tasker.schedule_task(Box::new(LenTask::new("Missile".to_string())));
    let mut executer = tasker.get_executer();
    match executer.execute_task() {
        None => {}
        Some(result) => { println!("{result}") }
    }
    match executer.execute_task() {
        None => {}
        Some(result) => { println!("{result}") }
    }
    match executer.execute_task() {
        None => {}
        Some(result) => { println!("{result}") }
    }
}
