#ifndef UTILS_STACK_HPP
#define UTILS_STACK_HPP

#include "list.hpp"

typedef list_value_t stack_value_t;

struct stack {
    list internal_list;
};

stack stack_init();
void deinit(stack&);

void push(stack&, stack_value_t);
stack_value_t pop(stack&);
stack_value_t top(stack&);

long get_length(stack&);
bool empty();

void print(std::ostream&, stack&);
void print(stack&);
#endif
