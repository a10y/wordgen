#include "lexicon.h"
#include <fstream>
#include <iostream>
#include <string>

Lexicon::Lexicon(const std::string& filename){
  wordCount = 0;
  //instantiate root pointer.
  root = new Node;
  root->isWord = false;
  for (int i=0; i < NUM_CHILDREN; ++i) root->nextLetters[i] = new Node;
  //Attempt to load words from the file
  if (!LoadWords(filename)) {
    std::cerr << "Error loading filename" << std::endl;
  }
}

bool Lexicon::LoadWords(const std::string& filename){
  std::ifstream wordlist;
  wordlist.open(filename);
  if (!wordlist){
    std::cerr << "Cannot load file \"" << filename << "\"" << std::endl;
    return false;
  }
  while (true){
    if (root == NULL) std::cout << "root is NULL." << std::endl;
    std::string word;
    std::getline(wordlist, word);
    if (!wordlist) break;
    //std::cout << "Adding word " << word << std::endl;
    AddWord(word, root);
  }
  std::cout << "Added " << wordCount << " words to the lexicon." << std::endl;
  return true;
}

void Lexicon::AddWord(const std::string& word, Node *node){
  if (word == "") {
    node->isWord = true;
    ++wordCount; //Increment number of words in Lexicon.
    return; //Return when we have nothing left to add
  }
  char first = tolower(word[0]);
  //If the previous node is null, create a new node for it.
  if (node == NULL){
    //std::cout << "Setting NULL pointer to new Node" << std::endl;
    node = new Node;
    node->isWord = false;
  }
  //Now, insert the next letter of the word.
  Node *n = node->nextLetters[ first - 'a' ];
  if (n == NULL) {
    n = new Node;
  }
  node->nextLetters[first - 'a'] = n;
  //Finally, add the next letter into the DAWG.
  AddWord(word.substr(1), n);
  return;  
}

bool Lexicon::ContainsWord(const std::string& word){
  return CheckPathForWord(word, root);
}

bool Lexicon::CheckPathForWord(const std::string& word, Node *last){
  if (last == NULL) return false;
  if (word == "") return last->isWord;
  char first = tolower(word[0]);
  Node *next = last->nextLetters[ first - 'a' ];
  return CheckPathForWord(word.substr(1), next);
}
