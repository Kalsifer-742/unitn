fn prev_char(c: char) -> char {
    if c.is_ascii_alphabetic() && c != 'A' && c != 'a' {
        return (c as u8 - 1u8) as char;
    } else {
        return c;
    }
}

fn prev_str(input: &str) -> String {
    let mut new_string = String::new();
    for c in input.chars() {
        new_string.push(prev_char(c));
    }

    return new_string;
}

struct X {
    s: Option<String>,
    i: i32
}

impl X {
    fn new(s: &str, i: i32) -> Self {
        Self {
            s: Some(s.to_string()),
            i
        }
    }

    fn take_str(&mut self) -> Option<String>{
        self.s.take()
    }
}

use std::mem::swap;

struct NameSurname {
    name: String,
    surname: String
}

fn replace_surname(mut name_surname: NameSurname, mut input: String) -> String {
    swap(&mut name_surname.surname, &mut input);
    return input;
}

use std::fmt::{Display, Formatter};

#[derive(Clone, Debug)]
struct Student {
    name: String,
    id: u32
}

impl Student {
    fn new(name: &str, id: u32) -> Self {
        Self{
            name: name.to_string(),
            id
        }
    }
}

impl Display for Student {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "Student {{ name \"{}\", id: {} }}", self.name, self.id)
    }
}

struct University {
    name: String,
    students: Vec<Student>
}

impl University {
    fn new(name: &str, students: &Vec<Student>) -> Self {
        Self {
            name: name.to_string(),
            students: students.to_vec()
        }
    }

    fn remove_student(&mut self, id: u32) -> Result<Student, &str> {
        let idx = self.students
            .iter()
            .position(|s| s.id == id);

        return match idx {
            None => { Err("Not found") }
            Some(i) => { Ok(self.students.remove(i)) }
        }
    }
}

impl Display for University {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}\n", self.name)?;
        let mut students = Vec::new();
        write!(f, "Students: ")?;
        for student in self.students.iter() {
            students.push(student);
        }
        write!(f, "{:?}", students)
    }
}

#[derive(PartialEq, Debug, Clone)]
enum AirplaneCompany {
    Airbus,
    Boeing
}

#[derive(Clone)]
struct Airplane {
    company: AirplaneCompany,
    model: String
}

struct AirFleet {
    fleet: Vec<Airplane>
}

impl AirFleet {
    fn remove_boeing(&mut self) {
        self.fleet = self.fleet
            .iter()
            .filter(|a| a.company != AirplaneCompany::Boeing)
            .map(|a| (*a).clone())
            .collect()
    }

    fn add_airplane(&mut self, a: Airplane) {
        self.fleet.push(a);
    }

    fn search_airplane(&self, model: &str) -> Result<AirplaneCompany, String> {
        match self.fleet.iter().find(|a| a.model == model) {
            None => { Err("Not in this fleet".to_string()) }
            Some(a) => { Ok(a.clone().company) }
        }
    }
}

use crate::random::string_to_tuple;
use crate::hashmaps::Maps;
use std::collections::HashMap;

mod unumber {
    pub type Unumber = usize;
}

mod hashmaps {
    use crate::unumber::Unumber;
    use std::collections::HashMap;

    pub struct Maps{
        pub map: HashMap<Unumber, String>
    }
}

mod random {
    use std::collections::HashMap;
    use crate::hashmaps::Maps;
    use crate::unumber::Unumber;

    pub fn string_to_tuple(maps: Maps) -> HashMap<Unumber, (Unumber, String)> {
        let mut new = HashMap::<Unumber, (Unumber, String)>::new();

        for map in maps.map {
            new.insert(map.0, (map.1.len(), map.1));
        }

        return new;
    }
}

struct Size {
    width: f32,
    height: f32,
}

impl Size {
    fn new(w: f32, h: f32) -> Self {
        Self {
            width: w,
            height: h
        }
    }

    fn area(&self) -> f32 {
        self.width * self.height
    }

    fn compare(&self, other: &Size) -> Option<bool> {
        if self.area() == other.area() {
            None
        } else if self.area() > other.area() {
            Some(true)
        } else {
            Some(false)
        }
    }
}

struct MaybePoint {
    x: Option<i32>,
    y: Option<i32>
}

impl MaybePoint {
    fn new(x: Option<i32>, y: Option<i32>) -> Self {
        Self {
            x,
            y
        }
    }

    fn is_some(&self) -> bool {
        if self.x.is_some() && self.y.is_some() {
            true
        } else {
            false
        }
    }

    fn maybe_len(&self) -> Option<f32> {
        if self.x.is_none() || self.y.is_none() {
            None
        } else {
            let x = self.x.unwrap();
            let y = self.y.unwrap();
            Some(f32::sqrt(x.pow(2) as f32 + y.pow(2) as f32))
        }
    }
}

