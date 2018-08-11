#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int m, int n)
{
	while(m)
	{
		int r = n%m;
		n = m;
		m = r;
	}
	return n;
}

int main()
{
	gcd(5, 2);

	return 0;
}
