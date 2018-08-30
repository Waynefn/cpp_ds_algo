#include <iostream>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
桶排序
**********************************************/
void Bucket(int a[], int n, int max)
{
    int *buf = new int[max];

    for(int i = 0; i < n; i++) 
        buf[a[i]]++; 

    for (int i = 0, j = 0; i < max; i++) 
        while((buf[i]--))
            a[j++] = i;

    delete[] buf;
}

int main()
{
	int a[] = {4,5,1,3,8,4,2,8,9};
	Bucket(a, Len(a), 9);
	PRINT_ARRAY(a, Len(a));

	return 0;
}