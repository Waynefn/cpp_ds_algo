#include<stdio.h>
#include<iostream>
using namespace std;

#define SWAP(x, y)  {int c = x; x = y; y = c;   }

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void b2(int a[], int n)
{
    int last = n;
    while(last)
    {
        int i = last;
        last = 0;
        for(int j = 1; j < i; j++)
        {
            if(a[j-1] > a[j])
            {
                last = j;
                SWAP(a[j-1], a[j]);
            }
        }
    }
    
}

void b1(int a[], int n)
{
    for(int i = n; i > 1; i--)
    {
        for(int j = 1; j < i; j++)
        {
            if(a[j-1] > a[j])
                SWAP(a[j-1], a[j]);
        }
    }
}

int main()
{
	int a[6] = {2,3,1,4,5,6};
	
    b2(a, 6);
    PRINT_ARRAY(a,6);

    return 0;
}