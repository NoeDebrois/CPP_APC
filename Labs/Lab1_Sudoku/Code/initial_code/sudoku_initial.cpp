/*
 * Check sudoku matrix
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size_t SIZE = 9;

/*
 * YOUR CODE GOES HERE
 */
// Declarations of the functions I code :
int basic_search (const unsigned v[], unsigned n_elements);
int check_rows (const unsigned sudoku[][SIZE]);
int check_cols (const unsigned sudoku[][SIZE]);
int check_regions (const unsigned sudoku[][SIZE]);
// To display beautifully the sudoku grids :
void display_sudoku(const unsigned sudoku[SIZE][SIZE]);

// check_sudoku function : the function that solves the problem of this lab :
// Return:
//         1 if sudoku matrix complies to all Sudoku rules
//        -1 if a row violates the game rules
//        -2 if a column violates the game rules
//        -3 if a region violates the game rules
int check_sudoku(const unsigned sudoku[][SIZE]);

// Create a Sudoku matrix by Lewis' Algorithm
// (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)
void generate_sudoku(unsigned sudoku[][SIZE]);

int main()
{
    // Initialize a sudoku matrix by hand :
    unsigned sudoku[SIZE][SIZE] = {
            {1,2,3,4,5,6,7,8,9},
            {2,3,4,5,6,7,8,9,1},
            {3,4,5,6,7,8,9,1,2},
            {4,5,6,7,8,9,1,2,3},
            {5,6,7,8,9,1,2,3,4},
            {6,7,8,9,1,2,3,4,5},
            {7,8,9,1,2,3,4,5,6},
            {8,9,1,2,3,4,5,6,7},
            {9,1,2,3,4,5,6,7,8}
    };
    // Display the sudoku :
    display_sudoku(sudoku);  // Call the function to display the sudoku grid
    // Check it :
    int res = check_sudoku(sudoku);
    cout << "check_sudoku returns: " <<  res << endl;
    cout << endl;

    // Initialize another sudoku matrix, using the Lewis's algorithm :
    unsigned sudoku2[SIZE][SIZE];
    generate_sudoku(sudoku2);
    // Display the sudoku :
    display_sudoku(sudoku2);  // Call the function to display the sudoku grid
    // Check it :
    res = check_sudoku(sudoku2);
    cout << "check_sudoku returns: " <<  res << endl;
    return 0;
}

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;
    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;
    return key_found;
}

/*
 * YOUR CODE GOES HERE
 */
// Definition of the functions I code :
int basic_search(const unsigned v[], unsigned n_elements) {
    for (size_t key=1; key<n_elements+1; ++key) {
        if (search_key(v, n_elements, key) != 1){
            return 0;
        }
    }
    return 1;
}

int check_rows(const unsigned sudoku[][SIZE]) {
    for (size_t i=0; i<SIZE; ++i) {
        if (basic_search(sudoku[i], SIZE) != 1){
            // This row does not comply with the rules :
            return 0;
        }
    }
    // If all the rows comply with the rules : return 1
    return 1;
}

int check_cols(const unsigned sudoku[][SIZE]) {
    for (size_t i = 0; i < SIZE; ++i) {  // 'i' is the column index
        unsigned col_values[SIZE];  // Temporary array to store the column's values
        // Collect the values from the column i :
        for (size_t j = 0; j < SIZE; ++j) {
            col_values[j] = sudoku[j][i];  // Get the value from row 'j' of column 'i'
        }
        // Now, check if this column complies with the rules
        if (basic_search(col_values, SIZE) != 1) {
            // If the column does not comply with the rules, return 0
            return 0;
        }
    }
    // If all columns comply with the rules, return 1
    return 1;
}

int check_regions(const unsigned sudoku[][SIZE]) {
    for (size_t row_start=0; row_start<SIZE; row_start+=3) { // 'row_start' is the row index : we need 0, 3, 6
        unsigned region[SIZE]; // A sudoku region is 3x3, but we convert it to a 1x9 array
        for (size_t col_start=0; col_start<SIZE; col_start+=3) { // 'col_start' is the column index : we need 0, 3, 6
            // Extract the 3x3 region :
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    region[3*i+j] = sudoku[row_start + i][col_start + j];
                }
            }
            // Check if the current region complies with the rules or not :
            if (basic_search(region, SIZE) != 1) {
                return 0; // If not, return 0
            }
        }
    }
    return 1; // If all the 9 3x3 regions comply with the rules : return 1
}
//

int check_sudoku(const unsigned sudoku[][SIZE])
{
    cout << "Is this sudoku grid correct ?" << endl;
    /*
    * YOUR CODE GOES HERE
    */
    if (check_rows(sudoku) != 1) {
        return -1;
    }
    else if (check_cols(sudoku) != 1) {
        return -2;
    }
    else if (check_regions(sudoku) != 1) {
        return -3;
    }
    else {
        return 1;
    }
}

void generate_sudoku(unsigned sudoku[][SIZE])
{
    int x = 0;
    for (size_t i=1; i<=3; ++i)
    {
        for (size_t j=1; j<=3; ++j)
        {
            for (size_t k=1; k<=SIZE; ++k)
            {
                sudoku[3*(i-1)+j-1][k-1] = (x % SIZE) + 1;
                x++;
            }
            x += 3;
        }
        x++;
    }
}

void display_sudoku(const unsigned sudoku[SIZE][SIZE]) {
    for (size_t i = 0; i < SIZE; ++i) {
        for (size_t j = 0; j < SIZE; ++j) {
            std::cout << sudoku[i][j] << " ";  // Print each element with a space
        }
        std::cout << std::endl;  // Move to the next line after each row
    }
}