#ifndef Trie_hpp
#define Trie_hpp

#include <iostream>
#include <map>
#include <vector>
#define X 3

using namespace std;

struct TrieNode {
    int ch;
    map<int, TrieNode*> children;
};

class Trie {
public:
    Trie() { head.ch = -1; };
    ~Trie();

    void insert(int[X][X]);
    bool search(int [X][X]);
    
    void print_tree(map<int, TrieNode*> tree);
    void print();
    
protected:
    TrieNode head;
    vector<TrieNode*> children;
};
#endif /* Trie_hpp */
