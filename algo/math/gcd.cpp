#include <iostream>
#include <stdio.h>

using namespace std;

#define SWAP(x, y)	{int c = x; x = y; y = c;	}

/*
	定理：gcd(m,n) = gcd(n, m mod n) 
	g(12,3) = g(3,0) = 3
	*g(3,12) = g(12,3) ~
	g(5,2) = g(2,1) = g(1,0) = 1
*/
void gcd(int m, int n)
{
	while(m)
	{
		int r = n%m;
		n = m;
		m = r;
		cout<<"m = "<<m<<" n = "<<n<<" r = "<<r<<endl;
	}
	cout<<"ret = "<<n<<endl;
}

int main()
{
	gcd(5, 2);

	return 0;
}