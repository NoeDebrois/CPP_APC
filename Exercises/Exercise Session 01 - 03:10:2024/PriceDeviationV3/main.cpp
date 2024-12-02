// Price deviation evaluation v3
// Version with a function "evaluate_deviations"

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


void evaluate_deviations (unsigned num, double sum, const double prices[], const std::string& zone);


int main (void)
{
    const unsigned MAXDIM = 100;
    const char CENTER = 'c';
    const char SUBURB = 's';

    double pricesC[MAXDIM];
    double pricesS[MAXDIM];
    unsigned numC = 0;
    unsigned numS = 0;
    double sumC = 0.;
    double sumS = 0.;
    bool exit = false;

    while (! exit)
    {
        double price;
        char zone;
        cout  << "Input price: ";
        cin >> price;
        cout  << "Input zone: ";
        cin >> zone;

        if (! cin || (zone != CENTER && zone != SUBURB))
            exit = true;
        else
        {
            if (zone == CENTER)
            {
                pricesC[numC++] = price;
                sumC += price;

                if (numC >= MAXDIM)
                    exit = true;
            }
            else
            {
                pricesS[numS++] = price;
                sumS += price;

                if (numS >= MAXDIM)
                    exit = true;
            }
        }
    }

    cout << "Exit input loop" << endl;
    cout << "sumC = " << sumC << "; numC = " << numC << endl;
    cout << "sumS = " << sumS << "; numS = " << numS << endl;

    evaluate_deviations (numC, sumC, pricesC, "center");
    evaluate_deviations (numS, sumS, pricesS, "suburb");

    return 0;
}


void evaluate_deviations (unsigned num, double sum, const double prices[], const std::string& zone)
{
    if (num != 0)
    {
        double mean = sum / num;
        cout << "mean " << zone << " = " << mean << endl;

        cout << endl << setw(20) << "Prices (" << zone << ")"
                     << setw(40) << "Deviation from the mean (" << zone << ")" << endl;

        for (unsigned i = 0; i < num; ++i)
        {
            double deviation = prices[i] - mean;
            cout << setw(20) << prices[i] << setw(20) << deviation << endl;
        }
    }
}
