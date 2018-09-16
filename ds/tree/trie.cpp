#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**********************************************
    字典树(Trie)
**********************************************/
typedef struct _Trie
{
    bool exist; // 1.路径上存在的字母不一定组成单词 2.删除单词时直接改标记不破坏结构 
    _Trie *child[26];
    _Trie()
    {
        this->exist = false;
        for(int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
}Trie;

Trie *Insert(Trie *t, char *word)
{
    if(NULL == t)
        t = new Trie;

    Trie *curr = t;
    for(int i = 0; i < strlen(word); i++)
    {
        int c = word[i] - 'a';
        if(NULL == curr->child[c])
            curr->child[c] = new Trie;
        curr = curr->child[c];
    }
    curr->exist = true;
    return t;
}

bool Search(Trie *t, char *word)
{
    if(NULL == t)
        return false;
    
    Trie *curr = t;
    for(int i = 0; i < strlen(word); i++)
    {
        int c = word[i] - 'a';
        if(NULL == curr->child[c])
            return false;
        curr = curr->child[c];
    }
    return curr->exist;    
}

int main()
{
    Trie *t = NULL;

    t = Insert(t, "abc");
    t = Insert(t, "abcd");
    t = Insert(t, "abd");

    cout<<"trie search: "<<Search(t, "ab")<<endl;
    cout<<"trie search: "<<Search(t, "abc")<<endl;

    return 0;
}