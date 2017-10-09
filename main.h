#define Len(x)		sizeof(x)/sizeof(x[0])	
#define NULL_CHK(x)	{if(NULL == x)	cout<<"NULL Err !"<<endl;	}
#define SWAP(x, y)	{if(x != y)	{	x ^= y; y ^= x; x ^= y;	}	}
#define PRINT_FUNCTION_NAME	{cout<<endl<<__FUNCTION__<<"\t-->\n";}

void print_array(int a[], int n);