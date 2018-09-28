#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])

/**********************************************
    背包问题-递归搜索
**********************************************/
int w[] = {2,3,4,5};
int v[] = {3,4,5,6};
int n = Len(w);
int k = 8;

int knapsack(int curr_v, int curr_w, int curr, bool ret[])
{
	if(curr_w > k)
		return -1;
	if(curr >= n)
	{
		for(int i = 0; i < n; i++)
			if(ret[i])
				cout<<i<<" ";
		cout<<" value => "<<curr_v<<endl;
		return curr_v;
	}
	else
	{
		ret[curr] = true;
		int a = knapsack(curr_v+v[curr], curr_w+w[curr], curr+1, ret);
		ret[curr] = false;
		int b = knapsack(curr_v, curr_w, curr+1, ret);
		return max(a, b);
	}
}

int main()
{
	bool ret[n];
    cout<<"max value = "<<knapsack(0, 0, 0, ret)<<endl;
	return 0;
}