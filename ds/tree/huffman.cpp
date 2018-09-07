#include <bits/stdc++.h>

using namespace std;

#define SIZE (100)
#define Len(x)      sizeof(x)/sizeof(x[0])  
#define INSIDE ('#')

typedef struct _Node
{
	char c;
	int fq;
	_Node *left, *right;
	_Node(char c, int fq)
	{
		this->c = c;
		this->fq = fq;
		left = right = NULL;
	}
}Node;

typedef struct _MinHeap
{
	int cnt;
	Node *buf[SIZE];
	_MinHeap()	{ cnt = 0; }
	void push(Node *n)
	{
		int i = cnt++;
		for(; i && buf[(i-1)/2]->fq > n->fq; i /= 2)
			buf[i] = buf[(i-1)/2];
		buf[i] = n;
	}
	Node *pop()
	{
		Node *ret = buf[0];
		Node *last = buf[--cnt];
		int i = 0, child, smallest = 0;
		for(; i <= cnt; i = child)
		{
			child = 2*i+1;
			if(child+1 < cnt && buf[child+1]->fq < buf[child]->fq)
				child++;
			if(child < cnt && buf[child]->fq < last->fq)
				buf[i] = buf[child];
			else
				break;
		}
		buf[i] = last;

		return ret;
	}
}MinHeap;

void HuffmanPrint(Node *n, string str)
{
	if(NULL == n)
		return;
	if(INSIDE != n->c)
		cout<<n->c<<" = "<<str<<endl;
	HuffmanPrint(n->left, str+"0");
	HuffmanPrint(n->right, str+"1");
}

void HuffmanCodes(char a[], int fq[], int n)
{
	MinHeap *mp = new MinHeap;
	for(int i = 0; i < n; i++)
		mp->push(new Node(a[i], fq[i]));
	
	while(mp->cnt > 1)
	{
		Node *left = mp->pop();
		Node *right = mp->pop();
		Node *curr = new Node(INSIDE, left->fq + right->fq);
		
		curr->left = left;
		curr->right = right;
		mp->push(curr);
	}

	HuffmanPrint(mp->pop(), "");
}

int main()
{
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    HuffmanCodes(a, freq, Len(a));
	return 0;
}