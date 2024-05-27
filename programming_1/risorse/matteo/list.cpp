#include "list.hpp"
#include <iostream>

//nota: ogni variabile 'node**' e' un puntatore o a list.head o a node.next;
//questo torna comodo per poter inserire e eliminare nodi in qualsiasi posizione

/* init-deinit */
list list_init() {
    return { nullptr };
}

void deinit(list& l) {
    while(l.head != nullptr)
        remove_at(&l.head);
}


/* inserimento e rimozione di base */
void insert_at(node** n, list_value_t val) {
    node* new_node = new node{ val, *n };
    *n = new_node;
}

list_value_t remove_at(node** n) {
    //trova il nodo da eliminare
    node* to_be_deleted = *n;
    list_value_t v = to_be_deleted->val;
    //avanza il next-pointer sottostante per fargli 'saltare' il nodo da eliminare
    advance(*n);

    delete to_be_deleted;
    return v;
}


list& push_front(list& l, list_value_t val) {
    insert_at(&l.head, val);
    return l;
}

list& push_back(list& l, list_value_t val) {
    insert_at(last_link(l), val);
    return l;
}

//le funzioni di lettura assumono !is_empty
list_value_t pop_front(list& l) {
    return remove_at(&l.head);
}
list_value_t pop_back(list& l) {
    return remove_at(last_valid_link(l));
}

list_value_t front(list& l) {
    return l.head->val;
}
list_value_t back(list& l) {
    return (*last_valid_link(l))->val;
}

//ritorna l'indirizzo dell'ultimo puntatore next (o head) non nullo
node** last_valid_link(list& l) {
    node** iterator = &l.head;
    while((*iterator)->next != nullptr)
        advance(iterator);

    return iterator;
}

//ritorna l'indirizzo dell'ultimo puntatore next (o head), sicuramente nullo
node** last_link(list& l) {
    node** iterator = &l.head;
    while(*iterator != nullptr)
        advance(iterator);

    return iterator;
}

/* numero di elementi */
long get_length(list& l) {
    long len = 0;
    for(node* iterator = l.head; iterator != nullptr; advance(iterator))
        len++;
    return len;
}

bool is_empty(list& l) {
    return l.head == nullptr;
}


/* reverse */
static node* pop_front_node(list& l) {
    node* v = l.head;
    if(l.head != nullptr) 
        advance(l.head);
    return v;
}

static list& push_front_node(list& l, node* n) {
    n->next = l.head;
    l.head = n;
    return l;
}

list& reverse(list& l) {
    list new_list = list_init();
    
    node* n;
    do {
        n = pop_front_node(l);
        if(n != nullptr)
            push_front_node(new_list, n);
    } while(n != nullptr);

    l = new_list;
    return l;
}


/* find, delete */
long find_element(list& l, long val) {
    node* iterator = l.head;
    bool found = false;
    long index = 0;
    while(iterator != nullptr && !found) {
        if(iterator->val == val) {
            found = true;
        } else {
            advance(iterator);
            index++;
        }
    }
    
    return found ? index : -1;
}

list& delete_by_value(list& l, list_value_t val) {
    node** iterator = &l.head;
    bool found = false;
    while(*iterator != nullptr && !found) {
        if((*iterator)->val == val) {
            found = true;
            node* to_be_deleted = (*iterator);
            advance(*iterator);
            delete to_be_deleted;
        } else {
            advance(iterator);
        }
    }

    return l;
}

//usa solo se la lista ha dimensione >index
list& delete_by_index(list& l, long index) {
    node** iterator = &l.head;
    for(int i = 0; i < index; i++)
        advance(iterator);
    node* to_be_deleted = *iterator;
    advance(*iterator);
    delete to_be_deleted;

    return l;
}

/* insert ordered, sort */
static void insert_ordered_node(list& l, node* n) {
    //itero i nodi cercando il primo >= val
    node** iterator = &l.head;
    bool inserted = false;

    while(!inserted) {
        if(*iterator != nullptr) {
            //se il nodo successivo e' maggiore di val, inserisci il nodo
            if(n->val <= (*iterator)->val) {
                n->next = *iterator;
                *iterator = n;
                inserted = true;
            } 
            //altrimenti continua a iterare
            else {
                advance(iterator);
            }
        } 
        //se raggiungi la fine della lista, inserisci il nodo li'
        else {
            n->next = nullptr;
            *iterator = n;
            inserted = true;
        } 
    }
}

void insert_ordered(list& l, list_value_t val) {
    insert_ordered_node(l, new node{ val, nullptr });
}

list& sort(list& l) {
    list new_list = list_init();

    while(l.head != nullptr) {
        node* n = pop_front_node(l);
        insert_ordered_node(new_list, n);
    }

    l = new_list;
    return l;
}

/* print */

void print(std::ostream& out_stream, list& list, const char* spacing) {
    //itero sui nodi stampando i valori
    node* iterator = list.head;    
    while(iterator != nullptr) {
        out_stream << iterator->val << spacing;
        iterator = iterator->next;
    }

    out_stream << std::endl;
}

void print(list& list, const char* spacing) {
    print(std::cout, list, spacing);
}

static void print_reverse_recursive(std::ostream& out_stream, node* iterator, const char* spacing) {
    if(iterator == nullptr)
        return;

    print_reverse_recursive(out_stream, iterator->next, spacing);
    out_stream << iterator->val << spacing;
}

void print_reverse(std::ostream& out_stream, list& l, const char* spacing) {
   print_reverse_recursive(out_stream, l.head, spacing);
    out_stream << std::endl;
}

void print_reverse(list& l, const char* spacing) {
    print_reverse(std::cout, l, spacing);
}

/* advance iterator*/

void advance(node*& iterator) {
    iterator = iterator->next;
}
//advance iterator able to modify the pointer it refers to
void advance(node**& iterator) {
    iterator = &(**iterator).next;
}
