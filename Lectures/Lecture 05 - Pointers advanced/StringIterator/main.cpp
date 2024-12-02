#include <iostream>
#include <string>

int main() {
    std::string s("some string");

    // till the character is not the last character of the string AND we didn't reach a space :
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // capitalize the current character
    std::cout << s << std::endl;

    return 0;
}
