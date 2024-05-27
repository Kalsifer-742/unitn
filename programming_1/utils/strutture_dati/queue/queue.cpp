#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* previous;
    node* next;
};

struct queue
{
    node* head;
    node* tail;
};

void enqueue(int val, queue& q);
int dequeue(queue& q);
int get_back(queue q);
int get_front(queue q);
void initialize_queue(queue& q);
void delete_queue(queue& q);
void print_queue(queue q);
int queue_length(queue q);

void enqueue(int val, queue& q)
{
    node* tmp = new node{val, NULL, NULL};
    if(q.head == NULL && q.tail == NULL){
        q = {tmp, tmp};
    }
    else
    {
        tmp->next = q.head;
        q.head->previous = tmp;
        q.head = tmp;
    }
}

int dequeue(queue& q)
{
    if(q.tail == NULL){
        return -1;
    }
    else
    {
        int tmp = q.tail->value;
        node* tmp_node = q.tail;
        q.tail = tmp_node->previous;
        delete tmp_node;
        q.tail->next = NULL;
        return tmp;
    }
}

int get_back(queue q)
{
    if(q.head == NULL){
        return -1;
    }
    else
    {
        return q.head->value;
    }
}

int get_front(queue q)
{
    if(q.tail == NULL){
        return -1;
    }
    else
    {
        return q.tail->value;
    }
}

void initialize_queue(queue& q)
{
    for (int i = 1; i < 11; i++)
    {
        enqueue(i, q);
    }
}

void delete_queue(queue& q)
{
    if(q.head == NULL)
    {
        return;
    }
    else
    {
        node* current = q.head;
        while (current != NULL)
        {
            node* tmp = current;
            current = tmp->next;
            delete tmp;
        }
        delete current;
        q.head = NULL;
        q.tail = NULL;
    }
}

void print_queue(queue q)
{
    node* current = q.head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int queue_length(queue q)
{
    node* current = q.head;
    int c = 0;
    while (current != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}