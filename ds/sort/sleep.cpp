#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
    睡觉排序
**********************************************/
void *Sleep_Worker(void *arg)
{
    int time = *(int *)arg;
    usleep(time*1000);
    cout<<time<<" ";
}

void Sleep(int a[], int n)
{
    pthread_t td[100];
    for(int i = 0; i < n; i++)
        pthread_create(&td[i], NULL, Sleep_Worker ,(void *)&a[i]);
    for(int i = 0; i < n; i++)
        pthread_join(td[i], NULL);
}

int main()
{
    int a[] = {4,5,65,77,23,54,2,9,2,3,7,10};
    Sleep(a, Len(a));

    return 0;
}