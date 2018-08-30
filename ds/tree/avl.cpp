#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

/**********************************************
    AVL树
**********************************************/
#define Len(x)      sizeof(x)/sizeof(x[0])  
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct _Avl
{
    int val, height;
    _Avl *left, *right;
    _Avl(int val)
    {
        this->val = val;
        this->height = 0;
        this->left = this->right = NULL;
    }
}Avl;

int Height(Avl *t)
{
    if(NULL == t)
        return 0;
    return t->height;
}

void HeightUpdate(Avl *t)
{
    t->height = 1 + max(Height(t->left), Height(t->right));
}

void TrvlLevel(Avl *t)
{
    if(NULL == t)
        return;

    queue<Avl *> q;
    q.push(t);

    int level = 0;
    while(!q.empty())
    {
        level++;
        cout<<"lv"<<level<<" :";
        int lvSize = q.size();
        while(lvSize)
        {
            lvSize--;
            Avl *tmp = q.front(); q.pop();
            cout<<tmp->val<<"-";
            if(tmp->left)   q.push(tmp->left);
            if(tmp->right)  q.push(tmp->right);
        }
        cout<<endl;
    }
}

/*  insert(A),造成k2不平衡
    A < k2 && A < k1 => 此时k2树左倾 
    => LL(k2)
    
        k2                k1
       /       LL        /  \
      k1      --->      A    k2
     /                        
    A                           
*/
Avl *LeftLeft(Avl *k2)
{
    Avl *k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    HeightUpdate(k1);
    HeightUpdate(k2);   

    return k1;
}

/*  insert(A),造成k1不平衡
    A > k1 && A > k1 => 此时k1树右倾 
    => RR(k1)
        k1                  k2
          \       RR       /  \
          k2     --->     k1   A
            \              
             A              
*/
Avl *RightRight(Avl *k1)
{
    Avl *k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    HeightUpdate(k1);
    HeightUpdate(k2);

    return k2;
}

/*  insert(k2),造成k3不平衡
    k2 < k3 && k2 > k1 => 此时k3树左右倾 
    => RR(k1),使k3完全左倾
    => LL(k3)
        k3                k3            k2
       /       RR        /       LL    /  \
      k1      --->      k2      --->  k1  k3
        \              /      
         k2           k1               
*/
Avl *LeftRight(Avl *k3)
{
    k3->left = RightRight(k3->left);
    return LeftLeft(k3);
}

/*  insert(k2),造成k1不平衡
    k2 > k1 && k2 < k3 => 此时k1树右左倾 
    => LL(k3),使k1完全右倾
    => RR(k1)
    k1                k1                k2
      \        LL      \         RR    /  \
      k3      --->      k2      --->  k1  k3
      /                  \ 
     K2                   k3               
*/
Avl *RightLeft(Avl *k1)
{
    k1->right = LeftLeft(k1->right);
    return RightRight(k1);
}

Avl *Insert(Avl *t, int val)
{
    if(NULL == t)
    {
        t = new Avl(val);
    }
    else if(val < t->val)
    {
        t->left = Insert(t->left, val);
        if(2 == abs(Height(t->left) - Height(t->right)))
        {
            
            if(val < t->left->val)
                t = LeftLeft(t);
            else
                t = LeftRight(t);
        }
    }
    else if(val > t->val)
    {
        t->right = Insert(t->right, val);
        if(2 == abs(Height(t->left) - Height(t->right)))
        {
            
            if(val > t->right->val)
                t = RightRight(t);
            else
                t = RightLeft(t);
        }
    }
    else
        ;

    HeightUpdate(t);
    return t;
}

Avl *Delete(Avl *t, int x)
{
    if(NULL == t)
        return NULL;

    if(x < t->val)  // x在t的左子树部分,删除后可能导致t的右子树不平衡
    {
        t->left = Delete(t->left, x);
        if(2 == abs(Height(t->left) - Height(t->right)))    // RR or RL
        {
            Avl *R = t->right;
            if(Height(R->right) > Height(R->left))      // RR
                t = RightRight(t);
            else
                t = RightLeft(t);                                   // RL
        }
    }
    else if(x > t->val) // x在t的右子树部分,删除后可能导致t的左子树不平衡
    {
        t->right = Delete(t->right, x);
        if(2 == abs(Height(t->left) - Height(t->right)))    // LL or LR
        {
            Avl *L = t->left;
            if(Height(L->left) > Height(L->right))      // LL
                t = LeftLeft(t);
            else                                                            // LR
                t = LeftRight(t);
        }
    }
    else
    {
        Avl *tmp;
        if(t->left && t->right) // 根据左右子树的高度,再选择用前驱or后驱元素替代
        {
            if(Height(t->left) > Height(t->right))
            {
                // x节点的左子树>右子树,选择前驱元素替代
                tmp = t->left;
                while(tmp->right)
                    tmp = tmp->right;
                t->val = tmp->val;
                t->left = Delete(t->left, tmp->val);
            }
            else
            {
                // x节点的左子树<右子树,选择后驱元素替代
                tmp = t->right;
                while(tmp->left)
                    tmp = tmp->left;
                t->val = tmp->val;
                t->right = Delete(t->right, tmp->val);
            }
        }
        else
        {
            tmp = t;
            if(t->left) t = t->left;
            else        t = t->right;
            delete tmp;
        }
    }

    return t;
}

int main()
{
    int a[] = {6,4,8,2,7,9,1,3,10,0};
    Avl *t = NULL;

    for(int i = 0; i < Len(a); i++)
        t = Insert(t, a[i]);
    TrvlLevel(t);
    Delete(t, 6);
    TrvlLevel(t);

    return 0;
}