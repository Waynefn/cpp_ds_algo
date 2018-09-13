#include <bits/stdc++.h>

using namespace std;

#define MAX (8)

void display(int arr[])
{
	int i;
	for(i = 0; i < MAX; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int arrange(int a, int b, int arr[])
{
	int left, right, bd, temp;
	left = a, right = b, bd = arr[(a+b)/2];
	while(1)
	{
		while(arr[left] < bd){
			left++;
			if(left > b)
				break;
		}
		while(arr[right >= bd]){
			right--;
			if(right < a)
				break;
		}
		if(right < a)
		{
			arr[(a+b)/2] = arr[a];
			arr[a] = bd;
			return a+1;
		}
		else if(left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++, right--;
		}
		else
			break;
	}
	return left;
}

void sort(int a, int b, int arr[])
{
	int k;
	if(b <= a)
		return;
	k = arrange(a, b, arr);
	display(arr);
	sort(a, k-1, arr);
	sort(k, b, arr);
}

int main()
{
	int a[] = {3, 5, 7, 4, 2, 8, 6, 1};
	sort(0, MAX-1, a);
	display(a);
	return 0;
}