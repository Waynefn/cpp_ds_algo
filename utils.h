#include <iostream>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define NULL_CHK(x)	{if(NULL == x)	cout<<"NULL Err !"<<endl;	}
#define SWAP(x, y)	{if(x != y)	{	int c = x; x = y; y = x;}	}
#define PRINT_FUNCTION_NAME	{cout<<endl<<__FUNCTION__<<endl;	}
#define PRINT_SUB_FUNCTION_NAME	{cout<<"->"<<__FUNCTION__<<endl;}