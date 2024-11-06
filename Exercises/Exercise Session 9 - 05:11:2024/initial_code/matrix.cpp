#include "matrix.hpp"

Matrix::Matrix (unsigned rows, unsigned cols): n_rows (rows), n_cols (cols)
{}

unsigned Matrix::get_n_cols() const
{
    return n_cols;
}
unsigned Matrix::get_n_rows() const
{
    return n_rows;
}