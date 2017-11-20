/*
http://www.cs.tsukuba.ac.jp/admission/29-2.pdf
	情报1
		离散数学逻辑
	情报2
		问题1->Trie树
		问题2->数组实现动态buffer
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/***************************************
情报2
	问题1->Trie树
		n个节点的树中,长度为k的字符串的搜索时间复杂度:
			O(k),因为每一个字符k[i]直接通过下标随机访问确认存在or不存在,k次搜索即可完成
	问题2->数组实现字符串buffer
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _node
{
	int isEnd;
	int val;
	_node *c[26];
}node;

node *new_node()
{
	int i;
	node *n = new node;

	for(i = 0; i < 26; i++)
		n->c[i] = NULL;

	n->isEnd = false;
	return n;
}

void insert(node *root, char *key, int val)
{
	int l;
	int len = strlen(key);
	node *n = root;

	for(l = 0; l < len; l++)
	{
		int i = key[l] - 'a';
		if(n->c[i] == NULL)		// coding
			n->c[i] = new_node();
		n = n->c[i];			// coding
	}
	n->isEnd = true;			// coding
	n->val = val;				// coding
}

int search(node *root, char *key)
{
	int l;
	int len = strlen(key);
	node *n = root;

	for(l = 0; l < len; l++)
	{
		int i = key[l] - 'a';

		if(n->c[i] == NULL)
			return -1;

		n = n->c[i];			// coding
	}
	if(n->isEnd)				// coding fixed bug:节点一定不为NULL，此时判断isEnd来决定返回值
		return n->val;	
	else
		return -1;
}

void test_trie()
{
	char s1[] = {"mile"};
	char s2[] = {"milk"};

	node *root = new_node();
	insert(root, s1, 20);
	insert(root, s2, 15);
	cout<<search(root, s1)<<endl;;
}

/*************************************************/

#define BUFSIZE (10)

typedef struct
{
	int head, tail;
	char store[BUFSIZE];
}buffer;

void print_array(char a[], char n)
{
	for(char i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int put_str(buffer *buf, char *str)
{
	int i = buf->tail;

	while(i - buf->head < BUFSIZE)
	{
		buf->store[i++ % BUFSIZE] = *str;
		if(*str == '\0')
		{
			buf->tail = i;
			return 1;
		}
		else
			str++;
	}

	return 0;
}

int get_str(buffer *buf, char dest[])
{
	int i = buf->head;
	int j = 0;

	if(i == buf->tail)						// coding
		return 0;

	do{
		dest[j] = buf->store[i++ % BUFSIZE];	// coding
	}while(dest[j++] != '\0');					// coding

	buf->head = i;							// coding

	return 1;
}

void test_str_buffer()
{
	buffer *buf = new buffer;
	char res[BUFSIZE] = {""};

	cout<<put_str(buf, "a")<<endl;
	cout<<put_str(buf, "b")<<endl;
	cout<<put_str(buf, "c")<<endl;
	cout<<put_str(buf, "d")<<endl;
	cout<<put_str(buf, "e")<<endl;
	
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;
	
	cout<<put_str(buf, "f")<<endl;
	cout<<put_str(buf, "g")<<endl;
	cout<<put_str(buf, "h")<<endl;
	
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;
	cout<<get_str(buf, res)<<"->get = "<<res<<endl;

	print_array(buf->store, BUFSIZE);	// head虽然不指向[0]了,但[0]的字符仍然被保存着
}

void test_question_1()
{
	test_trie();
	cout<<"---------------------------"<<endl;
	test_str_buffer();
}

int main()
{
	test_question_1();

	return 0;
}