fn res1(n: i32) -> Result<i32, String> {
    if n % 10 == 0 {
        Ok(n)
    } else {
        Err("error".to_string())
    }
}

fn res2(n: i32) -> Result<i32, String> {
    if n % 5 == 0 {
        Ok(n)
    } else {
        Err("error".to_string())
    }
}

fn wrapper(n: i32) -> Result<i32, String> {
    if res1(n).is_ok() && res2(n).is_ok() {
        Ok(n)
    } else {
        Err("error".to_string())
    }
}

fn order(mut input: Vec<String>) -> Vec<String> {
    for (i, s) in input.iter_mut().enumerate() {
        *s = format!("{i} - {s}");
    }

    input
}

mod modx {
    pub enum X {
        S(char),
        C(String),
    }
}

mod mody{
    pub enum X {
        F(f64, usize)
    }
}

mod modsum {
    use crate::modx::X as xX;
    use crate::mody::X as yX;

    pub fn sum(x: xX, y: yX) -> f64 {
        let yX::F(float_v, usize_v) = y;
        let product = float_v * usize_v as f64;

        return match x {
            xX::S(c) => { c.to_digit(10).unwrap_or_else(|| 32) as f64 + product  }
            xX::C(s) => { s.len() as f64 + product }
        }
    }
}

use crate::modsum::sum;

pub fn main(){
    let c = 's';
    println!("{}", prev_char(c));

    let s = "abcdefg_1234_ABCDEFG";
    let s = prev_str(s);
    println!("{}", s);

    let mut x = X::new("ciao", 10);

    let s = x.take_str();
    println!("{}", s.unwrap() );

    let person1: NameSurname = NameSurname {
        name: "Ernesto".to_string(),
        surname: "Bianchi".to_string(),
    };
    let surname = "sassi".to_string();
    let a = replace_surname(person1, surname);
    println!("{}", a);

    let s1 = Student::new("marco", 1);
    let s2 = Student::new("anto", 2);
    let s3 = Student::new("anna", 3);
    let mut university = University::new("Trento", &vec![s1, s2, s3]);

    println!("{}", university);

    println!("{}", university.remove_student(1).unwrap().id);

    let mut fleet = AirFleet{
        fleet: Vec::new(),
    };

    let airplane1 = Airplane{
        company: AirplaneCompany::Airbus,
        model: "A380".to_string(),
    };

    let airplane2 = Airplane{
        company: AirplaneCompany::Boeing,
        model: "747".to_string(),
    };

    let airplane3 = Airplane{
        company: AirplaneCompany::Airbus,
        model: "A320".to_string(),
    };

    fleet.add_airplane(airplane1);
    fleet.add_airplane(airplane2);
    fleet.add_airplane(airplane3);

    println!("{:?}", fleet.search_airplane("A380"));
    println!("{:?}", fleet.search_airplane("747"));
    println!("{:?}", fleet.search_airplane("A320"));
    println!("{:?}", fleet.search_airplane("A330"));

    let mut hashmap = HashMap::new();
    hashmap.insert(1, "ciao".to_string());
    hashmap.insert(2, "ciao".to_string());
    hashmap.insert(3, "ciao".to_string());

    let hashmap = Maps{
        map: hashmap,
    };

    let hashmap = string_to_tuple(hashmap);

    println!("{:?}", (hashmap.get(&1).unwrap().0, hashmap.get(&1).unwrap().1.clone()));

    use std::fmt::{Debug, Formatter};

    impl Debug for Size {
        fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
            write!(f, "Size {{ width: {}, height: {} }}", self.width, self.height)
        }
    }

    let s = Size::new(5.7, 1.2);

    println!("{:?}", s.area());
    println!("{:?}", s.compare(&Size::new(8.9, 10.)));
    println!("{:?}", s.compare(&Size::new(1.8, 0.1)));
    println!("{:?}", s.compare(&Size::new(5.7, 1.2)));

    let x = MaybePoint::new(Some(10),Some(20));
    let y = MaybePoint{x:Some(10),y:None};

    println!("{:?}", x.is_some());
    println!("{:?}", y.is_some());
    println!("{:?}", x.maybe_len());
    println!("{:?}", y.maybe_len());

    println!("{:?}", wrapper(10));
    println!("{:?}", wrapper(5));
    println!("{:?}", wrapper(11));

    let a :Vec<String> = vec!["Ciao".to_string(), "Come".to_string(), "Va".to_string()];

    let b = order(a);
    println!("{}", b.get(1).unwrap().to_owned());
    println!("{}", b.get(2).unwrap().to_owned());

    println!("{}", sum(modx::X::S(' '), mody::X::F(1.2, 4)));
    println!("{}", sum(modx::X::C("hello".to_owned()), mody::X::F(2.4, 10)))
}