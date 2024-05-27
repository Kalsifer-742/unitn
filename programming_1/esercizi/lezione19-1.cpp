#include <iostream>
#include <fstream>
using namespace std;

struct node{
    int value;
    node* next;
};

int main(){
    fstream input;
    input.open("file.txt", ios::in);

    node* list = new node;
    
    node* current_node = list;
    while(!input.eof()){
        node* tmp = new node;
        input >> tmp->value; // (*tmp).value
        current_node->next = tmp;
        current_node = tmp;
    }

    input.close();

    current_node = list;
    do{
        cout << current_node->value << " ";
        current_node = current_node->next;
    }
    while (current_node->next != NULL);
    cout << endl;

    return 0;
}