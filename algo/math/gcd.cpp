#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int m, int n)
{
	int r = 1;
	while(r)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main()
{
	cout<<gcd(5, 2)<<endl;

	return 0;
}
