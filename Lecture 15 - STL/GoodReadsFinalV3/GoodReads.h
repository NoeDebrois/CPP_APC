//
// Created by Danilo Ardagna on 13/07/2020.
//

#ifndef GOODREADS_GOODREADS_H
#define GOODREADS_GOODREADS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "BookData.h"
#include "Review.h"


class GoodReads {
    std::map<std::string, BookData> books; // <title, BookData>
    std::vector<Review> reviews;
public:
    void add_book(const std::string & title, unsigned pagesNumber, const std::string &publisher, const std::string &author);
    void add_review(const std::string &bookTitle, const std::string &text, unsigned int rating);
    float get_avg_rating() const;
    float get_avg_rating(const std::string & title) const;
    void search_reviews(const std::vector<std::string> & keywords) const;
    void print_book(const std::string & title) const;
};


#endif //GOODREADS_GOODREADS_H
