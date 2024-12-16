#include "nd_vector.hh"

namespace numeric
{
  nd_vector::nd_vector (size_type n)
    : x (n, 0.) {}

  nd_vector::nd_vector (std::initializer_list<double> il)
    : x (il) {}

  nd_vector::size_type
  nd_vector::size (void) const
  {
    return x.size ();
  }

  void
  nd_vector::read (std::ifstream & input_stream)
  {
    std::string line;

    while ( getline (input_stream,line) )
    {
      x.push_back(std::stod(line));
    }
    input_stream.close();

  }

  void
  nd_vector::print() const{
    for (auto it = x.cbegin(); it != x.cend(); it++)
      std::cout << *it << std::endl;
    std::cout << std::endl;
  }

  nd_vector::reference
  nd_vector::operator [] (size_type idx)
  {
    return x[idx];
  }

  nd_vector::value_type
  nd_vector::operator [] (size_type idx) const
  {
    return x[idx];
  }

  nd_vector::pointer
  nd_vector::data (void)
  {
    return x.data ();
  }

  nd_vector::const_pointer
  nd_vector::data (void) const
  {
    return x.data ();
  }
}
