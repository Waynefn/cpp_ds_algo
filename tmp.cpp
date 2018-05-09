#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

typedef struct _TrieNode
{
	bool exist;
	_TrieNode *child[26];
	_TrieNode()
	{
		this->exist = false;
		for(int i = 0;  i < 26; i++)
			this->child[i] = NULL;
	}
}TrieNode;

TrieNode *Insert(TrieNode *t, string word)
{
	if(NULL == t)
		t = new TrieNode;

	TrieNode *tmp = t;
	for(int i = 0; i < word.length(); i++)
	{
		int c = word[i] - 'a';
		if(NULL == tmp->child[c])
			tmp->child[c] = new TrieNode;
		tmp = tmp->child[c];
	}
	tmp->exist = true;
	return t;
}

bool Search(TrieNode *t, string word)
{
	TrieNode *tmp = t;
	for(int i = 0; i < word.length(); i++)
	{
		int c = word[i] - 'a';
		if(NULL == tmp->child[c])
			return false;
		tmp = tmp->child[c];
	}
	return tmp->exist;
}

int main()
{
	TrieNode *root = NULL;
	root = Insert(root, "hello");
	root = Insert(root, "haha");

	cout<<Search(root, "hah")<<endl;

	return 0;
}