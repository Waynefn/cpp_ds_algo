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

using namespace std;

void day_20171008()
{
	/**********************************************
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
*/
	/***********************************************/
	
	test_list_create_merge();
	test_list_reverse();
	test_list_delete();
	test_doubly_list();
}

void day_20171015()
{
//	show_radixSort();

//	test_queue_byStack();
	test_stack_byList();
//	test_stack_minStack();

}

void day_20171022()
{
	test_tree_basic();
}

int main()
{
//	day_20171008();
	day_20171015();
//	day_20171022();
	return 0;
}

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}