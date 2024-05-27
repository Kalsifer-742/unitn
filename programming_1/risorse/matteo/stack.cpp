#include "stack.hpp"

stack stack_init() {
    return stack{ list_init() };
}

void deinit(stack& s) {
    deinit(s.internal_list);
}

void push(stack& s, stack_value_t val) {
    push_front(s.internal_list, val);
}

stack_value_t pop(stack& s) {
    return pop_front(s.internal_list);
}

stack_value_t top(stack& s) {
    return front(s.internal_list);
}

long get_length(stack& s) {
    return get_length(s.internal_list);
}

bool is_empty(stack& s) {
    return is_empty(s.internal_list);
}

void print(std::ostream& out_stream, stack& s) {
    print_reverse(out_stream, s.internal_list);
}
void print(stack& s) {
    print_reverse(s.internal_list);
}
