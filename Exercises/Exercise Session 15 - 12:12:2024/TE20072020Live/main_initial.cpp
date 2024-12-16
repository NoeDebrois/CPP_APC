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

  std::string nation_msg = nation;
  unsigned msg_count = nation.length();

  if (rank == 0){
     // commmunicate nation from rank 0 to all
    for (int r =1; r< size; ++r){

      // send lenght of string 
      MPI_Send(&msg_count, 1, MPI_UNSIGNED, r, 0, MPI_COMM_WORLD);

      // send string
      MPI_Send(&nation_msg[0], msg_count, MPI_CHAR, r, 0, MPI_COMM_WORLD);

    }
      

  }
  else { // all other ranks
    // receive nation in all ranks

    // receive lenght
    MPI_Recv(&msg_count, 1, MPI_UNSIGNED, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // resize message string buffer
    nation_msg.resize(msg_count);

    // receive stirng 
    MPI_Recv(&nation_msg[0], msg_count, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }

 


  
  
  // split the vector in blocks  (logically)
  // in a way rank 0 work on first block, rank 1 second block, etc. 
  
 unsigned count = 0;
 size_t local_n = auts.size()/size;

 for (size_t i =  rank * local_n; i < (rank+1)* local_n ; ++i)
  if (auts[i].get_nation() == nation_msg)
    ++count;

  MPI_Allreduce( MPI_IN_PLACE, & count, 1, MPI_UNSIGNED, MPI_SUM, MPI_COMM_WORLD );

  return count;
}
