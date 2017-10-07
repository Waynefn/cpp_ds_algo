#include <iostream>

#include "main.h"
#include "array.h"
#include "list.h"
#include "doubly_list.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"
#include "graph.h"
#include "sort.h"
#include "exam.h"

using namespace std;

void day_20171008()
{
	/***********************************************/
	int a1[4] = {1,3,5,7};
	int b1[5] = {2,4,6,8,10};
	int c1[20] = {};
	array_merge2Array(a1, Len(a1), b1, Len(b1), c1, Len(c1));

	int a2[10] = {0,1,2,3,4,5,6,7,8,9};
	array_reverse(a2, Len(a2));

	int a3[10] = {1,2,2,3,4,5,5,6,7,7};
	array_deleteX(a3, Len(a3), 2);

	int a4[10] = {1,1,2,2,2,3,4,5,5,6};
	array_deleteRepeat(a4, Len(a4));

	/**********************************************
	int l1[10] = {3,3,5,7,9,4,5,6,2,3};
	ListNode *list1 = list_insertHead(l1, Len(l1));
	list1 = list_deleteX(list1, 3);
	list_reverse(list1);

	int l2[5] = {2,4,6,8,10};
	ListNode *list2 = list_insertTail(l2, Len(l2));
	list2 = list_mergeList(list1, list2);

	int l3[10] = {6,7,8,9,10,9,9,9,9,9};
	DoublyListNode *list3 = doubly_list_insertHead(l3, Len(l3));
	list3 = doubly_list_deleteX(list3, 9);
*/

	StackNode *s = stack_create();
	for(int i = 0;  i < 10; i++)
		stack_push(s, i);
	stack_empty(s);

	show_radixSort();
}

int a[5] = {1,3,5,7,9};
int b[5] = {2,4,6,8,10};
int tmp[10] = {0};
void test(int a[], int m, int b, int n, int tmp[])
{
	
}

int main()
{
	day_20171008();

	return 0;
}

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}