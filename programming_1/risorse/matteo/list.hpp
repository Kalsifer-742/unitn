#ifndef UTILS_LIST_HPP
#define UTILS_LIST_HPP

#include <ostream>

//uso un typedef per distinguere quando una variabile rappresenta un valore nella lista o un indice (o altro)
typedef char list_value_t;

struct node {
    list_value_t val;
    node* next;
};

struct list {
    node* head;
};

/* init-deinit */
list list_init();
void deinit(list& l);

/* push */
list& push_front(list& l, list_value_t val);
list& push_back(list& l, list_value_t val);

/* pop (assume !is_empty) */
list_value_t pop_front(list& l);
list_value_t pop_back(list& l);
list_value_t front(list& l);

/* ordinamento e inserimento ordinato */
void insert_ordered(list& l, list_value_t val);
list& sort(list &l);

long get_length(list& l);
bool is_empty(list& l);

list& reverse(list& l);

long find_element(list& l, list_value_t val);

list& delete_by_value(list& l, list_value_t val);
list& delete_by_index(list& l, long index);

/* stampa */
void print(std::ostream&, list&, const char* spacing = " ");
void print(list&, const char* spacing = " ");
void print_reverse(std::ostream&, list&, const char* spacing = " ");
void print_reverse(list&, const char* spacing = " ");


/* utilities */
list_value_t remove_at(node**);
void insert_at(node**, list_value_t);

node** last_link(list&);
node** last_valid_link(list&);

void advance(node*& iterator);
void advance(node**& iterator);

#endif
