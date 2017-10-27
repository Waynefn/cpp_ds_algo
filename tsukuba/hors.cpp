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
  i=m-1;
  while(i<=n-1)
  {
    k=0;
    while(k<=m-1 && p[m-1-k]==t[i-k])
      k++;
    if(k==m)
    {
      cout<<"found at "<<i-m+2<<endl;
      flag=1;
      break;
    }
    else
      i=i+table[t[i]];
    }
    if(!flag)
      cout<<"not found"<<endl;

    return 0;
}