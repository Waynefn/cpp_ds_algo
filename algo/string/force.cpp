#include <iostream>
#include <string.h>

using namespace std;

int force(char t[], char p[])
{
	int i = 0, j = 0;
	while(i < strlen(t))
	{
		if(t[i] == p[j])
		{
			i++,j++;
			if(j == strlen(p))
				return i-strlen(p);
		}
		else
			i = i-j+1,j=0;
	}
	return -1;
}

void test_force()
{
	char t[] = {"XYXZdeOXZZKWXYZ"};
	char p[] = {"WXYZ"};

	cout<<"result : "<<force(t, p)<<endl;
}

int main()
{
	test_force();
	return 0;
}