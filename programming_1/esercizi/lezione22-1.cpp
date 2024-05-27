#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};

nodo* crea_albero();
void inserisci_nodo(nodo** root, nodo* node);
// si invoca "stampaAlbero(radice);"
void stampaAlbero(nodo* radice, int spazio=0);
void stampa_valori(nodo* root);
void cerca_valore(nodo* root, int value);
void cancella_albero(nodo* root);

int main(){
    nodo* root = crea_albero();

    //stampa_valori(root);
    //stampaAlbero(root);
    cerca_valore(root, 6);
    cancella_albero(root);
}

nodo* crea_albero(){
    fstream input;
    input.open("file.txt", ios::in);

    int buffer;
    nodo* root = NULL;

    while (input >> buffer)
    {
        nodo* tmp = new nodo{buffer, NULL, NULL};
        inserisci_nodo(&root, tmp);
    }

    input.close();

    return root;
}

void inserisci_nodo(nodo** root, nodo* node){
    if(*root == NULL){
        *root = node;
    }else if(node->value <= (*root)->value){
        inserisci_nodo(&((*root)->left), node);
    }else{
        inserisci_nodo(&(*root)->right, node);
    }
}

void stampaAlbero(nodo* radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}

void stampa_valori(nodo* root){
    if(root != NULL){
        stampa_valori(root->left);
        cout << root->value << " ";
        stampa_valori(root->right);
    }
}

//rotta
void cerca_valore(nodo* root, int value){
    int i = 0, j = 0;
    nodo** r = &root;
    while(*r != NULL && (*r)->value != value){
        if((*r)->value > value){
            r = &(*r)->left;
            i++;
        }else{
            r = &(*r)->right;
            j++;
        }
    }
    cout << i << " sinistra " << j << " destra";
}

void cancella_albero(nodo* root){
    if(root != NULL){
        cancella_albero(root->left);
        cancella_albero(root->right);
        delete root;
    } 
}