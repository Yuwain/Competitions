/* Problem: Given a dictionary of m words followed by n sentences, determine 
            whether spaces can be added to each sentence such that all words
            created appear in the given dictionary. ie, determine whether it
            is possible to create the sentence with some permutation of only
            words found in the dictionary.                                    
   Example: dictionary - this, is, a, string
            thisis     - valid
            thisisais  - valid
            thisaisthi - invalid
            stringg    - invalid                                            */
#include <vector>
#include <iostream>

using namespace std;

struct Node {
  char data;
  bool ends_word;
  vector<Node*> children;

  Node() : data(' '), ends_word(false) {}
  Node(char c) : data(c), ends_word(false) {}

  void setWord() {
    ends_word = true;
  }

  /* Checks if a given letter is a child of the current node 
     Input:   c - the character to check
     Output:  a pointer to the child node if found
              NULL otherwise                                */
  Node* findChild(char c) {
    for (auto s = children.begin(); s != children.end(); ++s) {
      if ((*s)->data == c) {
        return *s;
      }
    }
    return NULL;
  }

  void addChild(Node* child) {
    children.push_back(child);
  }
};

struct Trie {
  Node* root;

  Trie() : root(new Node()) {}
  
  /* Adds a given string to the trie 
     Input: s - the string to add to the trie */
  void addWord(string s) {
    Node* curr = root;
    for (auto c : s) {
      if (curr->findChild(c)) {
        curr = curr->findChild(c);
      } else {
        Node* temp = new Node(c);
        curr->addChild(temp);
        curr = temp;
      }
    }
    curr->setWord();
  }
  
  /* Searches for a specific word in the trie 
     Input:   s - the string to search for
     Output:  a pointer to the node if found 
              NULL otherwise                  */
  Node* findWord(string s) {
    Node* curr = root;
    for (auto b = s.begin(); b != s.end(); ++b) {
      if (!curr->findChild(*b)) {
        break;
      } else {
        curr = curr->findChild(*b);
      }

      if (next(b) == s.end() && curr->ends_word) {
        return curr;
      }
    }
    
    return NULL;
  }

};

/* Checks to see if a given string can be made from words in the trie
   Input:   trie - the trie to use as a dictionary
            word - the string we're comparing to the words in the trie
   Output:  1 if the word can be made from the words in the trie
            0 otherwise                                               */
int isValid(Trie& trie, string word) {
  Node* curr = trie.root;

  if (word.size() == 0) {
    return 1;
  }

  for (auto b = word.begin(); b != word.end(); ++b) {
    if (curr->findChild(*b)) {
      curr = curr->findChild(*b);
      if (curr->ends_word && isValid(trie, string(next(b), word.end()))) {
          return 1;
      }
    } else {
      return 0;
    }
  }

  return 0;
}

int main() {
  Trie trie;

  int n;
  string word;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    trie.addWord(word);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    cout << isValid(trie, word) << endl;
  }

  return 0;
}
