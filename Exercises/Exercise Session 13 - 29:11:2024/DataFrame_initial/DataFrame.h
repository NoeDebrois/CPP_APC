#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <map>
#include <vector>


/*
QUESTIONS:
1) constructor from string of column names
2) set_column()
3) set_element_at()
2-3-bis) get_column() and get_element_at() used in the main
4) get_mean()
5) select_equal()
*/


class DataFrame {
public:
  // !! Define internally used types to be more general :
  typedef std::map<std::string, std::vector<double>> df_type; // Dataframe type !
  // These other definitions follow from df_type
  typedef df_type::key_type key_type;        // string
  typedef df_type::value_type value_type;    // pair<const string, vector<double> >
  typedef df_type::mapped_type mapped_type;  // vector<double>
  typedef mapped_type::size_type size_type;  // size_t
  // The way to be the most general.

private:
  df_type df_data;
  bool added_first_column; // To check the size at the beginning.
  size_type n_rows;

  // return the names of columns in s separated by delim
  std::vector<key_type> split(const key_type &s, char delim) const;

  // UTILITY: returns true if column_name exists
  bool check_column_name(const key_type &column_name) const;

  // UTILITY: set a column data only checking if the number of rows is correct
  void set_column_data(const key_type &column_name,
                       const mapped_type &column_data);

public:
  DataFrame();
  void print(void) const;

  // Question 1: constructor from string of column names
  explicit DataFrame(const key_type &c_names);

  // Question 2: set the values of an EXISTING column
  void set_column(const key_type &column_name, const mapped_type &column_data);

  // Question 3: set a single value of a column
  void set_element_at(const key_type &column_name, size_type index,
                      double value);

  // Question 2-bis: getter used in the main
  mapped_type get_column(const key_type &column_name) const;

  // Question 3-bis: getter used in the main
  double get_element_at(const key_type &column_name, size_type index) const;

  // Question 4: compute and return mean of given column
  double get_mean(const key_type &column_name) const;

  // UTILITY: add a new column with data
  void add_column(const key_type &column_name, const mapped_type &column_data);

  // Question 5: return copy of DataFrame with rows i s.t. "c_name[i] == value"
  DataFrame select_equal(const key_type &c_name, double value) const;
};


#endif  //DATAFRAME_H
