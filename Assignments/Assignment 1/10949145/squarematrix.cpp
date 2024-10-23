#include "squarematrix.h"

#include <iostream>
#include <fstream>
#include <cstring>

namespace linear_algebra
{

    square_matrix::square_matrix(const std::string& filename)
    {

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file '" << filename << "' - " << std::strerror(errno) << std::endl;
            return;
        }

        file >> sz;
        double value;
        while (file >> value) {
            elem.push_back(value);
        }

        file.close();
    }


    std::size_t square_matrix::sub2ind(const std::size_t& i, const std::size_t& j) const
    {
        return i*sz + j;
    }


    const double& square_matrix::operator()(const std::size_t& i, const std::size_t& j) const
    {
        return elem[sub2ind(i,j)];
    }


    double& square_matrix::operator()(const std::size_t& i, const std::size_t& j)
    {
        return elem[sub2ind(i,j)];
    }


    std::vector<double> square_matrix::operator*(const std::vector<double>& x) const
    {
        std::vector<double> v(x.size());
        if (v.size() != sz) {
            std::cerr << "Error: dimensions don't agree!" << std::endl;
            return v;
        }

        for (std::size_t i = 0; i < v.size(); i++) {
            double d = 0;
            for (std::size_t j = 0; j < v.size(); j++) {
                d += elem[sub2ind(i,j)]*x[j];
            }
            v[i] = d;
        }

        return v;
    }
}
