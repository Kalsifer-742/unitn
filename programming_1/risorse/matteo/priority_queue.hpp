#ifndef UTILS_PRIORITY_QUEUE_HPP
#define UTILS_PRIORITY_QUEUE_HPP

#include <ostream>

typedef long priority_queue_val_t;

struct priority_queue_node {
    priority_queue_node* next;
    long priority;
    priority_queue_val_t value;
};

struct priority_queue {
    priority_queue_node* head;
};

priority_queue priority_queue_init();
void deinit(priority_queue& q);
bool empty(priority_queue& q);
void enqueue(priority_queue& q, priority_queue_val_t val, long priority);
priority_queue_val_t dequeue(priority_queue& q);
void advance(priority_queue_node*& iterator);
void advance(priority_queue_node**& iterator);
void print(std::ostream& out_stream, priority_queue& q, const char* spacing = " ");

#endif
