#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int table[128];
    char t[] = {"XYXZdeOXZZKWXYZ"};
    int n,i,k,j,m,flag=0;

    n=strlen(t);

    char p[] = {"WXYZ"}; 
    m=strlen(p);
    for(i=0;i<128;i++)
        table[i]=m;
    for(j=0;j<m-1;j++)
        table[p[j]]=m-1-j;

    j = 0;
    while(j+m <= n)
    {
        i = m-1;
        while(i >= 0 && p[i] == t[j+i])
            i--;
        if(i == -1)
            cout<<"found "<<j;
        j += table[t[j+m-1]];
    }

    return 0;
}