#ifndef UTILS_TREE_HPP
#define UTILS_TREE_HPP

#include <ostream>

typedef long tree_val_t;

struct tree_node {
    tree_val_t val;

    tree_node* l;
    tree_node* r;
};

typedef tree_node* tree;

tree tree_init();
void deinit(tree& t);
void insert_at(tree& tree, tree_val_t val);
void insert_ordered(tree& tree, tree_val_t val);
tree_node* search(tree t, tree_val_t val);
void print(std::ostream& out_stream, tree t, const char* separator = " ");
void print(tree t, const char* separator = " ");
tree make_balanced_tree_from_ordered_array(tree_val_t* arr, long size);
tree_val_t maxmin_value(tree t, bool max_if_true);
#endif
