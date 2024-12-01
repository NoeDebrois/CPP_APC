#include "DataFrame.h"

DataFrame::DataFrame (void)
  : added_first_column (false), n_rows (0) 
{}



std::vector<DataFrame::key_type>
DataFrame::split (const key_type & s,  char delim) const
{
  key_type word;
  std::vector<key_type> v;
  std::istringstream columns (s);

  while (std::getline (columns, word, delim)) v.push_back (word);

  return v;
}

void
DataFrame::print (void) const
{
  for (const value_type & element : df_data)
    {
      std::cout << element.first << " :: ";

      for (const double & d : element.second)
        std::cout << d << " ";

      std::cout << std::endl;
    }
}

// Question 1 : constructor from string of column names.
DataFrame::DataFrame (const key_type & c_names)
  : DataFrame ()
{
  /* MY CODE */
    auto column_names = split(c_names, ' '); // We separate by space.
    for (const auto & column_name : column_names) {
        df_data[column_name];
    }
}

// UTILITY for next questions.
bool
DataFrame::check_column_name (const key_type & column_name) const
{
    /* MY CODE */
    return df_data.find(column_name) != df_data.end(); // True if it exists.
}

// UTILITY for next questions.
void
DataFrame::set_column_data (const key_type & column_name,
                            const mapped_type & column_data)
{
    /* MY CODE */
    if (!added_first_column) { // new column added.
        added_first_column = true; // we added a first column.
        n_rows = column_data.size(); // change n_rows to save the size.
        for (auto it = df_data.begin (); it != df_data.end (); ++it) {
            it->second.resize (n_rows); // The vector is in second position.
        }
        df_data[column_name] = column_data; // We would like to make a swap, but it's not
        // possible since column_data is a const ref.
    }
    else {
        // at least one column exists, check n_rows.
        if(column_data.size () != n_rows) { // OK : we can add this column_data.
            // Nothing to do.
        }
        else { // ERROR : we cannot add a column that doesn't have the right nb off rows.
            std::cerr << "ERROR, " << column_name
                      << " has a different number of rows" << std::endl;
        }
    }
}

// Question 2 : set the values of an EXISTING column.
void
DataFrame::set_column(const key_type & column_name,
                      const mapped_type & column_data)
{
    /* MY CODE */
    if (check_column_name(column_name)) { // OK : the column indeed exists.
        set_column_data(column_name, column_data);
    }
    else { // ERROR : the column doesn't exist.
        std::cerr << "ERROR, " << column_name << " is unknown" << std::endl;
    }
}

// Question 3 : set a single value of a column.
void
DataFrame::set_element_at (const key_type & column_name,
                            size_type index, double value)
{
    /* MY CODE */
    // We have to check that this column exists :
    if (check_column_name(column_name)) { // OK : the column indeed exists.
        // We have to check that the index is not out of bounds :
        if(index < n_rows) {
            df_data[column_name][index] = value;
        }
        else { // Out of range !
            std::cerr << "ERROR, index out of bounds" << std::endl;
        }
    }
    else { // ERROR : the column doesn't exist.
        std::cerr << "ERROR, " << column_name << " is unknown" << std::endl;
    }
}

// Question 2-bis : getter used in the main.
DataFrame::mapped_type
DataFrame::get_column (const key_type & column_name) const
{
    /* MY CODE */
    if (check_column_name(column_name)) { // OK : the column indeed exists.
        return df_data.at(column_name); // We cannot do df_data[column_name] because
        // the subscript method is a non-const method.
    }
    else { // ERROR : the column doesn't exist.
        std::cerr << "ERROR, " << column_name << " is unknown" << std::endl;
        return std::vector<double> (); // We are forced to return a mapped_type type.
    }
}

// Question 3-bis : getter used in the main.
double
DataFrame::get_element_at (const key_type & column_name,
                           size_type index) const
{
    /* MY CODE */
    if (check_column_name(column_name)) {
        // OK : the column indeed exists.
        // We have to check that the index is not out of bounds :
        if (index < n_rows) {
            return df_data.at(column_name)[index];
        }
        else { // Out of range !
            std::cerr << "ERROR, index out of bounds" << std::endl;
            return std::numeric_limits<double>::quiet_NaN(); // We have to return something (a double).
        }
    }
    else {
        std::cerr << "ERROR, " << column_name << " is unknown" << std::endl;
        return std::numeric_limits<double>::quiet_NaN(); // We have to return something (a double).
    }
}

// Question 4 : compute and return mean of given column.
double
DataFrame::get_mean (const key_type & column_name) const
{
    /* MY CODE */
    if (check_column_name(column_name)) { // The column indeed exists.
        double sum = 0.0;

        for (double d : df_data.at(column_name)) {
            sum += d;
        }
        return sum / n_rows; // We compute the mean starting from the sum, and return it.
    }
    else {
        std::cerr << "ERROR, " << column_name << " is unknown" << std::endl;
        return std::numeric_limits<double>::quiet_NaN(); // We have to return something, a double.
    }
}

// UTILITY for question 5 : add a new column with data.
void
DataFrame::add_column (const key_type & column_name,
                        const mapped_type & column_data) {
    /* MY CODE */
    if (!check_column_name(column_name)) { // If not already existing, add it.

    }
}

// Question 5 : return copy of DataFrame with row(s) i s.t. "c_name[i] == value".
DataFrame
DataFrame::select_equal (const key_type & c_name, double value) const
{
    /* MY CODE */
    // We have to :
    // - Check that column exists ;
    if (!check_column_name(c_name)) { // The column doesn't exist !
        // Therefore we return an empty dataframe.
        std::cerr << "ERROR, " << c_name << " is unknown" << std::endl;
        return DataFrame ();
    }
    // The column indeed exists, so :
    std::vector<size_type> indexes; // Solution indexes
    const mapped_type & relevant_column = df_data.at(c_name);

    // - Scan all elements of that column and test equality to value ;
    for (size_type i = 0; i < n_rows; ++i) {
        if (relevant_column[i] == value) { // The value we are looking for :
            indexes.push_back (i);
        }
    }
    // - Copy these rows into the result Dataframe : scan all columns and for each
    // column just select the ones whose indexes are in "indexes".
    DataFrame result;
    for (const value_type & element : df_data) {
        // I have a column in my hand...
        // ... I need to keep only the rows with the right indexes.
        mapped_type v; // Select the values I'm interested in from the current column.
        v.reserve(indexes.size()); // complexity is O(n_rows) instead of O(n_rows^2)
        for (size_type idx : indexes) {
            v.push_back(element.second[idx]);
        }
        result.df_data[element.first] = v; // If you have implemented the above method,
        // it would be : result.add_column(element.first, v);
    }
    return result;
}
