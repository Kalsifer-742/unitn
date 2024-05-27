#include "tree.hpp"

#include <iostream>
#include <cstring>

//dichiarazione esplicita della funzione di confronto; se non è tra i tipi sotto serve definirla
extern int compare(tree_val_t&, tree_val_t&);

//definizioni standard della definizione di confronto
int compare(long& a, long& b) {
    return a < b ? -1 : a == b ? 0 : 1;
}
bool compare(char*& a, char*& b) {
    return std::strcmp(a, b);
}

tree tree_init() {
    return NULL;
}

void deinit(tree& t) {
    if(t) {
        deinit(t->l);
        deinit(t->r);
    }
    delete t;
    t = NULL;
}

void insert_at(tree& p, tree_val_t val) {
    p = new tree_node{ val, NULL, NULL };
}

void insert_ordered(tree& tree, tree_val_t val) {
    if(tree == NULL)
        insert_at(tree, val);
    else {
        if(compare(val, tree->val) < 0) // val < tree->val
            insert_ordered(tree->l, val);
        else
            insert_ordered(tree->r, val);
    }
}

tree_node* search(tree t, tree_val_t val) {
    if(t == NULL)
        return NULL;
    int order = compare(val, t->val);
    if(order == 0) //val == t->val
        return t;
    if(order < 0) //val < t->val
        return search(t->l, val);
    else //val > t->val
        return search(t->r, val);
}



void print(std::ostream& out_stream, tree t, const char* separator) {
    if(t == NULL)
        return;

    print(out_stream, t->l, separator);
    out_stream << t->val << " ";
    print(out_stream, t->r, separator);
}

void print(tree t, const char* separator) {
    print(std::cout, t, separator);
}

static void make_balanced_branch(tree_node*& n, tree_val_t* arr, long size) {
    if(size <= 0)
        return;
    long pivot_index = size/2;

    n = new tree_node{ arr[pivot_index], NULL, NULL };
    make_balanced_branch(n->l, arr, pivot_index);
    make_balanced_branch(n->r, arr + pivot_index + 1, size - (pivot_index + 1));
}

tree make_balanced_tree_from_ordered_array(tree_val_t* arr, long size) {
    tree t = tree_init();
    make_balanced_branch(t, arr, size);
    return t;
}

//assume che l'albero sia un BST di tree_val_t; ritorna -1 se l'albero e' vuoto, il massimo dell'albero se max_if_true==true o il minimo se max_if_true=false
tree_val_t maxmin_value(tree t, bool max_if_true) {
    if(t == NULL)
        return -1;

    if(max_if_true) {
        while(t->r)
            t = t->r;

        return t->val;
    }
    else {
        while(t->l)
            t = t->l;

        return t->val;
    }
}
