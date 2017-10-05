#include <iostream>

#include "main.h"
#include "array.h"
#include "list.h"
#include "doubly_list.h"
#include "tree.h"
#include "graph.h"
#include "sort.h"

using namespace std;

void day_20171008()
{
	/**********************************************
	int a1[4] = {1,3,5,7};
	int b1[5] = {2,4,6,8,10};
	int c1[20] = {};
	array_1(a1, Len(a1), b1, Len(b1), c1, Len(c1));

	int a2[10] = {0,1,2,3,4,5,6,7,8,9};
	array_2(a2, Len(a2));

	int a3[10] = {1,2,2,3,4,5,5,6,7,7};
	array_3(a3, Len(a3), 2);

	int a4[10] = {1,1,2,2,2,3,4,5,5,6};
	array_4(a4, Len(a4));
*/
	/***********************************************/
	int l1[5] = {1,3,5,7,9};
	ListNode *list1 = list_1_insertTail(l1, Len(l1));
	list1 = list_2(list1, 3);

	int l2[5] = {2,4,6,8,10};
	ListNode *list2 = list_1_insertTail(l2, Len(l2));
	list2 = list_3(list1, list2);

	int l3[5] = {6,7,8,9,10};
	DoublyListNode *list3 = doubly_list_1(l3, Len(l3));

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