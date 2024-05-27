#include "queue.hpp"

queue queue_init() {
    queue q;
    q.internal_list = list_init();
    q.tail = nullptr;
    return q;
}

void deinit(queue& q) {
    deinit(q.internal_list);
    q.tail = nullptr;
}

void enqueue(queue& q, list_value_t val) {
    if(q.tail == nullptr) {
        insert_at(&q.internal_list.head, val);
        q.tail = q.internal_list.head;
    }
    else {
        insert_at(&q.tail->next, val);
        advance(q.tail); 
    }
}

list_value_t dequeue(queue& q) {
    list_value_t ret = pop_front(q.internal_list);

    if(is_empty(q.internal_list))
        q.tail = nullptr;

    return ret;
}

list_value_t first_inserted(queue& q) {
    return front(q.internal_list);
}

void print(std::ostream& out_stream, queue& q) {
    print(out_stream, q.internal_list);
}
void print(queue& q) {
    print(q.internal_list);
}
