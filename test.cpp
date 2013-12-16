#include "lexicon.h"
#include <string>
#include <iostream>

int main(int argc, char **argv){
  std::string file = "words.txt";
  Lexicon lex(file); //Create a new lexicon
  while (true) {
    std::cout << "Enter word to search for: ";
    std::string word;
    std::getline(std::cin, word);
    std::cout << "Contains " << word << "?: " << (lex.ContainsWord(word) ? "Yes" : "No") << std::endl;
  }
  return 0;
}
