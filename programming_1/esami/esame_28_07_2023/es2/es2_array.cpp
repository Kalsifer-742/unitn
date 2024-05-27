#include <iostream>
#include <iomanip>
using namespace std;

void print_array(double array[], int len, int index)
{
    if (array[index] == -1)
    {
        cout << endl;
    }
    else
    {
        cout << array[index] << " ";
        print_array(array, len, index + 1);
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
void sinh(double nmax, double epsilon, double x, double prev_step, int depth, double*& array)
{    
    double exponent = 2.0 * depth + 1.0;
    double numerator = pow(x, exponent);
    double denominator = fact(2.0 * depth + 1.0);
    double curr_step =  numerator / denominator;
    
    //DEBUG
    cout << "exp:" << exponent << " num:" << numerator << " den:" << denominator << " prev_step:" << prev_step << " curr_step:" << curr_step << " depth:" << depth << endl;
    
    if(depth > nmax || absolute(curr_step - prev_step) < (epsilon * absolute(prev_step)))
    {
        array = new double[depth + 1];
        cout << "allocato array grandezza:" << depth + 1 << endl;
        array[depth + 1] = -1.0;
        array[depth] = prev_step;
    }
    else
    {
        sinh(nmax, epsilon, x, curr_step, depth + 1, array);
        cout << "depth:" << depth << endl;
        array[depth] = curr_step;
    }
}

int main(int argc, char* argv[])
{
    int nmax = 0;
    double epsilon = 0;
    double x = 0;
    double* array = nullptr;
    int len = 0;

    cout << "inserire nmax: ";
    cin >> nmax;
    cout << "inserire epsilon: ";
    cin >> epsilon;
    
    char choice = 'S';
    while (choice != 'n' && choice != 'N')
    {
        cout << "inserire x: ";
        cin >> x;
        
        sinh(nmax, epsilon, x, 0.0, 0, array);
        cout << "coefficienti: "; print_array(array, len, 0);

        cout << "continuare? (S/n) ";
        cin >> choice;
    }

    delete[] array;
    
    return 0;
}