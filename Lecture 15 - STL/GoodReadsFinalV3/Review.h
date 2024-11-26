//
// Created by Danilo Ardagna on 13/07/2020.
//

#ifndef GOODREADS_REVIEW_H
#define GOODREADS_REVIEW_H

#include <string>
#include <set>
#include <vector>
#include <sstream>


class Review {
    std::string book_title;
    std::string text;
    unsigned rating;
    std::set<std::string> words;

public:
    Review(const std::string &bookTitle, const std::string &text, unsigned int rating);
    std::string to_string() const;

    std::string get_text() const;
    std::set<std::string> get_words() const;

};

std::vector<std::string> split(const std::string &s, char d);


#endif //GOODREADS_REVIEW_H
