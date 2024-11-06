#include <vector>

#include <iostream>

#include "block.hpp"

Block::Block (std::size_t top_left_r, std::size_t top_left_c, std::size_t bottom_right_r,
              std::size_t bottom_right_c, const std::vector<double> & vals):
   top_left_row (top_left_r),
   top_left_col (top_left_c),
   bottom_right_row (bottom_right_r),
   bottom_right_col (bottom_right_c),
   dm (bottom_right_r - top_left_r + 1,
         bottom_right_c - top_left_c + 1, vals)
{}

   unsigned Block::get_bottom_right_col() const
{
   return bottom_right_col;
}

unsigned Block::get_bottom_right_row() const
{
   return bottom_right_row;
}

unsigned Block::get_top_left_col() const
{
   return top_left_col;
}

unsigned Block::get_top_left_row() const
{
   return top_left_row;
}

double & Block::operator()(std::size_t i, std::size_t j) // setter-like operator.
{
   return dm(i, j); // We access the element at idx (i, j) from the dense matrix.
}

double Block::operator() (std::size_t i, std::size_t j) const // getter-like operator.
{
   return dm(i, j); // We access the element at idx (i, j) from the dense matrix.
}
