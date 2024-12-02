#include <limits>
#include <iostream>

#include "block_matrix.hpp"

BlockMatrix::BlockMatrix(): Matrix (0, 0)
{}

void BlockMatrix::addBlock(const Block& block)
{
    blocks.push_back(block);
    // BUT we need also to update the number of rows and number of columns of our matrix since it was created at the
    // beginning by the above constructor : so with 0 row and 0 column.
    n_rows = std::max(n_rows, block.get_bottom_right_col() + 1);
    n_cols = std::max(n_cols, block.get_bottom_right_col() + 1);
}

bool BlockMatrix::indicies_in_matrix(unsigned i, unsigned j) const {
    return (i < n_rows) && (j < n_cols);
}

bool BlockMatrix::indicies_in_block(unsigned i, unsigned j, const Block& block) const {
    bool b1 = (i >= block.get_bottom_right_row() && i <= block.get_bottom_right_row());
    bool b2 = (j >= block.get_bottom_right_col() && j <= block.get_bottom_right_col());
    return b1 && b2;
}

double BlockMatrix::operator() (unsigned i, unsigned j) const
{
    // if (i, j) not in the matrix : print error msg and return NaN ;
    // else :
    //      if (i , j) is in a block : return elem ;
    //      else : return 0 (It means in the matrix but not in a block.

    double elem = 0;

    if (! indicies_in_matrix(i, j)) {
        std::cerr << "Indices out of bounds" << std::endl;
        elem = std::numeric_limits<double>::quiet_NaN();
    }
    else {
        bool found = false;
        for (std::vector<Block>::const_iterator it = blocks.cbegin(); it != blocks.cend() && ! found; ++it)
        {
            const Block& block = *it;
            if (indicies_in_block(i, j, block)) {
                found = true;
                elem = block(
                    i - block.get_top_left_row(),
                    j - block.get_top_left_col()
                );
            }
        }
    }

    return elem;
}

double& BlockMatrix::operator() (unsigned i, unsigned j) {
    for (std::vector<Block>::iterator it = blocks.begin(); it != blocks.end(); ++it) {
        Block& block = *it;

        if (indicies_in_block(i, j, block))
        {
            return block(
                    i - block.get_top_left_row(),
                    j - block.get_top_left_col()
                    );
        }
    }
    Block block(i, j, i, j, {0});
    addBlock(block);
    return blocks.back()(0, 0);
}