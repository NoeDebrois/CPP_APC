#ifndef BLOCK_H_
#define BLOCK_H_

#include <vector>

#include "dense_matrix.hpp"

class Block
{
    private:
        unsigned top_left_row; // That's how it stores the indices of the block.
        unsigned top_left_col;
        unsigned bottom_right_row;
        unsigned bottom_right_col;

        DenseMatrix dm; // A block stores its data in a dense matrix.

    public:
        // When we call the constructor : we pass all the indices of the block + the data is a vector.
        Block (std::size_t top_left_r, std::size_t top_left_c,
               std::size_t bottom_right_r, std::size_t bottom_right_c,
               const std::vector<double> & vals);

        // The getters :
        unsigned get_bottom_right_col() const;
        unsigned get_bottom_right_row() const;

        unsigned get_top_left_col() const;
        unsigned get_top_left_row() const;

        // Call '()' operator :
        // These two methods are not overriding the methods of the base class since this class is not a child class from
        // matrix class.
        double & operator () (std::size_t i, std::size_t j);
        double operator () (std::size_t i, std::size_t j) const;
};

#endif /* BLOCK_H_ */
