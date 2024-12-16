#include <iostream>
#include "Author.h"
#include <vector>
#include <iostream>
#include <mpi.h>

using std::vector;

using authors =  vector<Author>;

size_t author_nation_count(const string & nation, const authors & auts);

int main(int argc, char *argv[]) {

    int rank;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank (MPI_COMM_WORLD, &rank);


    authors auts;
    auts.emplace_back("S. Lippman", "USA");
    auts.emplace_back("J. K. Rowling","UK");
    auts.emplace_back("A. C. Doyle","UK");

    string nation;
    if (rank ==0)
      std::cin>> nation;

    size_t count_uk =  author_nation_count(nation, auts);

    if (rank ==0)
      std::cout <<count_uk<< std::endl;

    MPI_Finalize();
    return 0;
}

size_t author_nation_count(const string & nation, const authors & auts){
  int rank, size;

  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  // Your code goes here
  


  return 0;
}
