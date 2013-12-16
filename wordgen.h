#include "lexicon.h"
#include <vector>

//Return whether or not given string is a valid pattern.
bool IsValidPattern(std::string& pattern);
std::string GetPatternFromUser(); //Get a pattern from user input.

//Return a vector of strings that match the given pattern
std::vector<std::string> GetStringsByPattern(Lexicon& lex, std::string& pattern);

void PrintMatches(std::vector<std::string>& matches, int numCols);
