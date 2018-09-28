#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
    快排-递归实现
**********************************************/
void Quick_r(int a[], int s, int e)
{
    if(s >= e)
        return;
    int i = s, j = e, x = a[s];
    while(i < j)
    {
        while(i < j && a[j] > x)    j--;
        if(i < j)   a[i++] = a[j];
        while(i < j && a[i] < x)    i++;
        if(i < j)   a[j--] = a[i];  
    }
    a[i] = x;
    Quick_r(a, s, i-1);
    Quick_r(a, i+1, e);
}

void Quick(int a[], int n)
{
    Quick_r(a, 0, n-1);
}

/********************************************** 
    快排-三数取中实现
**********************************************/
void Median3(int a[], int low, int high)
{
    int mid = (low+high)/2;
    if(a[mid] > a[high])    SWAP(a[mid], a[high]);
    if(a[low] > a[high])    SWAP(a[low], a[high]);
    if(a[mid] > a[low])     SWAP(a[mid], a[low]);
}

void Quick_3_r(int a[], int s, int e)
{
    if(s >= e)
        return;
    Median3(a, s, e);
    int i = s, j = e, x = a[s];
    while(i < j)
    {
        while(i < j && a[j] > x)    j--;
        if(i < j)   a[i++] = a[j];
        while(i < j && a[i] < x)    i++;
        if(i < j)   a[j--] = a[i];  
    }
    a[i] = x;
    Quick_3_r(a, s, i-1);
    Quick_3_r(a, i+1, e);
}

void Quick_3(int a[], int n)
{
    Quick_3_r(a, 0, n-1);
}

/********************************************** 
    第k大数-快排实现
**********************************************/
void Kth_sub(int a[], int s, int e, int k)
{
    if(s > e)
        return;
    int i = s, j = e, x = a[s];
    while(i < j)
    {
        while(i < j && x < a[j])    j--;
        if(i < j)                   a[i++] = a[j];
        while(i < j && x > a[i])    i++;
        if(i < j)                   a[j--] = a[i];
    }
    a[i] = x;
    if(k-1 < i)
        Kth_sub(a, 0, i-1, k);
    else if(k-1 > i)
        Kth_sub(a, i+1, e, k);
    else
        cout<<"NO."<<k<<" = "<<a[i]<<endl;
}

void Kth(int a[], int n, int k)
{
    Kth_sub(a, 0, n-1, k);
}

int main()
{
    int a1[] = {8,9,0,5,6,2,1,4};
    Quick(a1, Len(a1));
    PRINT_ARRAY(a1, Len(a1));
    
    int a2[] = {8,9,0,5,6,2,1,4};
    Quick_3(a2, Len(a2));
    PRINT_ARRAY(a2, Len(a2));

    int a3[] = {8,9,0,5,6,2,1,4};
    Kth(a3, Len(a3), 4);
    Kth(a3, Len(a3), 6);
    return 0;
}