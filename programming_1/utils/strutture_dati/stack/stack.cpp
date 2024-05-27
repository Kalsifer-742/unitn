#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* next;
};

void push(int val, node*& stack);
int pop(node*& stack);
int top(node* stack);
void initialize_stack(node*& stack);
void delete_stack(node*& stack);
int stack_height(node* stack);
void print_stack(node* stack);

void push(int val, node*& stack)
{
    node* tmp = new node{val, NULL};
    if(stack == NULL){
        stack = tmp;
    }
    else
    {
        tmp->next = stack;
        stack = tmp;
    }
}

void initialize_stack(node*& stack)
{
    for (int i = 1; i < 11; i++)
    {
        push(i, stack);
    }
}

int pop(node*& stack)
{
    if(stack == NULL){
        return -1;
    }
    else
    {
        int top = stack->value;
        node* tmp = stack;
        stack = tmp->next;
        delete tmp;
        tmp->next = NULL;
        return top;  
    }
}

int top(node* stack)
{
    if(stack == NULL){
        return -1;
    }
    else
    {
        return stack->value;  
    }
}

void delete_stack(node*& stack)
{
    if(stack == NULL)
    {
        return;
    }
    else
    {
        node* current = stack;
        while (current != NULL)
        {
            node* tmp = current;
            current = tmp->next;
            delete tmp;
        }
        delete current;
        stack = NULL;
    }
}

int stack_height(node* stack)
{
    node* current = stack;
    int c = 0;
    while (current != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}

void print_stack(node* stack)
{
    node* current = stack;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}