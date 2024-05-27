#include <cmath>

void quadratic_equation(double& a, double& b, double c){
    double delta;

    if (a == 0)
    {
        a = -1;
        b = -1;

        /*
            0 == 0
            if ((b == 0) && (c == 0))
            {
                infinite soluzioni
            }
            retta parallela asse x
            if ((b == 0) && (c != 0))
            {
                nessuna soluzione
            }
            retta
            if (b != 0)
            {
                unica soluzione: -c/b
            }
        */
    }
    else
    {
        delta = (b * b) - 4.0 * (a * c);
        if(delta < 0)
        {
            a = -1;
            b = -1;

            /*
                cout << "x1: " << -b/(2.0*a) << " + " << sqrt(-delta) / (2.0 * a) << "i" << endl;
                cout << "x2: " << -b/(2.0*a) << " - " << sqrt(-delta) / (2.0 * a) << "i" << endl;
            */
        }
        else
        {
            a = (-b + sqrt(delta)) / (2 * a);
            b = (-b - sqrt(delta)) / (2 * a);
        }
    }
}