# MPI Program Structure and Basics

## Communicator
- A communicator is a collection of processes that can send messages to each other.
- **Size**: Number of processes it collects.
- **Rank**: Unique identifier in [0, size) for each process.

## MPI_COMM_WORLD
- A predefined communicator.
- Collects every process launched with the program.

## MPI Functions
### MPI_Comm_size
- Usage: `MPI_Comm_size(MPI_Comm comm, int *size)`
  - Returns the number of processes in the communicator (`*size`).
  - **First argument**: Communicator of type `MPI_Comm`.

### MPI_Comm_rank
- Usage: `MPI_Comm_rank(MPI_Comm comm, int *rank)`
  - Returns the rank of the calling process in the communicator (`*rank`).
  - **First argument**: Communicator of type `MPI_Comm`.

---

## "Hello World" Example with MPI

```cpp
#include <cstdio>  // For printf
#include <mpi.h>   // For MPI functions

int main (int argc, char *argv[]) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int rank, size;

    // Get the total number of processes in the communicator
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the rank (ID) of the current process in the communicator
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Print a message from each process
    printf("Hello from process %d of %d\n", rank, size);

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}```


## TO BE CLEANED :
Those files are the first "parallel computing" implementations that we saw during the course. They should be executed on the VM given during the course.

## hello.cpp :
1) mpicxx --std=c++23 -o helloMPI hello.cpp [COMPILE]
2) mpiexec -np 2 ./helloMPI [RUN]

## trapezoidal_rule :
cd inside the folder and :
1) mpicxx -o reduce --std=c++11 with_io.cc quadrature.cc bcast.cc reduce.cc [COMPILE]
2) mpiexec -np 4 -oversubscribe reduce
3) Enter lower bound / upper bound / number of trapezoids

PS : the number after "-np" corresponds to the number of cores.
PSS : "-oversubscribe" is needed if there are not enough cores avaiable (I guess it uses previously used cores).
