#include "vectorhelpers.h"

namespace linear_algebra
{
    double norm(const std::vector<double>& x)
    {
        double n = 0;
        for (std::size_t i = 0; i < x.size(); i++) {
            n += x[i]*x[i];
        }
        return sqrt(n);
    }


    void normalize(std::vector<double>& x)
    {
        double nx = norm(x);
        for (std::size_t i = 0; i < x.size(); i++) {
            x[i] /= nx;
        }
        return;
    }


    double scalar(const std::vector<double>& x, const std::vector<double>& y)
    {
        double prod = 0;

        if (x.size() != y.size()) {
            std::cerr << "Error: vectors must have the same dimension!" << std::endl;
            return prod;
        }

        for (std::size_t i = 0; i < x.size(); i++) {
            prod += x[i]*y[i];
        }

        return prod;
    }


    std::vector<double> operator*(const double& a, const std::vector<double>& x)
    {
        std::vector<double> y(x);
        for (std::size_t i = 0; i < y.size(); i++) {
            y[i] *= a;
        }
        return y;
    }


    std::vector<double> operator-(const std::vector<double>& x1, const std::vector<double>& x2)
    {

        if (x1.size() != x2.size()) {
            std::cerr << "Error: vectors must have the same dimension!" << std::endl;
            return x1;
        }

        std::vector<double> y(x1);
        for (std::size_t i = 0; i < y.size(); i++) {
            y[i] -= x2[i];
        }
        return y;
    }
}

