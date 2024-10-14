//
// Created by Danilo Ardagna on 2019-09-28.
// Modified by Noé Debrois on 2024-10-14.
//

// This is the source file for the Book class : this is where we DEFINE everything
// (all the methods).

#include "Book.h"

// Getters :
// - "Book::" means that we are in the Book class.
unsigned Book::getCode() const {
    return code;
}

unsigned Book::getYear() const {
    return year;
}

unsigned Book::getPages() const {
    return pages;
}

std::string &Book::getAuthor() const {
    return author;
}

std::string &Book::getTitle() const {
    return title;
}

bool Book::getAvailable() const {
    return available;
}

// Setter (only one) :
void Book::setAvailable(bool av) {
    available = av;
}

// Other methods :
bool Book::equalTo(const std::string& rhs_author, const std::string& rhs_title) const {
    return (author == rhs_author && title == rhs_title);
}

void Book::print() const {
    std::cout << code << "\n"
    << author << "\n"
    << title << "\n"
    << pages << "\n"
    << year << "\n";

    if (available) {
        std::cout << "Available";
    } else {
        std::cout << "Not available";
        std::cout << std::endl;
    }
}