#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <limits>

using namespace std;

constexpr int int_inf = numeric_limits<int>::max();

#ifdef EVAL
    #define DEBUG(x)
#else
    #define DEBUG(x) x
#endif

struct Arc {
    int dest;
    int weight;
    int min_weight;
    int max_weight;
};

struct Node
{
    list<Arc> adjacent_nodes;
};

struct Graph
{
    int montresus, student, fablab;
    vector<Node> nodes;
};

Graph construct_graph() {
    ifstream input;
    input.open("input.txt");

    //Un file con 2 + M + K righe.

    /*
    La prima riga riporta 3 numeri interi: N (int), M (int) e K (int),
    rispettivamente il numero di stanze, corridoi “semplici” e corridoi
    con ventole.
    */

    
    int nodes_number, simple_corridors, vent_corridors;
    input >> nodes_number >> simple_corridors >> vent_corridors;

    /*
    La seconda riga riporta 3 numeri interi: I (int), S (int) e F (int),
    rispettivamente il nodo di partenza dell’impostore, dello studente e
    il FabLab.
    */
    int montresus, student, fablab;
    input >> montresus >> student >> fablab;

    Graph graph { montresus, student, fablab, vector<Node>(nodes_number) };

    /*
    Le successive M righe riportano i corridoi semplici che collegano
    le stanze. Ogni riga riporta 3 interi U (int), V (int) e T (int),
    rappresentanti la stanza di partenza, la stanza di arrivo e il tempo
    di percorrenza del corridoio.
    */

    int arc_start, arc_end, arc_weight;
    for (int i = 0; i < simple_corridors; i++)
    {
        input >> arc_start >> arc_end >> arc_weight;

        graph.nodes[arc_start].adjacent_nodes.push_back(Arc{arc_end, arc_weight, -1, -1});
    }

    /*
    Le successive K righe riportano i corridoi con ventole, e sono co-
    stituite da 4 interi ciascuna: Uv (int), Vv (int), Tmin (int), Tmax
    (int), che rispettivamente sono la stanza di partenza, la stanza di
    arrivo, e i tempi di percorrenza minimo e massimo che è possibile
    ottenere regolando la potenza della ventola.   
    */

    int arc_min_weight, arc_max_weight;
    for (int i = 0; i < vent_corridors; i++)
    {
        input >> arc_start >> arc_end >> arc_min_weight >> arc_max_weight;

        graph.nodes[arc_start].adjacent_nodes.push_back(Arc{arc_end, arc_max_weight, arc_min_weight, arc_max_weight});
    }

    input.close();

    return graph;
}

void print_graph(const Graph& graph)
{
    for (int i = 0; i < graph.nodes.size(); i++)
    {
        cout << i << " -> ";
        for (const Arc& arc : graph.nodes[i].adjacent_nodes)
        {
            cout << arc.dest << "(" << arc.weight << ") ";
        }
        cout << endl;
    }
    cout << endl;    
}

struct node_priority_queue {
    list<int> nodes;
    const vector<int>& dist;
    node_priority_queue(const vector<int>& dist_vec) : nodes(), dist(dist_vec) {}
    int pop() {
        int ret = nodes.front();
        nodes.pop_front();
        return ret;
    }
    void push(int node) {
        nodes.push_back(node);
        nodes.sort(
            [&](int a, int b) { return dist[a] < dist[b]; }
        );
    }
    bool empty() { 
        return nodes.empty();
    }
    bool contains(int node) {
        for(int n : nodes)
            if(n == node)
                return true;
        return false;
    }
};

