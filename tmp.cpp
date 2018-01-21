#include <iostream>
#include <string>
#include <string.h>

#include "utils.h"

using namespace std;

typedef struct _List
{
	int val;
	_List *next;
}List;

List *ins(List* h, int val)
{
	List *n = new List();
	n->val = val;
	n->next = NULL;

	List *p = h;

	if(NULL == p)
	{
		n->next = p;
		return n;
	}
	while(p->next && val > p->next->val)
		p = p->next;
	n->next = p->next;
	p->next = n;

	return h;
}

int main()
{
	int *p;
	int n = 10, b = 0;
	p = &n;
	b = *p + 1;
	n = 100;

	cout<<*p<<endl;
	cout<<b<<endl;


	return 0;
}

void remove_if(Node **pphead, int v)//删除节点值为v的所有节点  
{  
    for(Node **cur = pphead; *cur;)  
    {  
        Node *en = *cur;  
        if(en->data == v)  
        {  
            // *重要*  
            *cur = en->next;//用二级指针去操纵指针的值,*cur现在为待删除节点的next节点  
            free(en);//释放待删除节点,此时存放地址en值的二级指针cur依然存在 且cur地址  
                    //所指内存已经了存储了 删除节点的下一个节点  
        }  
        else  
        {  
            cur = &en->next;  
        }  
  
    }  
}  