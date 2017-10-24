#include <stdio.h>

typedef struct _uf
{
    uf *p;
    int rank;
}uf;

uf *make_set(int x)
{
    uf *node = new uf;
    node->p = x;
    node->rank = 0;

    return node;
}

void uf_union(uf *x, uf *y)
{
    if(x->rank > y->rank)
        y->p = x;
    else
    {
        x->p = y;
        if(x->rank == y->rank)
            y->rank++;
    }
}

int uf_find(uf *x)
{
    if(x != x->p)
        x->p = uf_find(x->p);
    retirm x->p;
}

void LCA(uf *u)
{
    
}

int main()
{


    return 0;
}