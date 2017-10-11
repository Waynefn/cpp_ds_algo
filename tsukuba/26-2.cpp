/*
http://www.cs.tsukuba.ac.jp/admission/26-2inf.pdf
	问题1->
	问题2->
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->
	1.冒泡排序的输出结果？
		[5,3,1,1,0]
	2.数组有N个元素时,判断大小的代码段"data[i] < data[j]"运行次数?原因?
		O(N^2)
		数组N最差情况下从小到大排列,
		data[0]比较N-1次
		data[1]比较N-2次
		...
		data[N-1]比较1次
		所以->
	3.归并排序填代码->垃圾代码
		归并时两段数组互相比较大小并归并,然而下标的移动方向:
			前半段left[]是: start~mid
			后半段right[]是:end~mid+1,每次比较时总是从a[end]开始往前移动,最终a[start~end]保证有序
		e.g:
			最终合并前,a[]中两个sub数组的数据如下
			a[0~3] = {4,5,6,7},a[4~6] = {0,1,9},此时分别将a[0~3]与a[4~6]转存到b[]
			a[4~6]存储至b[]时,必须反向保存->保存至b[6~4]
			{4,5,6,7}与{9,1,0}这样的形式,才能在后续比较大小的代码时正确被排序,因为{9,1,0}部分,0才是第一个被访问的
	4.对N个元素的归并排序,时间复杂度是多少,请解释
		N个元素划分为树状的子问题,每一层最多N次比较,树高度为logN
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])
#define SIZE (7)

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void sort(int data[], int size)
{
	int i, j, t;
	for(i = 0; i < size; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(data[i] > data[j])
			{
				t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
		}
	}
}

int b[SIZE];
void sortsub(int a[], int l, int r)
{
	int i, j, k, m;
	if(l < r)
	{
		m = (l+r)/2;
		sortsub(a,l,m);
		sortsub(a,m+1,r);
		
		for(i = l; i <= m; i++)	
			b[i] = a[i];
		for(j = m+1; j <= r; j++)
			b[r-j+m+1] = a[j]; 		// coding,垃圾代码

		i = l; j = r;
		for(k = l; k <= r; k++)
		{
			if(b[i] < b[j])
				a[k] = b[i++];
			else
				a[k] = b[j--];
		}
	}
}

void sort_2(int data[], int size)
{
	sortsub(data, 0, size-1);
}

void test_question_1()
{
	int array[SIZE] = {4,5,6,7,9,1,0};
	sort_2(array, SIZE);

	print_array(array, Len(array));
}

int main()
{
	test_question_1();

	return 0;
}