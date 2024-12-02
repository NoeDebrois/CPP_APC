//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "GoodReads.h"

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

void GoodReads::add_book(const string &title, unsigned int pages_number, const string &publisher,
                         const string &author) {

    Book bd(pages_number, publisher, author, title);

    auto it = find_book(title);

    if (it == books.cend()) // the book is not already in the collection
        books.push_back(bd);
    else
        cerr << "The book is already in the books collection" <<endl;
}

void GoodReads::add_review(const string &book_title, const string &text, unsigned int rating) {

    const auto it = find_book(book_title);

    if (it == books.cend()) // the book is not in the collection
        cerr << "The book is not in the books collection" <<endl;
    else{
        Review r(book_title, text, rating);
        reviews.push_back(r);
        it->add_review(reviews.size()-1, rating);
    }
}

float GoodReads::get_avg_rating() const {

    float avg= 0;
    size_t count = 0;
    for (auto it = books.cbegin(); it != books.cend(); ++it){
        avg += it->get_avg_rating();
        count++;
    }

    return avg/count;
}

float GoodReads::get_avg_rating(const string & title) const {

    const auto it = find_book(title);
    if (it == books.cend()){ // the book is not in the collection
        cerr << "The book is not in the books collection" <<endl;
        return 0;
    }
    else
        return it->get_avg_rating();
}

void GoodReads::search_reviews(const vector<string> & keywords) const {

    for (auto it = reviews.cbegin(); it != reviews.cend(); ++it){
        const vector<string>& words = it->get_words();
        if(includes_all(words, keywords))
            cout << it->to_string() << endl;
    }
}

void GoodReads::print_book(const string &title) const {
    const auto it = find_book(title);
    if (it == books.cend())// the book is not in the collection
        cerr << "The book is not in the books collection" <<endl;
    else{
        // print book data
        cout << it->to_string()<<endl;
        auto rev_list = it->get_review_indexes();
        auto rev_it = rev_list.cbegin();
        while ( rev_it != rev_list.cend()){
            cout << reviews[*rev_it].to_string() << endl;
            rev_it++;
        }
    }
}

// return true iff all keywords are included in words
bool GoodReads::includes_all(const vector<string>& words, const vector<string>& keywords) const {

    for (const string& k : keywords)
        if (!includes_word(words,k))
            return false;

    return true;
}

// return true iff k is included in words
bool GoodReads::includes_word (const vector<string>& words, const string& k) const {

    for (const string& w : words)
        if (w == k)
            return true;

    return false;
}

GoodReads::const_books_it GoodReads::find_book(const string& title) const {

    for (const_books_it it = books.cbegin(); it != books.cend(); ++it)
        if (it->get_title() == title)
            return it;

    return books.cend();
}


GoodReads::books_it GoodReads::find_book(const string& title) {

    for (books_it it = books.begin(); it != books.end(); ++it)
        if (it->get_title() == title)
            return it;

    return books.end();
}
