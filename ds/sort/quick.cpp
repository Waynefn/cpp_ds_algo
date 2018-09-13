#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
	快排-递归实现
**********************************************/
void Quick_r_sub(int a[], int s, int e)
{
	if(s >= e)
		return;
	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && a[j] > x)	j--;
		if(i < j)	a[i++] = a[j];
		while(i < j && a[i] < x)	i++;
		if(i < j)	a[j--] = a[i];	
	}
	a[i] = x;
	Quick_r_sub(a, s, i-1);
	Quick_r_sub(a, i+1, e);
}

void Quick_r(int a[], int n)
{
	Quick_r_sub(a, 0, n-1);
}

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
	第k大数-快排实现
**********************************************/
void Kth_sub(int a[], int s, int e, int k)
{
	if(s > e)
		return;
	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && x < a[j])	j--;
		if(i < j)					a[i++] = a[j];
		while(i < j && x > a[i])	i++;
		if(i < j)					a[j--] = a[i];
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

/**********************************************	
	test
**********************************************/
void test()
{
	int a1[] = {99,38,65,97,26,13,27,19,55,4};
	Quick_r(a1, Len(a1));
	PRINT_ARRAY(a1, Len(a1));
	
	int a2[] = {99,38,65,97,26,13,27,19,55,4};
	Quick(a2, Len(a2));
	PRINT_ARRAY(a2, Len(a2));

	int a3[] = {3,9,0,5,6,2,1,4};
	Kth(a3, Len(a3), 4);
	Kth(a3, Len(a3), 6);
}

int main()
{
	test();
	return 0;
}