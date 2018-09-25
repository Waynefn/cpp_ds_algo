#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
堆排序
Heap1() : 借助额外的数组
Heap2() : 数组自身完成堆排
**********************************************/
void Heap1_Up(int hp[], int add)
{
	int i = ++hp[0];

	for(; i > 1 && hp[i/2] > add; i /= 2)
		hp[i] = hp[i/2];
	hp[i] = add;
}

int Heap1_Down(int hp[])
{
	int ret = hp[1], last = hp[hp[0]--];
	int child, i;

	for(i = 1; i*2 <= hp[0]; i = child)
	{
		child = 2*i;
		if(child+1 <= hp[0] && hp[child+1] < hp[child])
			child++;
		if(last < hp[child])
			break;
		else
			hp[i] = hp[child];
	}
	hp[i] = last;

	return ret;
}

void Heap1(int a[], int n)
{
	int *hp = new int[n+1];
	hp[0] = 0;

	for(int i = 0; i < n; i++)
		Heap1_Up(hp, a[i]);
	for(int i = 0; i < n; i++)
		a[i] = Heap1_Down(hp);
}

void Heap2_Up(int a[], int idx)
{
	int i = idx, add = a[idx];
	for(; i && add > a[(i-1)/2]; i = (i-1)/2)
		a[i] = a[(i-1)/2];
	a[i] = add;
}

void Heap2_Down(int a[], int last)
{
	int curr = a[last];
	SWAP(a[0], a[last]);

	int i = 0, child, smallest = 0;
	for(; i < last; i = child)
	{
		child = 2*i+1;
		if(child+1 < last && a[child] < a[child+1])
			child++;
		if(child < last && curr < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = curr;
}

void Heap2(int a[], int n)
{
	for(int i = 1; i < n; i++)
		Heap2_Up(a, i);
	for(int i = n; i > 0; i--)
		Heap2_Down(a, i-1);
}

int main()
{
	int a1[] = {1,1,0,0,3,4,5,2,2,0};
    Heap1(a1, Len(a1));
    PRINT_ARRAY(a1, Len(a1));
    
    int a2[] = {1,1,0,0,3,4,5,2,2,0};
	Heap2(a2, Len(a2));
	PRINT_ARRAY(a2, Len(a2));

	return 0;
}