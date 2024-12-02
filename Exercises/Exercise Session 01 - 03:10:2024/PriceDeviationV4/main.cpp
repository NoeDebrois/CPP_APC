// Price deviation evaluation v4
// Function with two functions : one to get prices, the other to compute deviations.

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

const unsigned NZONES = 4;
const unsigned MAXDIM = 5;


void get_prices (unsigned nums[], double sums[], double prices[][MAXDIM]);
void evaluate_deviations (const unsigned nums[], const double sums[], const double prices[][MAXDIM]);


int main (void)
{
    double prices[NZONES][MAXDIM];
    unsigned nums[NZONES] = {};
    double sums[NZONES] = {};

    get_prices(nums, sums, prices);
    evaluate_deviations(nums, sums, prices);

    return 0;
}


void get_prices (unsigned nums[], double sums[], double prices[][MAXDIM])
{
    bool stop = false;

    while (! stop)
    {
        double price;
        unsigned zone;
        cout  << "Input price: ";
        cin >> price;
        cout  << "Input zone: ";
        cin >> zone;

        if (! cin || zone >= NZONES)
            stop = true;
        else
        {
            prices[zone][nums[zone]++] = price;
            sums[zone] += price;

            if (nums[zone] >= MAXDIM)
                stop = true;
        }
    }

    cout << "Exit input loop" << endl;
}


void evaluate_deviations (const unsigned nums[], const double sums[], const double prices[][MAXDIM])
{
    for (unsigned z = 0; z < NZONES; ++z)
    {
        if (nums[z] != 0)
        {
            double mean = sums[z] / nums[z];
            cout << "mean in zone " << z << " = " << mean << endl;

            cout << endl << setw(20) << "Prices (" << z << ")"
                 << setw(40) << "Deviation from the mean (" << z << ")" << endl;

            for (unsigned i = 0; i < nums[z]; ++i)
            {
                double deviation = prices[z][i] - mean;
                cout << setw(20) << prices[z][i] << setw(20) << deviation << endl;
            }
        }
    }
}
