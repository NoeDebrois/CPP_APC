//
// Created by Danilo Ardagna on 13/07/2020.
//

#ifndef GOODREADS_BOOKDATA_H
#define GOODREADS_BOOKDATA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>




class BookData {
    std::vector<unsigned> ratings_distr;
    unsigned pages_number;
    std::string publisher;
    unsigned review_count;
    std::string author;
    float avg_rating;
    std::list<unsigned> review_indexes;
public:
    BookData(unsigned int pagesNumber, const std::string &publisher, const std::string &author);
    float get_avg_rating() const;
    void add_review(unsigned index, unsigned stars);
    std::string to_string() const;
    std::list<unsigned> get_review_indexes()const ;
private:
    float compute_rating();
};


#endif //GOODREADS_BOOKDATA_H
