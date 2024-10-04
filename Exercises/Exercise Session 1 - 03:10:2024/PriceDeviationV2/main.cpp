// Price deviation evaluation v2

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


int main (void)
{
    const unsigned MAXDIM = 10;
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

    if (numC != 0)
    {
        double mean = sumC / numC;
        cout << "mean center = " << mean << endl;

        cout << endl << setw(20) << "Prices (center)" << setw(40) << "Deviation from the mean (center)" << endl;

        for (unsigned i = 0; i < numC; ++i)
        {
            double deviation = pricesC[i] - mean;
            cout << setw(20) << pricesC[i] << setw(20) << deviation << endl;
        }
    }

    if (numS != 0)
    {
        double mean = sumS / numS;
        cout << "mean suburb = " << mean << endl;

        cout << endl << setw(20) << "Prices (suburb)" << setw(40) << "Deviation from the mean (suburb)" << endl;

        for (unsigned i = 0; i < numS; ++i)
        {
            double deviation = pricesS[i] - mean;
            cout << setw(20) << pricesS[i] << setw(20) << deviation << endl;
        }
    }

    return 0;
}
