#include <vector>  //Include vector

#define NUM_CHILDREN 26

//A struct representing a single node in a Directed Acyclic Word Graph (DAWG).
struct Node {
  bool isWord; //Determine if the path upto and including the current Node makes up a word.
  Node *nextLetters[NUM_CHILDREN]; //Possible next children.
};

class Lexicon {
public:
  //Constructor that takes in a the name of a wordlist file.
  Lexicon(const std::string& filename);
  bool LoadWords(const std::string& filename); //Load words into the internal representation.
  void AddWord(const std::string& word, Node *last);
  bool ContainsWord(const std::string& word);
  std::vector<std::string> MatchesForPattern(const std::string& pattern);
private:
  bool CheckPathForWord(const std::string& word, Node *last);
  std::vector<std::string> CheckPattern(const std::string& pattern, const std::string& built, Node *last);
  Node *root;
  int wordCount; //Count of words in the Lexicon.
};
