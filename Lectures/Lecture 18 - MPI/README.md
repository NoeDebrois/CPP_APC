# MPI Program Structure and Basics

## Communicator
- A communicator is a collection of processes that can send messages to each other.
- **Size**: Number of processes it collects.
- **Rank**: Unique identifier in [0, size) for each process.

For example, `MPI_COMM_WORLD` :
- A predefined communicator.
- Collects every process launched with the program.

## MPI Basic Functions
### `MPI_Init`
- Usage: `int MPI_Init(int* argc_p, char*** argv_p)`
- The arguments, `argc_p` and `argv_p` are pointers to the arguments of main, `argc` and `argv` (we can pass `nullptr`).
- Tells the MPI system to do all the necessary setup.
- No other MPI functions should be called before the program calls `MPI_Init`.

### `MPI_Finalize`
- Usage: `int MPI_Finalize(void)`
- Tells the MPI system that we’re done using MPI, and that any resources allocated for MPI can be freed.
- No MPI functions should be called after the call to `MPI_Finalize`.

### `MPI_Comm_size`
- Usage: `MPI_Comm_size(MPI_Comm comm, int *size)`
  - Returns the number of processes in the communicator (`*size`).
  - **First argument**: Communicator of type `MPI_Comm`.

### `MPI_Comm_rank`
- Usage: `MPI_Comm_rank(MPI_Comm comm, int *rank)`
  - Returns the rank of the calling process in the communicator (`*rank`).
  - **First argument**: Communicator of type `MPI_Comm`.

