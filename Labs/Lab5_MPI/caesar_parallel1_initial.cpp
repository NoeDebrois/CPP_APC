#include <iostream>
#include <vector>
#include <string>
#include <mpi.h>

std::string caesar (const std::string& str, unsigned key, bool is_encrypted);

int main (int argc, char *argv[])
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  unsigned key = 0;
  std::string sentence = "";
  bool is_encrypted = true;

  if (rank == 0)
  {
    sentence = "Q EQTT OQDM I KPWKWTIBM JIZ BW IVGWVM EPW LMKZGXBA BPQA";

    std::cout << "Your sentence is:" << std::endl;
    std::cout << "    " << sentence << std::endl;
    std::cout << "It should be " << (is_encrypted ? "decrypted." : "encrypted.") << std::endl;
  }

  /*
      YOUR CODE GOES HERE
  */

  if (rank == 0)
  {
    std::cout << std::endl;
    std::cout << "The new sentence is:" << std::endl;
    std::cout << "    " << new_sentence << std::endl;
  }

  MPI_Finalize();

  return 0;
}
