#include <bits/stdc++.h>
using namespace std;



struct TrieNode
{
    TrieNode* child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


void insert(string key, TrieNode* root)
{
    TrieNode* curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(root->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

void traversal(TrieNode* root, string str, vector<string> &result)
{
    if(root->isEnd == true) 
    {
        result.push_back(str);
    }
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL)
        {
            char currStr = 'a' + i;
            traversal(root->child[i], str+currStr, result);
        }
    }
}


int main() 
{
    TrieNode* root = new TrieNode();
    vector<string> arr {"dog", "dome", "drum"};
    for(string str : arr)
    {
        insert(str, root);
    }

    vector<string> result;
    traversal(root, "", result);
    for(string str: result)
    {
        cout<<str<<"\n";
    }
    return 0;
}