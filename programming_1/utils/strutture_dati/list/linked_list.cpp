#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node* next;
};

void insert_to_head(int val, node*& head);
void insert_to_tail(int val, node*& head);
void initialize_list(node*& head);
void delete_list(node*& head);
void print_list(node* head);
int list_length(node* head);
bool search_first_occurence_in_list(int val, node* head);
void bubble_sort_list(node*& head);

void insert_to_head(int val, node*& head)
{
    node* tmp = new node{val, NULL};
    if(head == NULL){
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
}

void insert_to_tail(int val, node*& head)
{
    node* tmp = new node{val, NULL};
    if(head == NULL){
        head = tmp;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = tmp;
    }
}

void initialize_list(node*& head)
{
    for (int i = 1; i < 11; i++)
    {
        insert_to_tail(i, head);
    }
}

void delete_list(node*& head){
    if(head == NULL)
    {
        return;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            node* tmp = current;
            current = current->next;
            delete tmp;
        }
        delete current;
        head = NULL;
    }
}

void print_list(node* head)
{
    node* current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int list_length(node* head)
{
    node* current = head;
    int c = 1;
    while (current->next != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}

bool search_first_occurence_in_list(int val, node* head)
{
    if(head == NULL){
        return false;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            if(val == current->value){
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void bubble_sort_list(node*& head)
{
    int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;

		node* current = head;
        while (current->next != NULL)
        {
            if(current->value > (current->next)->value)
            {
                tmp = current->value;
                current->value = (current->next)->value;
                (current->next)->value = tmp;
                swapped = true;
            }
            current = current->next;
        }
	}
}