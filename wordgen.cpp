#include "wordgen.h"
#include <iostream>

std::string GetPatternFromUser(){
  std::string pattern;
  while (true){
    //Prompt the user for a pattern
    std::cout << "Enter pattern: ";
    std::getline(std::cin, pattern);
    if (!IsValidPattern(pattern))
      std::cerr << "Invalid pattern entered !" << std::endl;
    else break;
  }
  return pattern;
}

bool IsValidPattern(std::string& pattern){
  for (size_t i=0; i < pattern.size(); ++i){
    if ((tolower(pattern[i]) <= 'z' && tolower(pattern[i]) >= 'a') 
	|| pattern[i] == '-') continue;
    std::cout << tolower(pattern[i]) << " is invalid" << std::endl;
    return false;
  }
  return true;
}

std::vector<std::string> GetStringsByPattern(Lexicon& lex, std::string& pattern){
  //Vector of strings that match the pattern.
  std::vector<std::string> matches = lex.MatchesForPattern(pattern);
  //Stuff goes here.
  return matches; //Return the vector.
}

void PrintMatches(std::vector<std::string>& matches, int numCols){
  for (size_t i=0; i < matches.size(); ++i){
    if (i%numCols == 0) std::cout << std::endl;
    std::cout << "\t" << matches[i];
  }    
  std::cout << std::endl;
}

int main(int argc, char **argv){
  Lexicon lex("words.txt"); //Create a lexicon from local wordlist file.
  int numCols = 10; //Default number of output columns
  if (argc > 1){
    numCols = atoi(argv[1]);
  }
  while (true){
    std::string pattern = GetPatternFromUser(); //Get pattern from user input.
    
    std::cout << "Checking pattern \"" << pattern << "\" in lexicon..." << std::endl;
    std::vector<std::string> strings = GetStringsByPattern(lex, pattern);
    std::cout << "Found " << strings.size() << " strings matching the pattern \"" << pattern << "\":" << std::endl;
    PrintMatches(strings, numCols);
  }
}
