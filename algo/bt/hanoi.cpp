#include <bits/stdc++.h>

using namespace std;

/**********************************************
    Shift 'n-1' disks from 'A' to 'B'.
    Shift last disk from 'A' to 'C'.
    Shift 'n-1' disks from 'B' to 'C'.
**********************************************/
void hanoi(int n, char from, char to, char tmp) 
{ 
    if(n == 1)
    {
        cout<<"Move 1 from tower "<<from<<" to "<<to<<endl; 
        return; 
    }
    hanoi(n-1, from, tmp, to); 
    cout<<"Move "<<n<<" from tower "<<from<<" to "<<to<<endl; 
    hanoi(n-1, tmp, to, from); 
} 
  
int main() 
{ 
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    return 0; 
} 