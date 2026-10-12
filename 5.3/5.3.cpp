#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double h(const double x);

int main()
{
    double qp, qk;
    int n;


    cout << "qp = "; cin >> qp;
    cout << "qk  = "; cin >> qk;
    cout << "n      = "; cin >> n;

  
    double dq = (qk - qp) / n;


    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "|" << setw(12) << "q" << "   |"
        << setw(14) << "Result" << "   |" << endl;
    cout << "---------------------------------" << endl;

    cout << fixed;
    double q = qp;

   
    for (int i = 0; i <= n; i++)
    {
        double h1 = h(q + 1.0);
        double h2 = h(q * q + 1.0);
        double h3 = h(q * q);

        double result = h1 + h2 + h3 * h3;

     
        cout << "|" << setw(12) << setprecision(4) << q << "   |"
            << setw(14) << setprecision(6) << result << "   |" << endl;

        q += dq;
    }

    cout << "---------------------------------" << endl;

    return 0;
}


double h(const double x)
{
    if (abs(x) >= 1)
    {

        return (cos(x) + 1) / (pow(cos(x), 2) + 1);
    }
    else
    {
        
        double sum = 0;
        double a = 1; 

        for (int i = 0; i <= 6; i++)
        {
            if (i > 0)
            {
                
                a *= (x * x) / ((2 * i - 1) * (2 * i));
            }
            sum += a;
        }

        return (1 / cos(x)) * sum;
    }
}