//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "Book.h"

using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::list;

Book::Book(unsigned pagesNumber, const string &pub,
           const string &author, const string &title) :
           pages_number(pagesNumber), publisher(pub), author(author), title(title) {

    ratings_distr = vector<unsigned>(5,0);
    review_count = 0;
    avg_rating = 0.0;
}

float Book::get_avg_rating() const {
    return avg_rating;
}

void Book::add_review(unsigned int index, unsigned int stars) {
    review_indexes.push_back(index);
    ratings_distr[stars-1]++;
    review_count++;
    avg_rating = compute_rating();
}

float Book::compute_rating() {
    float average = 0;

    for (size_t i = 0; i < ratings_distr.size(); ++i)
        average += (i+1) * ratings_distr[i];

    return average/review_count;
}

string Book::to_string() const {

    return title + " " + author + " " + publisher + " " + std::to_string(pages_number) + " " +
           std::to_string(review_count) + " " + std::to_string(avg_rating);

}

list<unsigned> Book::get_review_indexes() const {
    return review_indexes;
}

string Book::get_title() const {
    return title;
}