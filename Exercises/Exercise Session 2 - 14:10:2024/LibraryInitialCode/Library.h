//
// Created by Danilo Ardagna on 2019-09-28.
// Modified by Noé Debrois on 2024-10-14.
//

#ifndef LIBRARYINITIALCODE_LIBRARY_H
#define LIBRARYINITIALCODE_LIBRARY_H

#include "Book.h"

#include <vector>
#include <iostream>

class Library {

private:
  // books;

  // Private methods already declared :

  // return the index of the book
  int find(const std::string & author, const std::string & title) const;

  // return the index of the first available book
  int find_available_book(const std::string & author, const std::string & title) const;

public:
  // Public methods already declared here :

  // add a book to the library
  void add_book(const Book & book);

  // return the book code or -1 if the book is not available
  int rent_book(const std::string & author, const std::string & title);

  // return to the library the book with the specified code.
  // Return false if the code is not found/the book is available
  // return true otherwise
  bool return_book(unsigned code);

  void print() const;

  void print_oldest() const;
};

#endif //LIBRARYINITIALCODE_LIBRARY_H
