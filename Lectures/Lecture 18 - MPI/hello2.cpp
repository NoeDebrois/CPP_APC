#include <cstdio>
#include <mpi.h>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);
  int rank, size;
  MPI_Comm_size (MPI_COMM_WORLD, &size);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);

	// Assumption we use up to 10 processes, no more!
	constexpr unsigned max_string = 18; 
	std::ostringstream builder;
	builder << "Hello from " << rank << " of " << size;
	std::string message (builder.str ());
	if (rank > 0)
  		MPI_Send (&message[0], max_string , MPI_CHAR,
            	  0, 0, MPI_COMM_WORLD);
	else 
  	{
    	std::cout << message << std::endl;
    	for (int r = 1; r < size; ++r)
      	{
        	MPI_Recv (&message[0], max_string , MPI_CHAR, r, 0,
            	      MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        	std::cout << message << std::endl;
      	}
}

  
  MPI_Finalize ();
  return 0;
}
