#include <iostream>
#include <cstdlib>
#include <cassert>

struct node {
		char info;
		node * next;
};

void dealloca(node *& s) {
		while(s != NULL) {
				node * t = s;
				s = s->next;
				delete t;
		}
}

void stampa_lista(const char * testo, node * s) {
		std::cout << testo;
		for( ; s!= NULL; s=s->next) {
				std::cout << " " << s->info;
		}
		std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* str, node*& a, node*& b);
// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
		if (argc != 2) {
				std::cout << "Usage: " << argv[0]
														<< " \"stringa di caratteri\"" << std::endl;
				exit(1);
		}
		node * s1, * s2;
		std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

		compute_lists(argv[1], s1, s2);

		stampa_lista("Lista s1:", s1);
		stampa_lista("Lista s2:", s2);
		dealloca(s1);
		dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* str, node*& list_a, node*& list_b) {
    //inizializzo le liste (utile al primo livello di ricorsione non essendo inizializzate dal main)
    list_a = list_b = NULL;

    char c = *str;
    
    if(c >= 'A' && c <= 'M') {
        c = 'm' - (c - 'A');
        list_a = new node{ c , NULL };
        compute_lists(str+1, list_a->next, list_b);
    }
    else if(c >= 'N' && c <= 'Z') {
        c = 'z' - (c - 'N');
        list_b = new node{ c , NULL };
        compute_lists(str+1, list_a, list_b->next);
    }
    else if(c)
        compute_lists(str+1, list_a, list_b);
}
// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
