#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>

class Document {

private:
    std::string text = "";
    std::size_t id = 0;

public:
    Document () = default;
    Document (const std::string& text, std::size_t id): text(text), id(id) {}

    const std::string& getText () const;
    std::size_t getId () const;

    void print () const;
};

#endif /* DOCUMENT_H */