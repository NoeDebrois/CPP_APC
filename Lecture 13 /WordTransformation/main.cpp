#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

// Example 2 : a word transformation map.
// Write a program that given one string, transforms it into another one.
// The input to our program is two files :
// The FIRST file contains rules that we will use to transform the text in the SECOND file.
// Each rule consists of a word that might be in the input file and a phrase to use in its place.

// Typedef :
typedef std::map<std::string, std::string> dictionary_type; // Because it's very long to type !
// std::map<std::string, std::string> is like a dictionary in Python.

// Definition of the three functions that we implement :
void word_transform (std::ifstream& map_file, std::ifstream& content_file);
dictionary_type buildMap (std::ifstream& ifs);
std::string transform (const std::string& s, const dictionary_type& dictionary);

// Main :
int main() {
  std::ifstream map_file("../map_file.txt");
  std::ifstream content_file("../content_file.txt");

  word_transform(map_file, content_file);

  return 0;
}

// Functions :
// map_file contains the rules used to transform the text. content_file is the text to transform.
void word_transform (std::ifstream& map_file, std::ifstream& content_file)
{
  dictionary_type dictionary = buildMap(map_file); // cf top of the file :
  // "dictionary_type" means "std::map<std::string, std::string>" (typedef).

  std::string line;
  while (getline(content_file, line)) // Read each line and put the content in line.
  {
    std::istringstream iss(line);

    std::string word;
    while (getline(iss, word, ' ')) // Read each line and separate each word in it.
      std::cout << transform(word, dictionary) << " "; // Transforms word by word using rules.
    std::cout << std::endl;
  }
}

// Reads the file "map_file.txt" : we know it contains key (space) value. So we can use ifs >> key >> value.
dictionary_type buildMap (std::ifstream& ifs)
{
  dictionary_type dictionary; // cf the typedef on top of the file.

  std::string key, value;
  while(ifs >> key >> value) // We read each key - value couple.
    dictionary[key] = value; // We put it into the dictionary.

  return dictionary;
}

// Takes a word -> looks in the dictionary for a potential transformation -> returns either the
// initial word, or the new transformed word.
std::string transform (const std::string& s, const dictionary_type& dictionary)
{
  std::string new_s = s;

  dictionary_type::const_iterator it = dictionary.find(s);
  if (it != dictionary.cend())
    new_s = it->second;

  return new_s;
}
