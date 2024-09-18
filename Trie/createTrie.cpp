#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;

    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    void insertUtil(TrieNode *node, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
        }
        // asuming word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
};
int main()
{
}