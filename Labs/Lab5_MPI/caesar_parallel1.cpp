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

    std::cout << "Your sentence is:"  << std::endl;
    std::cout << "    " << sentence << std::endl;
    std::cout << "It should be " << (is_encrypted ? "decrypted." : "encrypted.") << std::endl;
  }

  if (rank == 0)
  {
    std::cout << "Please, insert the Caesar number: ";
    std::cin >> key;
  }

  // communicate the key to all ranks
  MPI_Bcast(&key, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

  // communicate the sentence length to all ranks
  unsigned sentence_length = sentence.size();
  MPI_Bcast(&sentence_length, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

  // compute the local sentence length
  unsigned local_sentence_length = sentence_length / size;

  // initialize the local sentence
  std::string local_sentence(local_sentence_length, 'x');
  MPI_Scatter(&sentence[0], local_sentence_length, MPI_CHAR, 
                    &local_sentence[0], local_sentence_length, MPI_CHAR, 
                    0, MPI_COMM_WORLD);

  // compute the new local sentence
  std::string new_local_sentence = caesar(local_sentence, key, is_encrypted);

  // gather results
  std::string new_sentence(sentence_length, 'x');
  MPI_Gather(&new_local_sentence[0], local_sentence_length, MPI_CHAR, 
                    &new_sentence[0], local_sentence_length, MPI_CHAR, 
                    0, MPI_COMM_WORLD);

  if (rank == 0)
  {
    std::cout << std::endl;
    std::cout << "The new sentence is:" << std::endl;
    std::cout << "    " << new_sentence << std::endl;
  }

  MPI_Finalize();

  return 0;
}

std::string caesar (const std::string& str, unsigned key, bool is_encrypted)
{
  std::string new_str(str);

  int signed_key = (is_encrypted) ? -key : key;

  for (unsigned i = 0; i < new_str.size(); ++i)
  {
    if (! isblank(new_str[i]))
    {
      char c = new_str[i] + signed_key;
      if (c > 'Z')
        c -= 26;
      else if (c < 'A')
        c += 26;
      new_str[i] = c;
    }
  }

  return new_str;
}
