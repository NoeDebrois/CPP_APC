#ifndef __ND_VECTOR__
#define __ND_VECTOR__

#include <initializer_list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace numeric
{
  class nd_vector
  {
    typedef std::vector<double> container_type;

    container_type x;

  public:
    typedef container_type::value_type value_type;
    typedef container_type::size_type size_type;
    typedef container_type::pointer pointer;
    typedef container_type::const_pointer const_pointer;
    typedef container_type::reference reference;
    typedef container_type::const_reference const_reference;

    explicit nd_vector (size_type n = 0);
    nd_vector (std::initializer_list<double>);


    size_type
    size (void) const;

    void
    read (std::ifstream & input_stream);

    void
    print() const;


    reference
    operator [] (size_type);
    value_type
    operator [] (size_type) const;

    pointer
    data (void);
    const_pointer
    data (void) const;
  };
}

#endif
