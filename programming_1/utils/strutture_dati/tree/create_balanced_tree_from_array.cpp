#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
};

node* create_balanced_tree_from_array(int array[], int start, int end);
void delete_tree(node*& root);

//alla prima chiamata end deve essere DIM-1
node* create_balanced_tree_from_array(int array[], int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    
    int middle = (start + end) / 2;
    node* root = new node{array[middle], NULL, NULL};
    root->left = create_balanced_tree_from_array(array, start, middle - 1);
    root->right = create_balanced_tree_from_array(array, middle + 1, end);

    return root;
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