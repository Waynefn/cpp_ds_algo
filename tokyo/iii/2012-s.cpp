/*
问题2：编辑距离
问题3：归并排序
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])  
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

#define I       left >= right
#define II      mSort(data, tmp, left, mid);                        \
                mSort(data, tmp, mid+1, right);
#define III     int i = left, j = mid+1, k = 0;                     \
                while(i <= mid && j <= right)                       \
                {                                                   \
                    if(data[i] < data[j])   tmp[k++] = data[i++];   \
                    else                    tmp[k++] = data[j++];   \
                }                                                   \
                while(i <= mid)     tmp[k++] = data[i++];           \
                while(j <= right)   tmp[k++] = data[j++];           \
                for(i = 0; i < k; i++)                              \
                    data[left+i] = tmp[i];                          
/**********************************************
    问题2. 编辑距离
**********************************************/


/**********************************************
    问题3. 归并排序
**********************************************/
void merge(int data[], int tmp[], int left, int mid, int right)
{
    III;
}

void mSort(int data[], int tmp[], int left, int right)
{
    if(I)   return;
    int mid = (left + right) / 2;
    II;
    merge(data, tmp, left, mid, right);
}

void test_3()
{
    int a[] = {5,7,3,4,1,9,8};
    int *p = new int[Len(a)];
    mSort(a, p, 0, Len(a)-1);
    delete p;
    PRINT_ARRAY(a, Len(a));
}

int main()
{
    test_3();

    return 0;
}