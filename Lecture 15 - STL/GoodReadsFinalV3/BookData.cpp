//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "BookData.h"

using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::list;


BookData::BookData(unsigned pagesNumber, const string &pub, const string &author) :
pages_number(pagesNumber), publisher(pub), author(author) {
    ratings_distr= vector<unsigned>(5,0);
    review_count =0;
    avg_rating =0.0;

}

float BookData::get_avg_rating() const {
    return avg_rating;
}

void BookData::add_review(unsigned int index, unsigned int stars) {
    review_indexes.push_back(index);
    ratings_distr[stars-1]++;
    review_count++;
    avg_rating = compute_rating();
}

float BookData::compute_rating() {
    float average = 0;

    for (size_t i=0; i< ratings_distr.size(); ++i)
        average += (i+1)* ratings_distr[i];

    return average/review_count;
}

string BookData::to_string() const {

    return author + " " + publisher + " " + std::to_string(pages_number) + " " +
           std::to_string(review_count) + " " + std::to_string(avg_rating);

}

list<unsigned> BookData::get_review_indexes() const {
    return review_indexes;
}
