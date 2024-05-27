#ifndef UTILS_QUEUE_HPP
#define UTILS_QUEUE_HPP

#include "list.hpp"

struct queue {
    list internal_list;
    node* tail; // un puntatore all'ultimo nodo permette complessità O(k) nell'inserimento alla fine della coda
};

queue queue_init();
void deinit(queue&);
void enqueue(queue& q, list_value_t val);
list_value_t dequeue(queue& q);
list_value_t first_inserted();


void print(std::ostream& out_stream, queue& q);
void print(queue& q);

#endif
