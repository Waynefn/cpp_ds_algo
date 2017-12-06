#include <iostream>

using namespace std;

//#define DEBUG_LOG (FALSE)		// 输出更详细的log时，取消注释
#define Len(x)		sizeof(x)/sizeof(x[0])	
#define NULL_CHK(x)	{if(NULL == x)	cout<<"NULL Err !"<<endl;	}
#define SWAP(x, y)	{int c = x; x = y; y = c;	}
#define PRINT_FUNCTION_NAME	{cout<<endl<<"********** "<<__FUNCTION__<<" **********"<<endl;	}
#define PRINT_SUB_FUNCTION_NAME	{cout<<endl<<"->"<<__FUNCTION__<<endl;}
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}