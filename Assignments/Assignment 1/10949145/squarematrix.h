#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <vector>
#include <iostream>
#include <utility>

namespace linear_algebra
{
    class square_matrix
    {
    private:
        std::vector<double> elem;
        std::size_t sz;

        std::size_t sub2ind(const std::size_t& i, const std::size_t& j) const;
    public:
        square_matrix() = default;
        square_matrix(const std::size_t& s): elem(s*s),  sz(s) {};
        square_matrix(const std::string& filename); //builds a matrix reading data from a text file
        std::size_t size() const { return sz; }

        const double& operator() (const std::size_t& i, const std::size_t& j) const;
        double& operator()(const std::size_t& i, const std::size_t& j);

        std::vector<double> operator*(const std::vector<double>& x) const;
    };
}


#endif
