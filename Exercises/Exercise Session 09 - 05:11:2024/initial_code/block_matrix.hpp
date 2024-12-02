#ifndef BLOCKMATRIX_H_
#define BLOCKMATRIX_H_

#include <vector>

#include "block.hpp"

class BlockMatrix: public Matrix // Child class of Matrix class.
{
    private:
        std::vector<Block> blocks;

        bool indicies_in_matrix(unsigned i, unsigned j) const;
        bool indicies_in_block(unsigned i, unsigned j, const Block& block) const;
    public:
        BlockMatrix(); // Constructor : look at implementation, it initialises a (class) Matrix with 0 row and 0 column.

        void addBlock(const Block& block); // Receives a block and adds it to the matrix.

        // Call '()' operators : this time, as it is a child class of Matrix, these methods have to override the base
        // class corresponding methods :
        double operator() (unsigned i, unsigned j) const override;
        double& operator() (unsigned i, unsigned j) override;
};

#endif /* BLOCKMATRIX_H_ */
