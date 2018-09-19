#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
	快排-非递归实现
**********************************************/
int Quick_sub(int a[], int s, int e)
{
	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && a[j] > x)	j--;
		if(i < j)					a[i++] = a[j];
		while(i < j && a[i] < x)	i++;
		if(i < j)					a[j--] = a[i];
	}
	a[i] = x;
	return i;
}

void Quick(int a[], int n)
{
	stack<int> st;
	st.push(0), st.push(n-1);
	while(!st.empty())
	{
		int e = st.top(); st.pop();
		int s = st.top(); st.pop();
		int p = Quick_sub(a, s, e);
		if(p-1 > s)
			st.push(s), st.push(p-1);
		if(p+1 < e)
			st.push(p+1), st.push(e);
	}
}

/**********************************************	
	test
**********************************************/
void test()
{
	int a2[] = {99,38,65,97,26,13,27,19,55,4};
	Quick(a2, Len(a2));
	PRINT_ARRAY(a2, Len(a2));
}

int main()
{
	test();
	return 0;
}