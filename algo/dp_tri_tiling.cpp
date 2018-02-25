#include <iostream>

#include "utils.h"

using namespace std;

void tri_tiling(int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[MAX] = {0}, g[MAX] = {0};
	f[0] = 1, f[1] = 0;
	g[0] = 0, g[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		f[i] = f[i-2] + 2*g[i-1];
		g[i] = f[i-1] + g[i-2];
	}
	cout<<"f["<<n<<"] = "<<f[n]<<endl;
}

void test_tri_tiling()
{
	tri_tiling(8);
}

int main()
{
	test_tri_tiling();

	return 0;
}