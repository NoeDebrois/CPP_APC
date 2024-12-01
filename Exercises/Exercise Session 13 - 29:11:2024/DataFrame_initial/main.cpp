#include <iostream>
#include <vector>

#include "DataFrame.h"

int main() {
  std::cout << "- Declare DataFrame" << std::endl;
  DataFrame df("c1 c2");
  df.print();
  std::cout << std::endl;


  std::cout << "- Test set_column()" << std::endl;
  std::vector<double> v1 = {1, 2, 3};
  std::vector<double> v2 = {4, 5, 6};
  df.set_column("c1", v1);
  df.set_column("c2", v2);
  df.set_column("c2", v1);  // already full: ok, gets replaced
  df.set_column("c3", v1);  // unknown: error!
  df.print();
  std::cout << std::endl;


  std::cout << "- Test get_column() with existing column" << std::endl;
  std::vector<double> v_res = df.get_column("c1");
  std::cout << "Printing v_res" << std::endl;
  for (size_t i = 0; i < v_res.size(); i++)
    std::cout << v_res[i] << " ";
  std::cout << std::endl << std::endl;


  std::cout << "- Test get_column() with unknown column" << std::endl;
  v_res = df.get_column("c3");
  std::cout << "Printing v_res" << std::endl;
  for (size_t i = 0; i < v_res.size(); i++)
    std::cout << v_res[i] << " ";
  std::cout << std::endl << std::endl;


  std::cout << "- Test get_mean()" << std::endl;
  std::cout << "mean of c1 = " << df.get_mean("c1") << std::endl;
  std::cout << "mean of c2 = " << df.get_mean("c2") << std::endl;
  std::cout << std::endl;


  std::cout << "- Test set_column() with wrong number of rows" << std::endl;
  df.set_column("c2", v2);
  std::vector<double> v3 = {4, 5};
  df.set_column("c2", v3);
  std::cout << std::endl;


  std::cout << "- Test get_mean() again" << std::endl;
  std::cout << "mean of c2 = " << df.get_mean("c2") << std::endl;  // existing
  std::cout << "mean of c3 = " << df.get_mean("c3") << std::endl;  // unknown
  std::cout << std::endl;


  std::cout << "- Test get_element_at()" << std::endl;
  std::cout << "(c2,1) = " << df.get_element_at("c2", 1) << std::endl;  // ok
  std::cout << "(c2,4) = " << df.get_element_at("c2", 4) << std::endl;  // OOB
  std::cout << "(c3,1) = " << df.get_element_at("c3", 1) << std::endl;  // c3?
  std::cout << std::endl;


  std::cout << "- Test set_element_at()" << std::endl;
  df.set_element_at("c2", 1, 27);
  std::cout << "(c2,1) = " << df.get_element_at("c2", 1) << std::endl;
  std::cout << std::endl;


  std::cout << "Test add_column()" << std::endl;
  df.add_column("c3", v1);
  std::cout << "df after add:" << std::endl;
  df.print();
  std::cout << std::endl;


  std::cout << "- Test select_equal()" <<  std::endl;  
  DataFrame select_df = df.select_equal("c2", 27);
  std::cout << "select_df:" <<  std::endl;
  select_df.print();

  return 0;
}
