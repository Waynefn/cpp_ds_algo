#include <iostream>

using namespace std;

/**********************************************
    有序数组中，重复元素完全删除1个不剩
    1,2,2,3,3,5,5,6,7,7 --> 1,6
**********************************************/

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int DelRepeat(int a[], int n)
{
	int i = -1, j = 0;
	while(j < n)
	{
		int in = j, inn = in+1;
		if(a[in] != a[inn])
			a[++i] = a[in], j++;
		else
			for(j = inn; j < n && a[j] == a[in]; j++)
				;
	}
	return i+1;
}

int main()
{

	int a[] = {1,2,2,3,4,4,5,6,6};

	PRINT_ARRAY(a, Len(a));
	int n = DelRepeat(a, Len(a));
	PRINT_ARRAY(a, n);
	return 0;
}