### "Hello World" Example with MPI

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
}
```

**Compiling and running the "Hello World" Program :**

*First*, to compile the MPI "Hello World" program, go to the correct directory and use the following command:

```bash
mpicxx --std=c++23 -o helloMPI hello.cpp
```
- **mpicxx**: The MPI C++ compiler wrapper.
- **-o helloMPI**: Specifies the output executable file name (`helloMPI`).
- **hello.cpp**: The source file containing the "Hello World" code. Replace this with your actual filename if it's different.

*Then*, to run the MPI "Hello World" program, use the following command:

```bash
mpiexec -np 2 ./helloMPI
```
- **mpiexec**: Launches the MPI program.
- **-np 2**: Specifies the number of processes to use (4 in this example).
- (**-oversubscribe**: if too much processes have been already used).
- **./helloMPI**: The name of the compiled executable file.

---

## Other MPI Functions : `MPI_Send` and `MPI_Recv`
### `MPI_Send`
- Usage: `int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)`
- Example: `MPI_Send(&message[0], max_string, MPI_CHAR, 0, 0, MPI_COMM_WORLD)`
- Explanation:
  - The first 3 arguments `buf`, `count`, and `datatype` determine the contents of the messsage ;
  - The remaining arguments `dest`, `tag`, and `comm` determine the destination of the message.

### `MPI_Recv`
- Usage: `int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)`
- Example: `MPI_Recv(&message[0], max_string, MPI_CHAR, r, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE)`

For both `MPI_Send` and `MPI_Recv`, here are the explanations related to the arguments: 
- `buf`: array storing the data to send or to receive;
- `count`: states how many replicas of the data type will be sent, or the maximum allowed;
- `source`/`dest`: **ranks** identifying the targer sender or the receiver;
- `tag`: nonnegative `int` used to distinguish messages traveling on the same connection (we won't use it in the APC course) *that are otherwise identical*.
    - For example: if "process 1" is sending `floats` to "process 0" but some of them should be printed and the others should be used in a computation : "process 1" can use, say, a `tag` of 0 for the messages that should be printed and a `tag` of 1 for the messages that should be used in a computation.
- `status`: detailed information on received data. *We won't use it, so we will mainly pass* `MPI_STATUS_IGNBORE`.

MPI Datatypes are the following :
- `MPI_CHAR`;
- `MPI_SHORT`;
- `MPI_INT`;
- `MPI_LONG`;
- `MPI_UNSIGNED_CHAR`;
- `MPI_UNSIGNED_SHORT`;
- `MPI_UNSIGNED_CHAR`;
- `MPI_UNSIGNED_LONG`;
- `MPI_FLOAT`;
- `MPI_DOUBLE`;
- `MPI_LONG_DOUBLE`;
- `MPI_BYTE`.
- **WARNING:** No "`MPI_STRING`" !

---

## Message matching, or how a message sent by q can be received by r :
- In process q: `MPI_Send(send_buf, send_count, send_datatype, dest, send_tag, send_comm)` ;
- In process r: `MPI_Recv(recv_buf, recv_count, recv_datatype, src, recv_tag, recv_comm, &status)` ;
- **The message sent by q can be received by r if:**
  - `send_comm = recv_comm` ;
  - `dest = r` ;
  - `src = q` ;
  - `recv_tag = send_tag` ;
  - `recv_datatype = send_datatype` ;
  - `recv_count >= send_count`.
- **Non-overtaking message:** if process q send two messages to process r, then the first message sent by q must be available to r before the second message.
  - There is no such restriction on the arrival of messages sent from different processes.
 
## Deadlocks in MPI :
- **Deadlocks** occur when processes block for communication, but their requests remain unmatched or otherwise unprocessed.
  - Example: in the same time process 0 `MPI_Send(n)` and process n `MPI_Send(0)` ; and after, once again in the same time, process 0 `MPI_Recv(n)` and process n `MPI_Recv(0)`.
- To prevent deadlocks : *smartly rearrange communications* ! (or use non-blocking calls but we won't use them in APC course).

## Process hang :
- If a process tries to *receive* a message and there is **no matching send**, then the process will **block forever**.
- When you code, be sure that every *receive* has a matching *send*.
- Be careful to inadvertent mistakes in calls to `MPI_Send` and `MPI_Recv` :
  - If tags don't match : the *receive* won't match the *send* ;
  - If the rank of the destination process is the same as the rank of the source process : the *receive* won't match the *send*.
  - Either the process will **hang**, or the receive may match another send.
 
## Quadrature Function Implementation Example with MPI :
We want to build a program which computes the quadrature of a function f(x) over a specified interval [a, b] using the trapezoidal rule.
We want to divide the intermediate computations of trapezoid areas into different cores, and at the end we *need to aggregate the computations of these areas*.

**Basic Idea:**
- Split the interval [a, b] up into `comm_sz` subintervals ;
- If `comm_sz` evenly divides n the *number of trapezoids*, we can simply apply the trapezoidal rule with n / `comm_sz` trapezoids to *each* of the `comm_sz` subintervals ;
- At the end, process 0 adds all the estimates.

**To test the DEMO on trapezoidal rule:**
- cd inside the folder ;
- mpicxx -o reduce --std=c++11 with_io.cc quadrature.cc bcast.cc reduce.cc [COMPILE] (creates an output executable file named "reduce") ;
- mpiexec -np 4 -oversubscribe reduce ;
- Enter lower bound / upper bound / number of trapezoids.

---

## MPI B :

### Collective Communication : *Or how to throw flyers from a plane*

- `MPI_Send` and `MPI_Recv` are for "one-to-one" communication ;
- Instead if send many one-to-one communications, one single  `broadcast` is more *network efficient*.
- Let's discover **collective routines**.

### Collective routines :
- Involve all the processes in a communicator ;
- Only transmit predefined MPI data types ;
- Cannot use tgas to identify messages ;
- **Warning!** Be sure that every process in the communicator calls the **same** collective function to avoid deadlocks.

### `Broadcast` :
- Usage: `int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)`
  - Delivers an exact copy of the data in `buffer` from `root` to all the processes in `comm` ;
  - Simple example :
    | Rank | `buffer` Before | `buffer` After |
    |--------|------|--------|
    | 0 | A | A |
    | 1 | ? | A |
    | 2 | ? | A |
    | 3 |? |A |
  - Example with the trapezoidal quadrature, with broadcasting inputs :
    ```cpp
      #include <iostream>
      #include <mpi.h>
      #include "input.hh"
      
      namespace mpi // Namespace to encapsulate MPI-related functions
      {
        // Function to get input values and broadcast them to all processes
        void get_input (double & a, double & b, unsigned & n)
        {
          int rank; // Variable to store the rank of the current process
          MPI_Comm_rank (MPI_COMM_WORLD, &rank); // Get the rank of the current process

          // If the current process is the root (rank 0), read input values from stdin
          if (rank == 0) std::cin >> a >> b >> n;

          // Broadcast the values to all processes in the communicator
          MPI_Bcast (&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
          MPI_Bcast (&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
          MPI_Bcast (&n, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
        }
      }  
    ```
  - To compile with P2P : `mpicxx -o reduce --std=c++23 with_io.cc quadrature.cc p2p_input.cc p2p_output.cc` ;
  - To compile with Broadcast : `mpicxx -o reduce --std=c++23 with_io.cc quadrature.cc bcast.cc p2p_output.cc`.
  - **Warning!** We are not computing the "global sum" efficiently : in the end we don't want to send everything to one single process that has to compute the sum alone...
    - Instead we want to *split the final sum work* : this is what `MPI_Reduce` does ! cf the following picture.
    ![](IMG_Sum_Work.jpeg)

### `MPI_Reduce` :
- Usage: `int MPI_Reduce(const void  *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int dest, MPI_Comm comm)` ;
  - Applies `op` to portions of data in `sendbuf` from all the processes in `comm`, storing the result in `recvbuf` on `dest` ;
  - Simple example :
    ```cpp
    double local_partial; // Some partial sum
    double total;
    // Perform reduction to sum up partial values
    MPI_Reduce(&local_partial, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    ```
  - What it does in a simple example :
    | Rank | `local_partial` | `total` |
    |--------|------|--------|
    | 0 | 1 | 10 |
    | 1 | 2 | N/A |
    | 2 | 3 | N/A |
    | 3 |4 |N/A |
- The `Reduce` provided operators (`MPI_Op`)  are :
  - `MPI_MAX` ;
  - `MPI_MIN` ;
  - `MPI_SUM` ;
  - `MPI_PROD` ;
  - Others that don't interest us for this course.
- Example: `mpi::sum_and_print` function demonstrates how to aggregate partial results from multiple processes and output the result in the root process.
  ```cpp
  #include <mpi.h> // Include the MPI library
  #include "sum_and_output.hh" // Custom header for function declarations
  
  namespace mpi // Encapsulate MPI-related functions in a namespace
  {
    // Function to compute the sum of partial integrals and print the result
    void sum_and_print (double local_integral, std::ostream & out, double a, double b, unsigned n)
    {
      int rank; // Variable to store the rank of the current process
      MPI_Comm_rank (MPI_COMM_WORLD, &rank); // Get the rank of the current process
  
      double total (0.); // Initialize the total sum
      // Perform reduction to sum all local integrals and store the result in the root process
      MPI_Reduce (&local_integral, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  
      // If the current process is the root (rank 0), print the results
      if (rank == 0)
        {
          out << "n = " << n << ", a = " << a << ", b = " << b
              << ", integral = " << total << std::endl;
        }
    }
  }
  ```
- By using a `count` argument greater than 1, `MPI_Reduce` can operate on arrays instead of scalars ;
  - The following code could thus be used to add a collection of N-dimensional vectors :
    ```cpp
    std::vector<double> local_x (N), sum (N) ;
    /* Partial computation on local_x :*/
    MPI_Reduce(local_x.data (), sum.data (), N, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    // Where .data () returns the pointer to the vector elements.
    ```

### `MPI_Allreduce` :
- When all the processes need the result of a global sum to compute some larger computation (instead of only one process which prints the result like in the previous example) ;
- Usage: `int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)`
  - It's a variant of `MPI_Reduce` but which stores the result on all the processes in the communicator.

### `MPI_IN_PLACE` :
- Collective communication routine generally use both a send and receive *buffer* ;
  - When dealing with a lot of data it means occupying a lot of memory !
- MPI provides a special placeholder `MPI_IN_PLACE` to **enable the use of a SINGLE buffer for both input and output** ;
- Usage:
  ```c++
  double minimum (local_min);
  MPI_Allreduce(MPI_IN_PLACE, &minimum, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
  ```
- **WARNING!** It is **illegal** in MPI to try to use the same buffer for input and output like this `MPI_Reduce(&x, &x, 1, MPI_DOUBLE, MPI_SUM, 0, comm)` ;
  - Don't do that! Instead, call : `MPI_Reduce(MPI_IN_PLACE, &x, 1, MPI_DOUBLE, MPI_SUM, 0, comm);`.

### Working with vectors : *scatter & gather*
- Suppose we want to write a parallel function that computes a vector sum: x + y = (x_0 + y_0, ..., x_{n-1} + y_{n-1}) = z ;
- If the *number of component is n*, and we have *comm_sz cores or processes*, let's assume that n evenly divides comm_sz, we can define local_n = n / comm_sz ;
- We can parallelize the sum by assigning blocks of local_n consecutive components to each or our comm_sz processes :
  | Process | Block |
  |---------|-------|
  | 0 | 0-1-2-3 | 
  | 1 | 4-5-6-7 | 
  | 2 | 8-9-10-11 |
  - This is called **block partition**.
    - Block partitioning is used when data source is available on a single process. We have a primitive for this (`MPI_Scatter`).
- Or we can also parallelize by assigning components in a round fashion :
  | Process | Cyclic |
  |---------|-------|
  | 0 | 0-3-6-9 | 
  | 1 | 1-4-7-10 | 
  | 2 | 2-5-8-11 |
  - This is called **cyclic partition**.
    - Cyclic partitioning is used when data source is already available across all processes. We don't need any assumptions on the number of elements to be processed.
   
### Block partitioning (data distributions) :
- Each process will have `local_n` components of the vectors and, in order to save on storage, we can just store these on each process as a vector of `local_n` elements.
  ```cpp
  vector<double> parallel_sum (const vector<double> & local_x, const vector<double> & local_y)
  {
  vector<double> local_z(local_x.size()); // Initialization of the "local" z vector.
  for (size_t i = 0; i < local_x.size(); i++)
      {
      local_z[i] = local_x[i] + local_y[i]; // Compute the "local" vector sum.
      }
  return local_z;
  }
  ```
  - We only store local_x and local_y, not the full x and y, on each process.
- To implement our vector addition function, we need :
  - To read the dimension of the vectors : process 0 can prompt the user, read the dimension, and broadcast the dimension to the other processes ;
  - To read the vectors x and y : process 0 reads them (no other option) and sends the *needed components* to each of the other processes ;
  - This is exactly what `MPI_Scatter` implements ! (**block partition scheme**).

#### `MPI_Scatter`
- Usage: `int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)` ;
  - Sends a portion of the data in `sendbuf` from `root` to all the processes in `comm`, storing it in `recvbuf`;
  - `sendbuf` holds `sendcount * size` (i.e `sendcount` is the number of elements sent to individual processes) ;
- Simple example where rank 0 is the root :
  | Rank | `sendbuf` | `recvbuf` |
  |--------|------|--------|
  | 0 | ABCDEFGH | AB |
  | 1 | N/A | CD |
  | 2 | N/A | EF |
  | 3 |N/A |GH |
  - Clearly `MPI_Scatter` is the implementation of **block partitioning**.
- Example `read_vector` :
  ```cpp
  std::vector<double> read_vector(unsigned n, std::string const & name, MPI_Comm const & comm)
  {
  int rank, size; // Attribute a rank and a size for the processes in comm.
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);

  const unsigned local_n = n / size;
  std::vector<double> result (local_n) // Very important !

  if (rank == 0)
    {
      std::vector<double> input(n);
      std::cout << "Enter " << name << "\n"; 
      for (double & e : input) // Ask for n coefficients (n is an argument).
        std::cin >> e; // Input the coefficients of the vector.

      MPI_Scatter(input.data (), local_n, MPI_DOUBLE, result.data (), local_n, MPI_DOUBLE, 0, comm);
      // The root process (rank 0) splits the vector input into chunks and sends each chunk to the
      // corresponding process (including itself).
    }
  else
    {
      /* Here are only receiveing processes (ranks), no need for the send buffer. */
      MPI_Scatter (nullptr, local_n, MPI_DOUBLE, result.data (), local_n, MPI_DOUBLE, 0, comm);
      // The non-root processes only receive their respective chunk of the data; they do not send any
      // data : that's why there is nullptr in sendbuf.
      // Each non-root process receives a chunk of local_n elements from the vector input (owned by the
      // root process) into its result vector.
    }
  return result; // The return result only provides the local portion of the data (result) to the calling
  // code on that specific process.
  }
  ```

#### `MPI_Gather`
- Usage: `int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)`
  - It joins portions of data in `sendbuf` from all the processes in `comm` to `root`, storing them all in `recvbuf` ;
  - `recvcount` values received from each process.
  - Simple example where rank 0 is the root :
    | Rank | `sendbuf` | `recvbuf` |
    |--------|------|--------|
    | 0 | AB | ABCDEFGH |
    | 1 | CD | N/A |
    | 2 | EF | N/A |
    | 3 |GH |N/A |
- Example `print_vector` :
  ```cpp
  void print_vector(vector<double> const & local_v, unsigned n, string const & title, MPI_Comm const & comm)
  {
  int rank, size;
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);

  const unsigned local_n = local_v.size ();

  if (rank > 0)
    { // all the non-zero ranks send their part...
      /* Here are only sending ranks, no need for receiving buffer */
      MPI_Gather(local_v.data (), local_n, MPI_DOUBLE, nullptr, local_n, MPI_DOUBLE, 0, comm);
      // Receive nothing, hence "nullptr".
    }
  else 
    { // rank 0 receives everything...
      std::vector<double> global (n);
      MPI_Gather(local_v.data (), local_n, MPI_DOUBLE, global.data (), local_n, MPI_DOUBLE, 0, comm);
      // Rank 0 has also to send its part. Hence the sendbuf !
      std::cout << title << "\n";
      for (double value : global)
        std::cout << value << " "; // Reads all the value from the vector.
      std::cout << std::endl; 
    }
  }
  ```

### Final remarks on collective communications :
- All the processes in the communicator must call the same collective function : if a program attempts to match a call to `MPI_Reduce` on one process with a call to `MPI_Recv` on another process, the program will **hang** or **crash**.
- The arguments passed by each process to an MPI collective communication must be "compatible" : if one process passes in 0 as the dest process and another passes in 1, then the program will **hang** or **crash**.
- The `recvbuf` argument is **only used** on `dest` process. However, for `send` processes, you have to pass something, therefore you pass `nullptr`.
