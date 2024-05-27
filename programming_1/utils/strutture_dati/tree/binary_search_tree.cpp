#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* parent;
    node* left;
    node* right;
};

void insert_node(int value, node*& root);
void initialize_tree(node*& root);
void delete_node(int value, node* root);
void set_parent_null(node* root);
void transplant_node(node*& root);
bool is_parent_left(node* root);
void delete_tree(node*& root);
node* search_node(int value, node* root);
void print_tree(node* root, int c = 0, bool is_left = false);
void dfs_pre_order(node* root);
void dfs_post_order(node* root);
void dfs_in_order(node* root);
int get_minimum_value(node* root);
int get_maximum_value(node* root);

void insert_node(int value, node*& root)
{
    if(root == NULL)
    {
        root = new node{value, NULL, NULL, NULL};
    }
    else if(value <= root->value)
    {
        if(root->left == NULL)
        {
            root->left = new node{value, root, NULL, NULL};
        }
        else
        {
            insert_node(value, root->left);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = new node{value, root, NULL, NULL};
        }
        else
        {
            insert_node(value, root->right);
        }
    }
}

void initialize_tree(node*& root)
{
    insert_node(5, root);
    insert_node(3, root);
    insert_node(2, root);
    insert_node(4, root);
    insert_node(7, root);
    insert_node(6, root);
    insert_node(8, root);
}

void delete_node(int value, node* root)
{
    node* current_node = search_node(value, root);
    if(current_node->left == NULL && current_node->right == NULL)
    {
        set_parent_null(current_node);
        delete current_node;
    }
    else if(current_node->left == NULL)
    {
        transplant_node(current_node);
    }
    else if(current_node->right == NULL)
    {
        transplant_node(current_node);
    }
    else
    {
        //in order successor in un albero binario è sempre sul ramo di destra
        node* successor_node = current_node->right;

        //cerco il minimo valore a destra del nodo da eliminare
        while (successor_node->left != NULL)
        {
            successor_node = successor_node->left;
        }

        //il successore sarà sempre il figlio sinistro di un nodo e sarà alla maggiore profondità possibile, l'unica caso in cui non è una foglia è quando ha un figlio destro che va quindi sostituito a lui 
        if(successor_node->right != NULL)
        {
            transplant_node(successor_node);
        }
        else
        {
            //in caso sia una foglia procedo ad eliminare il nodo come una foglia qualsiasi
            set_parent_null(successor_node);
        }

        //sovrascrivo il valore del nodo eliminato con quello del successivo
        current_node->value = successor_node->value;

        delete successor_node;
    }
}

void transplant_node(node*& root)
{
    if(is_parent_left(root))
    {
        root->parent->left = root->right;
        root->right->parent = root->parent; 
        delete root;
    }
    else
    {
        root->parent->right = root->left;
        root->left->parent = root->parent; 
        delete root;
    }
}

void set_parent_null(node* root)
{
    if(is_parent_left(root))
    {
        root->parent->left = NULL;
    }
    else
    {
        root->parent->right = NULL;
    }
}

bool is_parent_left(node* root)
{
    return (root == root->parent->left);
}

void delete_tree(node*& root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = NULL;
    }
}

node* search_node(int value, node* root)
{
    if(root != NULL)
    {
        if(value == root->value)
        {
            return root;
        }
        else if(value < root->value)
        {
            return search_node(value, root->left);
        }
        else
        {
            return search_node(value, root->right);
        }
    }
    return NULL;
}

void print_tree(node* root, int c, bool is_left)
{
    if(root != NULL)
    {
        c++;
        
        print_tree(root->right, c, false);

        for (int i = 0; i < (c - 1); i++)
        {
            cout << "\t";
            //cout << "────";
        }
        cout << root->value << endl;
        
        print_tree(root->left, c, true);
    }
}

void dfs_pre_order(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->value << " ";
        dfs_pre_order(root->left);
        dfs_pre_order(root->right);
    }
    
}

void dfs_post_order(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        dfs_pre_order(root->left);
        dfs_pre_order(root->right);
        cout << root->value << " ";
    }
    
}

void dfs_in_order(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        dfs_pre_order(root->left);
        cout << root->value << " ";
        dfs_pre_order(root->right);
    }
    
}

int get_minimum_value(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->value;
}

int get_maximum_value(node* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->value;
    
}