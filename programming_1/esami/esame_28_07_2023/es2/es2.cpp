
#include <iostream>
#include <iomanip>
using namespace std;

struct node_t
{
    double value;
    node_t* next;
};

void insert_to_tail(double val, node_t*& node)
{
    if(node == nullptr)
    {
        node_t* tmp = new node_t{val, nullptr};
        node = tmp;
    }
    else
    {
        insert_to_tail(val, node->next);
    }
}

void print_list(node_t* node)
{
    if (node == nullptr)
    {
        cout << endl;
    }
    else
    {
        cout << node->value << " ";
        print_list(node->next);
    }
}

void delete_list(node_t*& node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        delete_list(node->next);
        delete node;
        node = nullptr;
    }   
}

double fact(double n)
{
    if (n == 0.0)
    {
        return 1.0;
    }
    else
    {
        return n * fact(n - 1.0);
    }
}

double pow(double base, double exponent)
{
    if (exponent == 0.0)
    {
        return 1.0;
    }
    else
    {
        return base * pow(base, exponent - 1.0);
    }
}

double absolute(double n) {
    if (n < 0)
    {
        return -n;
    }
    else
    {
        return n;
    }   
}

//depth == i
double sinh(double nmax, double epsilon, double x, double prev_step, int depth)
{    
    double exponent = 2.0 * depth + 1.0;
    double numerator = pow(x, exponent);
    double denominator = fact(2.0 * depth + 1.0);
    double curr_step = numerator / denominator;
    
    //DEBUG
    //cout << "exp:" << exponent << " num:" << numerator << " den:" << denominator << " prev_step:" << prev_step << " curr_step:" << curr_step << " depth:" << depth << endl;
    
    
    if(depth > nmax)
    {
        return prev_step;
    }
    else if (absolute(curr_step - prev_step) < (epsilon * absolute(prev_step)))
    {
        return prev_step;
    }
    else
    {
        return curr_step + sinh(nmax, epsilon, x, curr_step, depth + 1);
    }
}

void sinh(double nmax, double epsilon, double x, double prev_step, int depth, node_t*& list)
{      
    double exponent = 2.0 * depth + 1.0;
    double numerator = pow(x, exponent);
    double denominator = fact(2.0 * depth + 1.0);
    double curr_step =  numerator / denominator;
    
    //DEBUG
    //cout << "exp:" << exponent << " num:" << numerator << " den:" << denominator << " curr_step:" << curr_step << endl;
    
    if(depth > nmax)
    {
        insert_to_tail(prev_step, list);
    }
    else if (absolute(curr_step - prev_step) < (epsilon * absolute(prev_step)))
    {
        insert_to_tail(prev_step, list);
    }
    else
    {
        insert_to_tail(curr_step, list);
        
        //DEBUG
        //cout << "list: "; print_list(list);
        
        sinh(nmax, epsilon, x, curr_step, depth + 1, list);
    }   
}

int main(int argc, char* argv[])
{
    int nmax = 0;
    double epsilon = 0;
    double x = 0;
    node_t* list = nullptr;

    cout << "inserire nmax: ";
    cin >> nmax;
    cout << "inserire epsilon: ";
    cin >> epsilon;
    
    char choice = 'S';
    while (choice != 'n' && choice != 'N')
    {
        cout << "inserire x: ";
        cin >> x;

        //cout << "risultato: " << setprecision(10) << sinh(nmax, epsilon, x, 0.0, 0) << endl;
        
        sinh(nmax, epsilon, x, 0.0, 0, list);
        cout << "coefficienti: "; print_list(list);

        cout << "continuare? (S/n) ";
        cin >> choice;
    }

    delete_list(list);
    
    return 0;
}