//https://it.wikipedia.org/wiki/Algoritmo_di_Dijkstra
//https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
struct path {
    vector<int> dist, prec;
};
path min_path_with_dijkstra(const Graph& graph, int source) {
    vector<int> dist(graph.nodes.size(), int_inf);
    vector<int> prec(graph.nodes.size(), -1);

    //auto pq_comp = [&dist](const pq_el& a, const pq_el& b) { return dist[a.node] > dist[b.node]; };
    //priority_queue<pq_el, vector<pq_el>, decltype(pq_comp)> pq(pq_comp);
    node_priority_queue pq(dist);
    dist[source] = 0;

    pq.push( source );

    for(; !pq.empty();) {
        int current = pq.pop();

        if (current == graph.fablab)
            break;
        
        for (const Arc& arc : graph.nodes[current].adjacent_nodes)
        {
            int len = dist[current] + arc.weight;
            if (len < dist[arc.dest])
            {
                dist[arc.dest] = len;
                prec[arc.dest] = current;
                
                if (!pq.contains(arc.dest))
                    pq.push(arc.dest);
            }
        }
    }

    return path{ move(dist), move(prec) };
}

void print_path(const vector<int>& path)
{
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

struct results {
    int winner; //1=montresus, 2=student, 0=draw
    int montresus_dist, student_dist;
    vector<int> vent_values;
    int montresus_n_of_rooms;
    vector<int> montresus_rooms;
};

results compute_results(path& montresus_path, path& student_path, int fablab)
{
    results res;
    
    /*
    La prima riga del file di output deve essere:
        - 1, se è possibile per l’impostore arrivare prima degli studenti al
        FabLab, regolando la potenza delle ventole in modo opportuno;
        - 2, se l’impostore arriva dopo gli studenti, in qualsiasi modo regoli la
        potenza delle ventole;
        - 0, se nel migliore dei casi l’impostore e gli studenti arrivano al
        FabLab nello stesso istante.
    */
    int diff = montresus_path.dist[fablab] - student_path.dist[fablab];
    res.winner = diff > 0 ? 2 
            : diff < 0 ? 1
            : 0;
    
    /*
    La seconda riga contiene due interi: le distanze minime con cui I
    ed S raggiungono il FabLab;
    */

    res.montresus_dist = montresus_path.dist[fablab];
    res.student_dist = student_path.dist[fablab];

    /*
    La terza riga contiene K interi: i tempi di percorrenza dei corridoi
    con ventole dopo l’opportuna regolazione della potenza (gli archi
    vanno stampati nello stesso ordine in cui compaiono nell’input).
    Se K = 0, lasciare una riga vuota;
    */
    
    //TODO: vent_values.push_back(...)

    //Opzionale

    /*
    La quarta riga contiene un intero R: il numero di stanze visitate
    dall’impostore per arrivare al FabLab (comprese I e F );
    
    La quinta riga contiene R interi: le stanze visitate, in ordine,
    dall’impostore (comprese I e F ).
    */
    
    int current = fablab;
    vector<int> rooms;
    while(current != -1)
    {
        rooms.push_back(current);
        current = montresus_path.prec[current];
    }
    res.montresus_n_of_rooms = rooms.size();
    res.montresus_rooms = rooms;

    return res;
}

void output_to_file(results res)
{
    ofstream output;
    output.open("output.txt");
    
    output << res.winner << '\n';
    
    output << res.montresus_dist << ' ' << res.student_dist << '\n';
    
    for(int vent : res.vent_values)
        output << vent << ' ';
    output << '\n';

    output << res.montresus_n_of_rooms;
    output << '\n';

    for (int i = res.montresus_rooms.size() - 1; i >= 0; i--)
        output << res.montresus_rooms[i] << ' ';
    
    output << flush;
    output.close();
}

int main()
{
    Graph graph = construct_graph();

    DEBUG( print_graph(graph); )

    path montresus_path = min_path_with_dijkstra(graph, graph.montresus);
    path student_path = min_path_with_dijkstra(graph, graph.student);
    
    //DEBUG
    
    DEBUG(
        cout << "montresus ";
        print_path(montresus_path.prec);
        cout << "student ";
        print_path(student_path.prec);
    )

    results res = compute_results(montresus_path, student_path, graph.fablab);

    output_to_file(res);

    return 0;
}