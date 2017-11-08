#include <iostream>

using namespace std;

typedef struct _Node
{
	int val;
	_Node *next;
	_Node(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}Node;
Node *sp = NULL;
void push(Node *sp, int val)
{
	Node *node = new Node(val);
	if(sp == NULL)
		sp = node;
	else
	{
		node->next = sp;
		sp = node;
	}
}

int main()
{
	sp = push(4);

	cout<<sp<<endl;

	return 0;
}