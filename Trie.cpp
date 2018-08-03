#include "Trie.hpp"

Trie::~Trie()
{
    for (int i=0; i<children.size(); ++i)
        delete children[i];
}

void Trie::insert(int number[X][X])
{
    map<int, TrieNode*> *current_tree = &head.children;
    map<int, TrieNode*>::iterator it;
    
    for (int i = 0; i< X; i++)
    {
        for (int j = 0; j< X; j++)
        {
            int ch = number[i][j];
            if ((it = current_tree->find(ch)) != current_tree->end())
            {
                current_tree = &it->second->children;
                continue;
            }
            
            if (it == current_tree->end())
            {
                TrieNode* new_node = new TrieNode();
                new_node->ch = ch;
                (*current_tree)[ch] = new_node;
                current_tree = &new_node->children;
                children.push_back(new_node);
            }
        }
    }
}

bool Trie::search(int number[X][X])
{
    map<int, TrieNode*> current_tree = head.children;
    map<int, TrieNode*>::iterator it;
    
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < X; j++)
        {
            if ((it = current_tree.find(number[i][j])) == current_tree.end())
                return false;
            current_tree = it->second->children;
        }
    }
    return true;
}

void Trie::print_tree(map<int, TrieNode*> tree)
{
    if (tree.empty())
        return;
    
    for (map<int, TrieNode*>::iterator it=tree.begin(); it!=tree.end(); ++it)
    {
        cout << it->first << endl;
        print_tree(it->second->children);
    }
}

void Trie::print()
{
    map<int, TrieNode*> current_tree = head.children;
    print_tree(current_tree);
}
