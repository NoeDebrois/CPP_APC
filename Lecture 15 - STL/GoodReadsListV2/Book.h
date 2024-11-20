//
// Created by Danilo Ardagna on 13/07/2020.
//

#ifndef GOODREADS_BOOK_H
#define GOODREADS_BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <list>


class Book {
    std::vector<unsigned> ratings_distr;
    unsigned pages_number;
    std::string publisher;
    unsigned review_count;
    std::string author;
    std::string title;
    float avg_rating;
    std::list<unsigned> review_indexes;
    
public:
    Book(unsigned int pagesNumber, const std::string &publisher, const std::string &author, const std::string &title);
    float get_avg_rating() const;
    void add_review(unsigned index, unsigned stars);
    std::string to_string() const;
    std::list<unsigned> get_review_indexes() const ;

    std::string get_title() const;

private:
    float compute_rating();
};


#endif //GOODREADS_BOOK_H
