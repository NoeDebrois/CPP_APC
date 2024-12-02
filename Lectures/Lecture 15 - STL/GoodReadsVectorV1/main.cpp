#include <iostream>
#include "Review.h"
#include "GoodReads.h"

using std::cout;
using std::endl;

int main() {

    GoodReads data;
    /*
    Review r1("Harry Potter", "Great wonderful", 5);
    Review r2("Harry Potter", "No words amazing", 5);
    cout << r1.to_string() << endl;
    cout << r2.to_string() << endl;

    */

    data.add_book("Harry Potter", 400, "Pub", "J. K. Rowling");
    data.add_book("Harry Potter", 400, "Pub", "J. K. Rowling");

    data.add_review("Harry Potter", "Great wonderful", 5);
    data.add_review("Harry Potter", "No words amazing", 4);
    data.print_book("Harry Potter");

    data.add_book("C++ Primer", 800, "Pub 2", "S. Lippman");
    data.add_review("C++ Primer", "Very interesting book Great", 3);
    data.print_book("C++ Primer");
    data.print_book("C+ Primer");


    cout << "Good reads average rating ";
    cout << data.get_avg_rating() << endl;
    cout << "Searching Great" <<endl;
    data.search_reviews({"Great"});
    cout << "Searching Great, wonderful" <<endl;
    data.search_reviews({"Great", "wonderful"});
    cout << "Searching point" <<endl;
    data.search_reviews({"point"});

    return 0;
}
