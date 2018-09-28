#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])

/**********************************************
    子集和问题
**********************************************/
void subset(int a[], int selected[], int n, int curr, int sum)
{
    if(curr >= n)
    {
        if(sum == 0)
        {
            for(int i = 0; i < n; i++)
                if(selected[i])
                    cout<<a[i]<<"|";  
            cout<<endl;
        }
    }
    else
    {
        selected[curr] = false;
        subset(a, selected, n, curr+1, sum); 
        if(a[curr] <= sum)
        {
            selected[curr] = true;
            subset(a, selected, n, curr+1, sum-a[curr]);  
        }
    }
}

int main()
{  
    int a[]={5,3,4,2};
    int selected[Len(a)] = {false};
    subset(a, selected, Len(a), 0, 7); 

    return 0;  
}  