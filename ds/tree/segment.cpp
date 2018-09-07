#include <iostream>

using namespace std;

/**********************************************
    线段树(Segment)
**********************************************/
#define Len(x)      sizeof(x)/sizeof(x[0])  
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct _Segment
{
    int start, end, max, min, sum;
    _Segment *left, *right;
    _Segment(int s, int end, int val)
    {
        this->start = s;
        this->end = end;
        this->max = this->min = this->sum = val;
        this->left = this->right = NULL;
    }
}Segment;

void Trvl(Segment *t, int curr_level = 1)
{
    if(NULL == t)
        return;

    for(int i = 0; i < curr_level; i++)
        cout<<"#";
    cout<<"["<<t->start<<"~"<<t->end<<"]:max = "<<t->max<<", min = "<<t->min<<", sum = "<<t->sum<<endl;
    Trvl(t->left, curr_level+1);
    Trvl(t->right, curr_level+1);
}

Segment *Build(int a[], int s, int e)
{
    if(s > e)
        return NULL;

    Segment *node = new Segment(s, e, a[s]);
    if(s == e)
        return node;

    int m = (s + e) / 2;
    node->left = Build(a, s, m);
    node->right = Build(a, m+1, e);

    node->max = node->left->max > node->right->max ? node->left->max : node->right->max;
    node->min = node->left->min < node->right->min ? node->left->min : node->right->min;
    node->sum = node->left->sum + node->right->sum;

    return node;
}

void Improve(Segment *t, int index, int val)
{
    if(NULL == t || index < t->start || index > t->end)
        return;
    if(index == t->start && index == t->end)
    {
        t->max = t->min = val;
        return;
    }

    int m = (t->start + t->end) / 2;
    if(index <= m)
        Improve(t->left, index, val);
    else
        Improve(t->right, index, val);
    
    t->max = max(t->left->max, t->right->max);
    t->min = min(t->left->min, t->right->min);
    t->sum = t->left->sum + t->right->sum;
}

// 返回a[from]到a[to]的数据的和
int QuerySum(Segment *t, int from, int to)
{
    if(from > to)
        return 0;
    if(from == t->start && to == t->end)
        return t->sum;

    int m = (t->start + t->end) / 2;
    if(m > to)
        return QuerySum(t->left, from, to);
    else if(m < from)
        return QuerySum(t->right, from, to);
    else
    {
        int left = QuerySum(t->left, from, m);
        int right = QuerySum(t->right, m+1, to);
        return left + right;
    }
}

void test_Build()
{
    int a[] = {1,2,7,8,5};
    Segment *t = Build(a, 0, Len(a)-1);
    Trvl(t);
}

void test_Improve()
{
    int a[] = {1,2,7,8,5};
    Segment *t = Build(a, 0, Len(a)-1);

    cout<<"----------improve----------"<<endl;
    Improve(t, 2, 9);
    Trvl(t);
}

void test_QuerySum()
{
    int a[] = {1,2,7,8,5};
    Segment *t = Build(a, 0, Len(a)-1);

    cout<<"----------query sum----------"<<endl;
    Trvl(t);
    cout<<"query sum = "<<QuerySum(t, 0, 2)<<endl;
}

int main()
{
    test_Build();
    test_Improve();
    test_QuerySum();

    return 0;
}