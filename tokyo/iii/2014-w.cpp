/*
问题2：数据压缩？？？
问题3：？？？
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int T(int x, int y, int z)
{
	if(x <= y)	return y;
	else		return T(T(x-1,y,z), T(y-1,z,x), T(z-1,x,y));
}

void Q3()
{
	cout<<T(4,1,2)<<endl;
}

int main()
{
	Q3();
	return 0;
}
