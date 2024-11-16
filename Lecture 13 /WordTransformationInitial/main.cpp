#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

typedef std::map<std::string, std::string> dictionary_type;

void word_transform (std::ifstream& map_file, std::ifstream& content_file);
dictionary_type buildMap (std::ifstream& ifs);
std::string transform (const std::string& s, const dictionary_type& dictionary);

int main() {
  std::ifstream map_file("../map_file.txt");
  std::ifstream content_file("../content_file.txt");

  word_transform(map_file, content_file);

  return 0;
}
