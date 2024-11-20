//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "Review.h"

using std::vector;
using std::string;

Review::Review(const string& bookTitle, const string& t, unsigned int r) :
                book_title(bookTitle), text(t), rating(r)  {

    const vector<string> text_strings(split(t, ' '));
    words.push_back(text_strings[0]);
    for (size_t i = 1; i < text_strings.size(); ++i)
        if (!find_in_words(text_strings[i]))
            words.push_back(text_strings[i]);
}

string Review::to_string() const {
    return book_title + " " + text + " " +  std::to_string(rating);
}

string Review::get_text() const {
    return text;
}

vector<string> Review::get_words() const {
    return words;
}

bool Review::find_in_words(const string &w) const {

    for (const string& word: words)
        if (w == word)
            return true;

    return false;
}

vector<string> split(const string &s, char d) {

    string word;
    std::vector<string> v;
    std::istringstream text_read (s);
    while (std::getline (text_read, word, d))
    v.push_back (word);
    return v;
}
