//
// Created by Noé Debrois on 08/12/2024.
//

// Include the header file defining the FileManager class
#include "FileManager.h"

// Importing standard library components to avoid prefixing them with std::
using std::cerr;            // Standard error output stream
using std::endl;            // Line break for standard output
using std::string;          // String type
using std::ifstream;        // Input file stream class
using std::istringstream;   // String stream for parsing strings

// Method to parse a file and store its contents as a table (a vector of rows)
// - `filename`: The name of the file to be parsed
// - `d`: The delimiter used to split elements in each row (e.g., ',' or '\t')
// Returns a reference to the internal `fields` table containing the parsed data
const FileManager::table_type &FileManager::parse_file(const std::string &filename, char d) {
    // Clear any previously stored data in the table
    fields.clear();

    // Open the file using an input file stream
    ifstream ifs(filename);

    // Check if the file opened successfully
    if (ifs) {
        string line;
        // Read the file line by line
        while (getline(ifs, line)) {
            row_type row;              // Temporary storage for a single row
            istringstream iss(line);   // Create a string stream to parse the line
            string elem;               // Temporary storage for an element in the row

            // Split the line into elements based on the delimiter `d`
            while (getline(iss, elem, d))
                row.push_back(elem);   // Add each element to the current row

            // Add the parsed row to the `fields` table
            fields.push_back(row);
        }
    } else {
        // If the file cannot be opened, output an error message
        cerr << "Unable to open file " << filename << endl;
    }

    // Return a reference to the parsed table
    return fields;
}
