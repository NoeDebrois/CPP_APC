//
// Created by Danilo Ardagna on 13/07/2020.
//

#ifndef GOODREADS_GOODREADS_H
#define GOODREADS_GOODREADS_H


#include <string>
#include <vector>
#include <iostream>


#include "Book.h"
#include "Review.h"


class GoodReads {
public:
    typedef std::vector<Book>::const_iterator const_books_it;
    typedef std::vector<Book>::iterator books_it;

private:
    std::vector<Book> books; // <title, Book>
    std::vector<Review> reviews;

public:
    void add_book(const std::string& title, unsigned pagesNumber, const std::string& publisher,
                  const std::string& author);
    void add_review(const std::string& bookTitle, const std::string& text, unsigned int rating);

    float get_avg_rating() const;
    float get_avg_rating(const std::string& title) const;

    void search_reviews(const std::vector<std::string>& keywords) const;
    void print_book(const std::string& title) const;

private:

    // return the iterator of the book with a given title in books, books.cend() otherwise
    const_books_it find_book(const std::string& title) const;

    // return the iterator of the book with a given title in books, books.end() otherwise
    books_it  find_book(const std::string& title);

    // return true iff all keywords are included in words
    bool includes_all(const std::vector<std::string>& words, const std::vector<std::string>& keywords) const;

    // return true iff k is included in words
    bool includes_word(const std::vector<std::string>& words, const std::string& k) const;
};



#endif //GOODREADS_GOODREADS_H
