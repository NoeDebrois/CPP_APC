#include <fstream>
#include <iostream>
#include <sstream> // Required for std::istringstream
#include <vector>
#include <string>

// Example 1 : read a .csv file.

struct Data {
    // Members are all public by default (struct).
    int n1;
    int n2;
    int n3;
};

int main() {
    std::vector<Data> random_data;
    std::string line;
    std::ifstream data("../Random_Table.csv");

    if (!data.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    // Read all lines one by one
    while (getline(data, line)) {
        Data info; // Create an object to hold this record's data.
        std::istringstream record(line); // Bind record to the line we just read.

        std::string value; // Temporary string to store each value
        if (getline(record, value, ',')) {
            info.n1 = std::stoi(value); // Convert to int
        }
        if (getline(record, value, ',')) {
            info.n2 = std::stoi(value); // Convert to int
        }
        if (getline(record, value, ',')) {
            info.n3 = std::stoi(value); // Convert to int
        }

        random_data.push_back(info); // Append this record to random_data
    }

    // Output to verify
    for (const auto& record : random_data) {
        std::cout << "n1: " << record.n1
                  << ", n2: " << record.n2
                  << ", n3: " << record.n3 << std::endl;
    }

    return 0;
}
