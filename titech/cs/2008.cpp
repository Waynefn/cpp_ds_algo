#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/***************************************
    归并排序
    非递归实现
***************************************/

#define MAX_LENGTH (1000)
// int x[MAX_LENGTH];
// int x[] = {8,5,2,3,0,7,4,9,1};
int x[] = {9,3,4,2,0};

void B(int il, int m, int ir)
{
    cout<<"B["<<il<<","<<m<<","<<ir<<"]"<<endl;
    int i,j,k;
    int temp[MAX_LENGTH];
    i = il; j = m + 1;
    for(k = il; k <= ir; k++)
    {
        if(i > m)               temp[k] = x[j++];
        else if(j > ir)         temp[k] = x[i++];
        else if(x[i] <= x[j])   temp[k] = x[i++];
        else                    temp[k] = x[j++];
    }
    for(k = il; k <= ir; k++)
        x[k] = temp[k];
}

void A(int il, int ir)
{
    cout<<"A["<<il<<","<<ir<<"]"<<endl;
    int m;
    if(il >= ir)    return;
    m = (il+ir)/2;
    A(il, m);
    A(m+1, ir);
    B(il,m,ir);
}

void D(int il, int ir)
{
    int m, i, j, size;
    size = 1;
    while(size <= (ir-il))
    {
        for(i = il; i <= ir; i = i+size*2)
        {
            j = i + size*2 - 1;
            m = (i+j)/2;
            if(j > ir-il)
                j = ir-il;
            B(i, m, j);
        }
        size = size*2;
    }
}

int main()
{
    A(0, 4);
    // D(0, Len(x)-1);
    PRINT_ARRAY(x, Len(x));
    return 0;
}