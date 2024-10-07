#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector <string> text;

    text.push_back("Oh, Romeo, Romeo, why do you have to be Romeo?");
    text.push_back("Forget about your father and change your name.");
    text.push_back("Or else, if you won’t change your name,");
    text.push_back("just swear you love me and I’ll stop being a Capulet.");



    // Text must be sorted (here : alphabetically) :
    sort(text.begin(), text.end());

    // Print every elements, after they were sorted :
    for (auto s:text)
        cout<<s<<endl;

    // beg and end will denote the range we're searching
    auto beg = text.cbegin(), end = text.cend(); // cbegin, cend : const_iterator
    auto mid = text.cbegin() + (end - beg)/2; // original midpoint

    string s("just swear you love me and I’ll stop being a Capulet.");

    // while there are still elements to look at and we haven't yet
    // found s
    while (mid != end && *mid != s) {

        if (s < *mid)  // is the element we want in the first half?
            end = mid; // if so, adjust the range to ignore the
            // second half
        else // the element we want is in the second half
            beg = mid + 1; //start looking with the element just after mid

        mid = beg + (end - beg)/2; // new midpoint
    }

    if ( mid!= text.cend() )
        cout << "*mid: "<<*mid<<endl;

    if ( mid!= text.cend() && s == *mid )
        cout <<"Yes I found "<<s<<" in text"<<endl;
    else
        cout <<"Sorry I cannot find "<<s<<" in text"<<endl;

    return 0;
}