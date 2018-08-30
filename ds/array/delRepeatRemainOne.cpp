#include <iostream>

using namespace std;

/**********************************************
    有序数组中，重复元素删除至只剩1个
    1,2,2,3,3,5,5,6,7,7 --> 1,2,3,5,6,7
**********************************************/

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int DelRepeatRemainOne(int a[], int n)
{
	int i = 0, j = 1;
	
	for(; j < n; j++)
		if(a[i] != a[j])
			a[++i] = a[j];

	return i+1;
}

int main()
{
	int a[10] = {1,2,2,3,3,5,5,6,7,7};

	PRINT_ARRAY(a, Len(a));
	int n = DelRepeatRemainOne(a, Len(a));
	PRINT_ARRAY(a, n);
	return 0;
}