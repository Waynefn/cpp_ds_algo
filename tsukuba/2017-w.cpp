/*
http://www.cs.tsukuba.ac.jp/admission/29-2.pdf
	情报1
		离散数学逻辑
	情报2
		问题1->Trie树
		问题2->数组实现动态buffer
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/***************************************
情报2
	问题1->Trie树
		n个节点的树中,长度为k的字符串的搜索时间复杂度:
			O(k),因为每一个字符k[i]直接通过下标随机访问确认存在or不存在,k次搜索即可完成
	问题2->数组实现字符串buffer
		head和tail指针记录数组中存储元素的始末位置
		注1:空间不够时，虽然str的部分字符会被写入数组，但tail指针不会更新位置
		注2:题目问如何防止溢出,指的是head和tail没用模SIZE,数字会不断增长
			head = n*SIZE + x
			tail = (n+1)*SIZE + y  (tail最大不会超过head一个SIZE)
			此时head和tail应该同时减去n*SIZE,即可起到模SIZE的作用
***************************************/
#define A1 	n->c[i] == NULL
#define B1 	n->c[i]
#define C1 	true
#define D1 	n->val = val
#define E1	n->c[i]
#define F1	n->isEnd

#define A2	buf->tail
#define B2	buf->store[i++ % BUFSIZE]
#define C2	*dest++
#define D2	buf->head
#define E2	(buf->head / BUFSIZE) * BUFSIZE

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
		if(A1)
			n->c[i] = new_node();
		n = B1;
	}
	n->isEnd = C1;
	D1;
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
		n = E1;
	}
	if(F1)		// 节点一定不为NULL，但还要判断isEnd来决定返回值
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

#define BUFSIZE (24)

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
	char *cp_str = str;

	while(i - buf->head < BUFSIZE)
	{
		buf->store[i++ % BUFSIZE] = *str;
		if(*str == '\0')
		{
			buf->tail = i;
			cout<<"put("<<cp_str<<")\tOK, tail = "<<buf->tail<<endl;
			return 1;
		}
		else
			str++;
	}
	cout<<"put("<<cp_str<<")\tfailed, tail = "<<buf->tail<<endl;
	return 0;
}

int get_str(buffer *buf, char dest[])
{
	int i = buf->head;				// 为了避免操作head,用变量i读取buf的头部字符
	if(i == A2)						// head == tail,buf为空
	{
		cout<<"get() empty"<<endl;
		return 0;
	}

	do{
		*dest = B2;
	}while(C2 != '\0');				// 先判断相等,再++

	D2 = i;							// 读取完成,更新head指针
	i = E2;	
	buf->head -= i;
	buf->tail -= i;

	return 1;
}

void test_str_buffer()
{
	buffer *buf = new buffer;
	char res[BUFSIZE] = {""};

	put_str(buf, "012");
	put_str(buf, "345");
	put_str(buf, "67890");
	put_str(buf, "1234");
	put_str(buf, "56789");
	put_str(buf, "012");
	put_str(buf, "34567");
	print_array(buf->store, BUFSIZE);
	
	get_str(buf, res); print_array(res, BUFSIZE);
	get_str(buf, res); print_array(res, BUFSIZE);
	
	put_str(buf, "34567");
	print_array(buf->store, BUFSIZE);
	cout<<"head = "<<buf->head<<" tail = "<<buf->tail<<endl;
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