#include <iostream>
#include <string>
#include <string.h>

#include "utils.h"

using namespace std;

int bs(int a[], int n, int x)
{
	int i = 0, j = n-1;
	while(i <= j)
	{
		int m = i+(j-i)/2;

		if(x == a[m])
			return m;
		else if(x < a[m])
			j = m-1;
		else
			i = m+1;
	}
	return -1;
}

int main()
{
    int a[] = {2,4,6,7,8,9};
    cout<<bs(a, Len(a), 1)<<endl;
    return 0;
}