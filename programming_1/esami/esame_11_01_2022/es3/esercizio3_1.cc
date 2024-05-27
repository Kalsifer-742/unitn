#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


void stampaAlbero(albero radice, int spazio=0);

struct file_or_failure {
    ifstream f;
    bool is_valid;
};

file_or_failure get_file(int argc, char** argv);
void quicksort(int arr[], int arr_size);
void populate_tree(nodo*& n, int* arr, int size);
void delete_tree(nodo*& n);

int main(int argc, char** argv) {
    file_or_failure f = get_file(argc, argv);
    if(!f.is_valid)
        return -1;

    int contents[100];
    int size = 0;

    while(f.f && size < 100) {
        f.f >> contents[size];
        if(f.f) size++;
    }

    quicksort(contents, size);

    albero tree;
    populate_tree(tree, contents, size);

    stampaAlbero(tree);

    delete_tree(tree);

    return 0;
}

file_or_failure get_file(int argc, char** argv) {
    file_or_failure ret;

    if(argc < 2) {
        cerr << "l'argomento del programma dev'essere il file di input" << endl;
        ret.is_valid = false;
        return ret;
    }

    ret.f.open(argv[1]);

    if(ret.f.fail()) {
        cerr << "Il file di input non esiste" << endl;
        ret.is_valid = false;
        return ret;
    }
    
    ret.is_valid = true;

    return ret;
}

static void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

static int partition(int arr[], int first, int last) {
    //scelgo l'ultimo elemento come pivot
    int pivot = arr[last];
    int i = first;

    for (int j = first; j < last; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;  // increment index of smaller element
        }
    }
    swap(arr[i], arr[last]);
    
    return i;
}

static void quicksort_recursive(int arr[], int first, int last) {
    if(first < last) {
        int split = partition(arr, first, last);
        quicksort_recursive(arr, first, split-1);
        quicksort_recursive(arr, split+1, last);
    }
}
void quicksort(int arr[], int arr_size) {
    quicksort_recursive(arr, 0, arr_size-1);
}

void populate_tree(nodo*& n, int* arr, int size) {
    if(size <= 0)
        return;
    int pivot_index = size/2;
    n = new nodo{ arr[pivot_index], NULL, NULL };
    populate_tree(n->left, arr, pivot_index);
    populate_tree(n->right, arr + pivot_index + 1, size - (pivot_index + 1));
}

/** Stampa dell'albero */
void stampaAlbero(albero radice, int spazio){
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

void delete_tree(nodo*& subtree) {
    if(subtree != NULL) {
        delete_tree(subtree->left);
        delete_tree(subtree->right);
    }
    delete subtree;
}
