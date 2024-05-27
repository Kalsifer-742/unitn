#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* previous;
    node* next;
};

struct list
{
    node* head;
    node* tail;
};

void insert_to_head(int val, list& list);
void insert_to_tail(int val, list& list);
void insert_node_after_index(list& list, node*& new_node, int index);
void insert_after_node(list& list, node*& n, node*& new_node);
void initialize_list(list& list);
void delete_node_at_index(list& list, int index);
void delete_list(list& list);
void print_list(list list);
int list_length(list list);
bool is_in_list(int val, list list);
node* linear_search_first_occurence_in_list(int val, list list);
int linear_search_first_index_in_list(int val, list list);
int get_value_at_index(int index, list list);
void bubble_sort_list(list& list);

void insert_to_head(int val, list& l)
{
    node* tmp = new node{val, NULL, NULL};
    if(l.head == NULL && l.tail == NULL){
        l = {tmp, tmp};
    }
    else
    {
        tmp->next = l.head;
        l.head = tmp;
    }
}

void insert_to_tail(int val, list& l)
{
    node* tmp = new node{val, NULL, NULL};
    if(l.head == NULL && l.tail == NULL){
        l = {tmp, tmp};
    }
    else
    {
        tmp->previous = l.tail;
        l.tail->next = tmp;
        l.tail = tmp;
    }
}

void insert_node_after_index(list& l, node*& new_node, int index)
{
    if(l.head == NULL){
        return;
    }
    else
    {
        node* current = l.head;
        for (int i = 0; i <= index; i++)
        {
            if(i == index){
                new_node->previous = current;
        
                if (current->next == NULL)
                {
                    new_node->next = NULL;
                    l.tail = new_node;
                }
                else
                {
                    new_node->next = current->next;
                    current->next->previous = new_node;        
                }

                current->next = new_node;
                
            }
            current = current->next;
        }
        
    }
    return;
}

void insert_after_node(list& l, node*& n, node*& new_node)
{
    new_node->previous = n;
         
    if (n->next == NULL)
    {
        new_node->next = NULL;
        l.tail = new_node;
    }
    else
    {
        new_node->next = n->next;
        n->next->previous = new_node;        
    }

    n->next = new_node;
}

void initialize_list(list& list)
{
    for (int i = 1; i < 11; i++)
    {
        insert_to_tail(i, list);
    }
}

void delete_list(list& l){
    if(l.head == NULL)
    {
        return;
    }
    else
    {
        node* current = l.head;
        while (current != NULL)
        {
            node* tmp = current;
            current = tmp->next;
            delete tmp;
        }
        delete current;
        l.head = NULL;
        l.tail = NULL;
    }
}

void delete_node_at_index(list& l, int index)
{
    if(l.head == NULL){
        return;
    }
    else
    {
        node* current = l.head;
        for (int i = 0; i <= index; i++)
        {
            if(i == index){
                if(current->previous == NULL)
                {
                    l.head = current->next;
                }
                else
                {
                    current->previous->next = current->next;
                }
                if (current->next == NULL)
                {
                    l.tail = current->previous;
                }
                else
                {
                    current->next->previous = current->previous;
                }
                delete current;
            }
            current = current->next;
        }
        
    }
    return;
}

void print_list(list l)
{
    node* current = l.head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int list_length(list l)
{
    node* current = l.head;
    int c = 0;
    while (current != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}

bool is_in_list(int val, list l)
{
    if(l.head == NULL){
        return false;
    }
    else
    {
        node* current = l.head;
        while (current != NULL)
        {
            if(val == current->value)
            {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

node* linear_search_first_occurence_in_list(int val, list l)
{
    if(l.head == NULL){
        return NULL;
    }
    else
    {
        node* current = l.head;
        while (current != NULL)
        {
            if(val == current->value)
            {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}

int linear_search_first_index_in_list(int val, list l)
{
    if(l.head == NULL){
        return -1;
    }
    else
    {
        int c = 0;
        node* current = l.head;
        while (current != NULL)
        {
            if(val == current->value)
            {
                return c;
            }
            c++;
            current = current->next;
        }
    }
    return -1;
}

int get_value_at_index(int index, list l)
{
    if(l.head == NULL){
        return -1;
    }
    else
    {
        node* current = l.head;
        for (int i = 0; i <= index; i++)
        {
            if(i == index)
            {
                return current->value;
            }
            current = current->next;
        }
        
    }
    return -1;
}

void bubble_sort_list(list& l)
{
    int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;

		node* current = l.head;
        while (current->next != NULL)
        {
            if(current->value > (current->next)->value)
            {
                tmp = current->value;
                current->value = (current->next)->value;
                (current->next)->value = tmp;
                swapped = true;
            }
            current = current->next;
        }
	}
}