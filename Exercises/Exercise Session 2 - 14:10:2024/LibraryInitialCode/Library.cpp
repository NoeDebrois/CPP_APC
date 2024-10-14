//
// Created by Danilo Ardagna on 2019-09-28.
// Modified by Noé Debrois on 2024-10-14.
//

#include "Library.h"

/* YOUR CODE GOES HERE */
// WARNING : again, we should put "Library::" before the name of the method, to tell in which
// class we are working in.
int Library::find(const std::string & author, const std::string & title) const {
    int return_idx = -1; // we initialise it to -1 in case we don't find it.

    // Books are not sorted so the only way to check if we have it is to loop over all the books :
    for (size_t i = 0; i < books.size() && return_idx == -1; i++) {
        if (books[i].equalTo(author, title)) {
            return_idx = i; // We found the book : we return its index.
        }
    }
    return return_idx;
}

int Library::find_available_book(const std::string & author, const std::string & title) {
    // It's the same as in find() method, but you also have to check that the book is available !
    int return_idx = -1; // we initialise it to -1 in case we don't find it.

    // Books are not sorted so the only way to check if we have it is to loop over all the books :
    for (size_t i = 0; i < books.size() && return_idx == -1; i++) {
        if (books[i].equalTo(author, title) && books[i].isAvailable()) {
            return_idx = i; // We found the book : we return its index.
        }
    }
    return return_idx;
}

void Library::add_book(const Book & book) {
    books.push_back(book);
}

int Library::rent_book(const std::string & author, const std::string & title) {
    int return_code = -1;
    int book_idx = find_available_book(author, title);

    if (book_idx == -1) { // It's not available
        std::cerr << "Book not available" << std::endl;
    }
    else { // It's available
        return_code = books[book_idx].getCode(); // Get the code
        books[book_idx].setAvailable(false); // Change the book availability to false
    }
    return return_code;
}

bool return_book(unsigned code) {
    bool book_returned = false;
    int book_idx = find_by_code(code);
    if (book_idx = -1) {
        std::cerr << "Book not found" << std::endl;
    }
    else {
        if (books[book_idx].isAvailable != -1) {
            std::cerr << "Book already available" << std::endl;
        }
        else {
            // We have to set the book available, i.e, return the book
            books[book_idx].setAvailable(true);
            book_returned = true;
        }
    }
}

