/*
http://www.cs.titech.ac.jp/H20-gozen.pdf
问题7：归并排序,非递归实现
*/

#include<iostream>  

using namespace std;

#define MAX_LENGTH (1000)
int x[MAX_LENGTH];

void B(int il, int m, int ir)
{
	int i,j,k;
	int temp[MAX_LENGTH];
	i = il; j = m + 1;

	for(k = il; k <= ir; k++)
	{
		if(i > m)				temp[k] = x[j++];
		else if(j > ir)			temp[k] = x[i++];
		else if(x[i] <= x[j])	temp[k] = x[i++];
		else					temp[k] = x[j++];
	}
	for(k = il; k <= ir; k++)
		x[k] = temp[k];
}

void A(int il, int ir)
{
	int m;
	if(il >= ir)	return;
	m = (il+ir)/2;
	A(il, m);
	A(m+1, ir);
	B(il,m,ir);
}

void D(int il. int ir)
{
	int m, i, j, size;
	size = 1;
	while(size <= (ir-il))
	{
		for(i = il; i <= ir; i = i+size*2)
		{
			j = i + size*2 - i;
			m = (i+j)/2;
			//	coding
		}
		size = size*2;
	}
}

void test_merge()
{
	
}

int main()
{
	test_merge();

	return 0;
}