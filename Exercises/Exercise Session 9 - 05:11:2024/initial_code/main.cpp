#include <iostream>

#include "block.hpp"
#include "block_matrix.hpp"
#include "dense_matrix.hpp"
#include "matrix.hpp"

int main()
{
   DenseMatrix dm (3, 4);
   std::cout << "End constructor DM " << std::endl;

   for (unsigned i = 0; i < dm.get_n_rows(); ++i)
   {
      for (unsigned j = 0; j < dm.get_n_cols(); ++j)
         std::cout << dm(i, j) << " ";

      std::cout << std::endl;
   }

   std::cout << std::endl;

   for (unsigned i = 0; i < dm.get_n_rows(); ++i)
      for (unsigned j = 0; j < dm.get_n_cols(); ++j)
         dm(i, j) = i + j;

   std::cout << "!end set!" << std::endl;

   for (unsigned i = 0; i < dm.get_n_rows(); ++i)
   {
      for (unsigned j = 0; j < dm.get_n_cols(); ++j)
         std::cout << dm(i, j) << " ";

      std::cout << std::endl;
   }

   std::cout << "End constructor BM" << std::endl;
   BlockMatrix bm;
   Block block1 (0, 0, 1, 1, {1, 1, 1, 1});
   bm.addBlock (block1);
   Block block2 (2, 2, 4, 5, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2});
   bm.addBlock (block2);

   for (unsigned i = 0; i < bm.get_n_rows(); ++i)
   {
      for (unsigned j = 0; j < bm.get_n_cols(); ++j)
      {
         std::cout << bm(i, j) << " ";
      }
      std::cout << std::endl;
   }

   bm(3, 4) = 3;
   std::cout << "Second print BM" << std::endl;

   for (unsigned i = 0; i < bm.get_n_rows(); ++i)
   {
      for (unsigned j = 0; j < bm.get_n_cols(); ++j)
         std::cout << bm(i, j) << " ";

      std::cout << std::endl;
   }

   return 0;
}
