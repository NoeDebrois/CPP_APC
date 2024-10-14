//
// Created by Danilo Ardagna on 2019-09-28.
// Modified by Noé Debrois on 2024-10-14.
//

// This is the header file for the Book class : this is where we DECLARE everything
// (all the methods).

#ifndef LIBRARYINITIALCODE_BOOK_H
#define LIBRARYINITIALCODE_BOOK_H

#include <string>
#include <iostream>

class Book {

private:
  unsigned code;
  unsigned year;
  unsigned pages;
  std::string &author;
  std::string &title;
  bool available;

public:
  // Constructor :
  Book(unsigned c, unsigned y, unsigned p, std::string & a, std::string & t):
  // Let's consider that a book, by default, is always available. That's why we don't add "bool a".
  code(c), year(y), pages(p), author(a), title(t), available(true)
  {} // We did everything we wanted so : empty constructor.

  // -- SHORTCUT --
  // To generate all the getters (which is boring!), do :
  // - right click
  // - "generate"
  // - "getters and setters"
  // - unclick "inline" : so that we declare the getters in the header file but define the getters in the source file
  //

  // All the getters :
  unsigned getCode() const;
  unsigned getYear() const;
  unsigned getPages() const;

  std::string &getAuthor() const;
  std::string &getTitle() const;
  bool getAvailable() const;

  // We only have one setter :
  void setAvailable(bool av);

  // Other methods :
  bool equalTo(const std::string& rhs_author, const std::string& rhs_title) const;
  void print() const;
};

#endif //LIBRARYINITIALCODE_BOOK_H
