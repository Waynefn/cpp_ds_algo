#include <bits/stdc++.h>

using namespace std;

#define MAX (8)

typedef struct 
{
	int key;
	char val;
}item_t;

void sort(item_t data[])
{
	int i, j, tmp_key;
	char tmp_val;

	for(i = 1; i < MAX; i++)
	{
		for(j = i; j > 0 && data[j-1].key >= data[j].key; j--)
		{
			tmp_key = data[j].key; tmp_val = data[j].val;
			data[j].key = data[j-1].key;
			data[j].val = data[j-1].val;
			data[j-1].key = tmp_key; data[j-1].val = tmp_val;
		}
	}
}

void show(item_t data[])
{
	int i = MAX;
	while(i--)
		cout<<data[MAX-i-1].key<<", "<<data[MAX-i-1].val<<endl;
}

int main()
{
	item_t data[MAX] = 
	{
		{5, 'a'},
		{2, 'd'},
		{6, 'e'},
		{4, 'h'},
		{1, 'b'},
		{8, 'f'},
		{3, 'c'},
		{7, 'g'}
	};
	sort(data);
	show(data);

	return 0;
}