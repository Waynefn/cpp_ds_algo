#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
  归并排序-非递归实现
**********************************************/
void Merge_MergeArray(int a[], int s, int m, int e, int p[])
{
  int i = s, j = m+1, k = 0;

  while(i <= m && j <= e)
  {
    if(a[i] < a[j]) p[k++] = a[i++];
    else      p[k++] = a[j++];
  }
  while(i <= m)   p[k++] = a[i++];
  while(j <= e)   p[k++] = a[j++];

  for(i = 0; i < k; i++)
    a[s+i] = p[i];
}

void Merge(int a[], int n)
{
    stack<int> st;
    st.push(0), st.push(n-1);
    while(!st.empty())
    {
        int e = st.top(); st.pop();
        int s = st.top(); st.pop();
    }
}

int main()
{
  int a[] = {49,38,65,97,26,13,27,49,55,4};
  Merge(a, Len(a));
  PRINT_ARRAY(a, Len(a));

  return 0;
}