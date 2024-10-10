#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <set>
#include <list>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include "got2.h"
using namespace std;

#pragma region "debugging and printing"
    #ifdef EVAL
        #define DBG(x)
    #else
        #define DBG(x) x
    void print() { cout << endl; }
    template<typename T, typename...Ts> void print(T arg, Ts... args) {
        cout << arg << " ";
        print(args...);
    }
    #endif
    #define PRINT(...) DBG(print(__VA_ARGS__))
    #define PRINT_VAR(x) PRINT(#x, "=", x)
#pragma endregion

struct node_t {
    vector<node_t*> neighbours;
    int clique = -1;

    bool is_neighbour(const node_t* n) const {
        for(const node_t* neighbour : neighbours) {
            if (neighbour == n)
                return true;
        }

        return false;
    }

    bool is_neighbour(const set<node_t*>& s) const {
        for (const node_t* n : s) {
            if (!is_neighbour(n))
                return false;
        }
        return true;
    }

    int number_of_neighbors_in_set(const set<node_t*>& s) const {
        int neighbors_in_clique = 0;
        for (const node_t* n : s) {
            if (is_neighbour(n))
                neighbors_in_clique++;
        }
        return neighbors_in_clique;
    }
};

struct solution_t {
    struct arc_t {
        int a, b;
    };
    vector<arc_t> added, removed;

    int cost() const {
        return added.size() + removed.size();
    }
};

vector<node_t> input_data(istream& input) {
    int N, M;
    input >> N >> M;
    vector<node_t> nodes(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        input >> u >> v;
        nodes[u].neighbours.push_back(&nodes[v]);
        nodes[v].neighbours.push_back(&nodes[u]);
    }

    return nodes;
}

void output_solution(const solution_t& solution) {
    ofstream output("output.txt", std::ios::app);

    output << solution.added.size() << " " << solution.removed.size() << "\n";
    for(int i = 0; i < solution.added.size(); i++) {
        output << "+" << solution.added[i].a << " " << solution.added[i].b << "\n";
    }
    for(int i = 0; i < solution.removed.size(); i++) {
        output << "-" << solution.removed[i].a << " " << solution.removed[i].b << "\n";
    }

    output << "***" << endl;
}

DBG(void print_graph(const vector<node_t>& nodes) {
    auto ptr_to_index = [&](const node_t* p) -> int { return p - nodes.data(); };

    for(int i = 0; i < nodes.size(); i++) {
        const node_t& n = nodes[i];
        
        cout << "node " << i << " clique " << n.clique << "\tneighbours: ";
        for(const node_t* neighbour : n.neighbours) {
            cout << ptr_to_index(neighbour) << " ";
        }
        cout << endl;
    }
})

vector<solution_t::arc_t> find_and_extend_cliques(vector<node_t*>& nodes, const vector<node_t>& base_pointer) {
    auto ptr_to_index = [&](const node_t* p) -> int { return p - base_pointer.data(); };
    vector<solution_t::arc_t> added;
    vector<int> clique_closeness(nodes.size(), 0); //this vector will be zeroed every iteration; not declared inside the loop to optimize
    int last_clique = -1;

    for(int i = 0; i < nodes.size(); i++) {
        
        if(nodes[i]->clique != -1)
            continue;

        last_clique++;
        set<node_t*> clique;
        std::fill(clique_closeness.begin(), clique_closeness.end(), 0);
        nodes[i]->clique = last_clique;
        clique.insert(nodes[i]);
        
        for(int j = i+1; j < nodes.size(); j++) {
            if(nodes[j]->clique == -1) {
                if(nodes[j]->is_neighbour(clique)) {
                    nodes[j]->clique = last_clique;
                    clique.insert(nodes[j]);
                }
            }
        }
        
        
        for(node_t* n : clique) {
            for(node_t* clique_neighbor : n->neighbours) {
                clique_closeness[ptr_to_index(clique_neighbor)]++;
            }
        }

        bool changed;
        do {
            changed = false;
            for(int j = i+1; j < nodes.size(); j++) {
                if(nodes[j]->clique == -1) {
                    int numbers_of_neighbors_in_clique = clique_closeness[ptr_to_index(nodes[j])];
                    //if it costs more to remove the arcs that connect the node to the clique than to connect the missing ones just connect the node to the clique
                    if(numbers_of_neighbors_in_clique > clique.size()/2) { 
                        nodes[j]->clique = last_clique;

                        for(node_t* n : clique) {
                            if(!nodes[j]->is_neighbour(n)) {
                                added.push_back({ ptr_to_index(nodes[j]), ptr_to_index(n) });
                            }
                        }

                        clique.insert(nodes[j]);
                        for(node_t* clique_neighbor : nodes[j]->neighbours) {
                            clique_closeness[ptr_to_index(clique_neighbor)]++;
                        }
                        changed = true;
                    }
                }
            }
        } while(changed);
    }

    return added;
}

// si può tener traccia della dimensione delle cricche per risparmiare controlli su nodi senza collegamenti esterni
vector<solution_t::arc_t> prune_cliques(vector<node_t*>& nodes, const vector<node_t>& base_pointer) {
    vector<solution_t::arc_t> removed;
    auto ptr_to_index = [&](const node_t* p) -> int { return p - base_pointer.data(); };

    for(int i = 0; i < nodes.size(); i++) {
        for(node_t* neighbour : nodes[i]->neighbours) {
            if(ptr_to_index(nodes[i]) < ptr_to_index(neighbour) && neighbour->clique != nodes[i]->clique)
                removed.push_back({ ptr_to_index(nodes[i]), ptr_to_index(neighbour) });
        }
    }

    return removed;
}

vector<node_t*> shadow_wizard_money_gang(vector<node_t>& nodes) {
    vector<node_t*> souls(nodes.size());

    for(int i = 0; i < nodes.size(); i++)
        souls[i] = &nodes[i];
    
    return souls;
}

void casting_spells(vector<node_t*>& nodes){
    static uint64_t attempt_number = 0;
    attempt_number++;
    if(attempt_number == 1) {
        sort(nodes.begin(), nodes.end(), [](node_t* a, node_t* b) { return a->neighbours.size() > b->neighbours.size(); });
    } else if(attempt_number == 2) {
        //simply reverse it
        for(int i = 0; i < nodes.size() / 2; i++)
            swap(nodes[i], nodes[nodes.size() - 1 - i]);
    } else {
        for (int i = 0; i < nodes.size(); i++) {
            int random_value = rand() % nodes.size();
            swap(nodes[i], nodes[random_value]);
        }
    }
}

int main() {
    DBG({
        ofstream output("output.txt"); //wipe output.txt
    })
    ifstream input("input.txt");
    srand(0);

    vector<node_t> nodes = input_data(input);
    vector<node_t*> shadow_realm = shadow_wizard_money_gang(nodes);
    //DBG(print_graph(nodes));

    int last_solution = std::numeric_limits<int>::max();
    while (true) {
        solution_t solution;
        for(node_t& n : nodes)
            n.clique = -1;
        solution.added = find_and_extend_cliques(shadow_realm, nodes);
        solution.removed = prune_cliques(shadow_realm, nodes);

        PRINT_VAR(solution.cost());

        if (solution.cost() < last_solution) {
            output_solution(solution);
            last_solution = solution.cost();
        }

        casting_spells(shadow_realm); // shuffle 
    }

    return 0;
}
