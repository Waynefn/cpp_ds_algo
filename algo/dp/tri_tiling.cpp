#include <bits/stdc++.h>

using namespace std;

#define M (100)
/**********************************************
    3*n的方块，通过1*2的方块组成的方式有多少
**********************************************/
void tri_tiling(int n)
{
	int f[M] = {0}, g[M] = {0};
	f[0] = 1, f[1] = 0;
	g[0] = 0, g[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		f[i] = f[i-2] + 2*g[i-1];
		g[i] = f[i-1] + g[i-2];
	}
	cout<<"f["<<n<<"] = "<<f[n]<<endl;
}

int main()
{
	tri_tiling(2);	// 3
	tri_tiling(8);	// 153
	tri_tiling(12);	// 2131

	return 0;
}