//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "Review.h"

using std::set;
using std::vector;
using std::string;


Review::Review(const string &bookTitle, const string &t, unsigned int r) :
                book_title(bookTitle), text(t), rating(r)  {
    const vector<string> text_strings(split(t, ' '));
    words =  set<string>(text_strings.cbegin(),text_strings.cend());
}

string  Review::to_string() const {

    return book_title + " " + text + " " +  std::to_string(rating);
}

string  Review::get_text() const {
    return text;
}

set<string> Review::get_words() const {
    return words;
}

vector<string> split(const string &s, char d){
    string word;
    std::vector<string> v;
    std::istringstream text_read (s);
    while (std::getline (text_read, word, d))
    v.push_back (word);
    return v;
}
