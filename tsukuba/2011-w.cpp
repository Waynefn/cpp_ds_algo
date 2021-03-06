#include <bits/stdc++.h>

using namespace std

/***************************************
问题1->堆排序(有递归)
***************************************/
#define A   heap_add(heap, a[i])
#define B   a[n-i-1] = heap_delete_min(heap)
#define C   2*i+1
#define D   2*i+2
#define E   b[right] < b[smallest]
#define F   left < size && b[left] < b[smallest]
#define G   b[i]
#define H   b[smallest]
#define I   shift_up(a, i)
#define J   a[0]
#define K   a[n-i-1]
#define L   shift_down(a, 0, n-i-1)

#define Len(x)  sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// coding
void shift_up(int b[], int n)
{
    if(n > 0 && b[n] < b[(n-1)/2])
    {
        swap(b[(n-1)/2], b[n]);
        shift_up(b, (n-1)/2);
    }
}
/*
    参照算法导论 MAX-HEAPIFY,对i节点是否满足堆性质，进行调整。调整范围为size
    1.从b[i],b[left],b[right]中选取最小值，保存到smallest
    2.b[i]为最小值则已经满足堆性质，函数结束
    3.否则，b[i]与b[smallest]交换，使i和它的左右子树满足了堆的性质
    4.由于b[i]移动至b[smallest]，导致下一层再次不满足堆性质，所以递归地操作直至完全沉入底部
*/
void shift_down(int b[], int i, int size)
{
    int left = C, right = D;
    int smallest = i;

    if(right < size && E)
        smallest = right;
    if(F)
        smallest = left;

    if(smallest != i)
    {
        swap(G, H);
        shift_down(b, smallest, size);
    }
}

void sort2(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        I;
    for(i = 0; i < n; i++)
    {
        swap(J, K);
        L;      //  down()中，对于size的判断是【子树节点 < size】，故传参为n-i-1
    }
    print_array(a, n);
}

void test_question_1()
{
    int a[] = {1,5,3,5,7,9,7,6,10,8};

    sort2(a, Len(a));
}

int main()
{
    test_question_1();

    return 0;
}