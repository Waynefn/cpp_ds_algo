#include<iostream>  
#include<cstdlib> 

#include "utils.h"

using namespace std;

#define MAX (20)

bool check(int i,int column[]){  
    for(int j=0;j<i;j++){  
        if(column[j]==column[i]
        || abs(column[i]-column[j]) == (i-j))	//斜率等于±1  
            return false;
    }  
    return true;  
}  
//start表示搜索的行，column表示该行的所放的列  
void eightQueen(int start,int column[],int &sum){  
    if(start>=8){  
        for(int j=0;j<8;j++){  
            cout<<column[j]<<" ";  
        }  
        cout<<endl<<"-----------------"<<endl;  
        sum++;  
        return;  
    }  
    for(int j=0;j<8;j++){  
        column[start]=j;  
        if(check(start,column)){   
            eightQueen(start+1,column,sum);  
        }  
    }//end for  
}  

void test_n_queen()
{
	int column[8];  
    int sum=0;  
    eightQueen(0,column,sum);  
    cout<<sum<<endl;  
}

int main()
{
	test_n_queen();
	return 0;
}