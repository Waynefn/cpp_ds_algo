#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define MAX (128)

int t[MAX];
void shifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[]) {
	shifttable(p);

	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		   return(i-m+1); 
		else
		   i+=t[src[i]];
	}
	return -1;
}

int main()
{

	char text[] = {"XYXZdeOXZZKWXYZ"};
	char pattern[] = {"WXYZ"};

	cout<<"faster match: "<<horspool(text, pattern)<<endl;
	return 0;
}