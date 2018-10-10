#include <bits/stdc++.h>

using namespace std

/***************************************
问题1->插入排序，堆排序
	1.
		插入排序代码填空
		数组什么样的元素时，执行d[j] >= m 次数最多?
		数组有N个元素时,d[j] >= m最大执行次数?
		代码改一个地方,变为降序
	2.堆排(a[0]存放元素个数,利用额外数组)
		a[]={2,0,3,1},完成堆构造时堆数组里元素排列?
			0,1,3,2
		完成代码
		数组庞大时插入和堆排哪个速度快,说明理由
***************************************/
#define A1 	sz
#define B1 	d[j]
#define C1 	m

#define A2 	val[1]
#define B2 	val[j+1]
#define C2 	val[j]
#define D2 	val[val[0]]

#define Len(x)	sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void is(int sz, int d[])
{
	int i, j, m;

	for(i = 1; i < A1; i++)
	{
		m = d[i];
		for(j = i-1; j >= 0 && d[j] >= m; j--)
			d[j+1] = B1;
		d[j+1] = C1;
	}

	print_array(d, sz);
}

/********************************************/
void in(int dt, int val[])
{
	int i;

	val[0]++;
	for(i = val[0]; i > 1 && dt < val[i/2]; i = i/2)
		val[i] = val[i/2];
	val[i] = dt;
}

int dl(int val[])
{
	int i = 1, j, ret = A2;

	while(i <= val[0]/2)
	{
		j = 2*i;
		if(j+1 < val[0] && B2 < C2)
			j++;
		if(val[val[0]] < val[j])
			break;
		val[i] = val[j];
		i = j;
	}
	val[i] = D2;			
	val[0]--;

	return ret;
}

void hs(int sz, int d[])
{
	int i;
	int *val = new int[sz+1];
	val[0] = 0;

	for(i = 0; i < sz; i++)
		in(d[i], val);
	/* A */
	print_array(val, sz+1);
	for(i = 0; i < sz; i++)
		d[i] = dl(val);

	print_array(d, sz);
}

void test_question_1()
{
	int a[] = {5,6,4,2,1,3,9};
	is(Len(a), a);

	int b[] = {2,0,3,1};
	hs(Len(b), b);
}

int main()
{
	test_question_1();

	return 0;
}