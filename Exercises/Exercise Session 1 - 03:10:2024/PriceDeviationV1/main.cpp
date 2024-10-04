// Price deviation evaluation v1

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


int main (void)
{
    const unsigned MAXDIM = 10;

    double prices[MAXDIM];
    unsigned num = 0;
    double sum = 0.;
    bool exit = false;

    while (! exit)
    {
        double price;
        cout  << "Input price: ";
        cin >> price;

        if (! cin || num >= MAXDIM)
            exit = true;
        else
        {
            prices[num++] = price; // We add at idx num AND then we increment so that we can check
            // whether of not we reached the maximum dimension.
            sum += price;

            if (num >= MAXDIM) // If we reached the maximum dimension, exit.
                exit = true;
        }
    }

    cout << "Exit input loop" << endl;
    cout << "sum = " << sum << "; num = " << num << endl;

    if (num != 0)
    {
        double mean = sum / num;
        cout << "mean = " << mean << endl;

        cout << endl << setw(20) << "Prices" << setw(40) << "Deviation from the mean" << endl;

        for (unsigned i = 0; i < num; ++i)
        {
            double deviation = prices[i] - mean;
            cout << setw(20) << prices[i] << setw(20) << deviation << endl;
        }
    }

    return 0;
}
