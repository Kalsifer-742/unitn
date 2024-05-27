#include "priority_queue.hpp"
#include <cstddef>

priority_queue priority_queue_init() {
    return { NULL };
}

void deinit(priority_queue& q) {
    while(q.head != NULL)
        dequeue(q);
}

bool empty(priority_queue& q) {
    return q.head == NULL;
}

static void insert_ordered_node(priority_queue& q, priority_queue_node* n) {
    //itero i nodi cercando il primo con priorita' minore
    priority_queue_node** iterator = &q.head;
    bool inserted = false;

    while(!inserted) {
        if(*iterator != NULL) {
            //se il nodo successivo ha meno priorita', inserisci il nodo
            if(n->priority > (*iterator)->priority) {
                n->next = *iterator;
                *iterator = n;
                inserted = true;
            }
            //altrimenti continua a iterare
            else {
                advance(iterator);
            }
        }
        //se raggiungi la fine della coda, inserisci il nodo li'
        else {
            n->next = NULL;   
            *iterator = n;    
            inserted = true;
        } 
    }
}

void enqueue(priority_queue& q, priority_queue_val_t val, long priority) {
    insert_ordered_node(q, new priority_queue_node { NULL, priority, val });
}

priority_queue_val_t dequeue(priority_queue& q) {
    //trova il nodo da eliminare
    priority_queue_node* to_be_deleted = q.head;
    priority_queue_val_t v = to_be_deleted->value;
    //avanza la testa della queue per 'saltare' il nodo da eliminare
    advance(q.head);

    delete to_be_deleted;
    return v;
}

void advance(priority_queue_node*& iterator) {
    iterator = iterator->next;
}
//avanza un iteratore capace di modificare il puntatore a cui si riferiscono
void advance(priority_queue_node**& iterator) {
    iterator = &(**iterator).next;
}

void print(std::ostream& out_stream, priority_queue& q, const char* spacing) {
    //itero sui nodi stampando i valori
    priority_queue_node* iterator = q.head;
    while(iterator != NULL) {
        out_stream << iterator->value << spacing;
        iterator = iterator->next;
    }

    out_stream << std::endl;
}

