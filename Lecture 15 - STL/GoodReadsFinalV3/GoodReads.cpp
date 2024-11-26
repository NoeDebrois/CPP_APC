//
// Created by Danilo Ardagna on 13/07/2020.
//

#include "GoodReads.h"

using std::map;
using std::set;
using std::string;
using std::vector;

using std::cout;
using std::cerr;
using std::endl;


void GoodReads::add_book(const string &title, unsigned int pages_number, const string &publisher, const string &author) {
    BookData bd(pages_number, publisher, author);
    if (books.find(title) == books.cend())// the book is not already in the collection
        books.insert(std::make_pair(title, bd));
    else
        cerr << "The book is already in the books collection" <<endl;
}

void GoodReads::add_review(const string &book_title, const string &text, unsigned int rating) {
    const auto it = books.find(book_title);
    if (it == books.cend())// the book is not in the collection
        cerr << "The book is not in the books collection" <<endl;
    else{
        Review r(book_title,text,rating);
        reviews.push_back(r);
        it->second.add_review(reviews.size()-1,rating);
    }
}

float GoodReads::get_avg_rating() const {
    float avg= 0;
    size_t count = 0;
    for (auto it = books.cbegin(); it != books.cend(); ++it){
        avg += it->second.get_avg_rating();
        count++;
    }

    return avg/count;
}

float GoodReads::get_avg_rating(const string & title) const {
    const auto it = books.find(title);
    if (it == books.cend()){// the book is not in the collection
        cerr << "The book is not in the books collection" <<endl;
        return 0;
    }
    else
        return it->second.get_avg_rating();
}

void GoodReads::search_reviews(const vector<string> & keywords) const {
    const set<string> keywords_set(keywords.cbegin(),keywords.cend());
    for (auto it = reviews.cbegin(); it != reviews.cend(); ++it){
        const set<string> & words = it->get_words();
        if(std::includes(words.cbegin(), words.cend(), keywords_set.cbegin(), keywords_set.cend()) )
            cout << it->to_string()<<endl;
    }

}

void GoodReads::print_book(const string &title) const {
    const auto it = books.find(title);
        if (it == books.cend())// the book is not in the collection
            cerr << "The book is not in the books collection" <<endl;
        else{
        // print book data
        cout << it->first<<endl;
        cout << it->second.to_string()<<endl;
        auto rev_list = it->second.get_review_indexes();
        auto rev_it = rev_list.cbegin();
        while ( rev_it != rev_list.cend()){
            cout << reviews[*rev_it].to_string() << endl;
            rev_it++;
        }
    }
}
