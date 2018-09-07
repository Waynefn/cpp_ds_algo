/*
http://www.cs.tsukuba.ac.jp/admission/23-8inf.pdf
	问题1->处理超大数字
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->处理超大数字
	(d):执行C行11次，初始0执行了一次，d=1执行一次 ~ d=1234执行四次
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])
#define N (100)

typedef struct
{
	int length;
	int digits[N];
}BigDecimal;

void print_array(int a[], int n)
{
	for(int i = n-1; i >= 0; i--)
		cout<<a[i]<<" ";
	cout<<endl;
}

void intToBigDecimal(int i, BigDecimal *d)
{
	d->length = 0;
	do{
		d->digits[d->length] = i % 10;		// coding
		d->length++;
		i /= 10;		// coding
	}while(i);
}

void shiftLeftBigDecimal(BigDecimal *d)
{
	int i;
	for(i = d->length; i > 0; i--)
		d->digits[i] = d->digits[i-1];		// coding
	if(d->length > 1 || d->digits[0] != 0)	// coding
		d->length++;
	d->digits[0] = 0;						// coding
}

void strToBigDecimal(char *str, BigDecimal *d)
{
	intToBigDecimal(0, d);
	do{
		shiftLeftBigDecimal(d);
		
		d->digits[0] = *str-'0';// coding
		
		str++;

	}while(*str != '\0');				// coding
}

int compareBigDecimal(BigDecimal *d1, BigDecimal *d2)
{
	if(d1->length > d2->length)
		return 1;
	if(d1->length < d2->length)
		return -1;
	for(int i = d1->length-1; i >= 0; i--)
	{
		if(d1->digits[i] > d2->digits[i])
			return 1;
		if(d1->digits[i] < d2->digits[i])
			return -1;
	}

	return 0;
}

void int_to_big_decimal()
{
	BigDecimal *big = new BigDecimal;
	intToBigDecimal(1, big);
	shiftLeftBigDecimal(big);
	print_array(big->digits, big->length);
}

void str_to_big_decimal()
{
	BigDecimal *big = new BigDecimal;
	strToBigDecimal((char *)"12345", big);
	print_array(big->digits, big->length);
}

void compare_big_decimal()
{
	BigDecimal *b1 = new BigDecimal;
	BigDecimal *b2 = new BigDecimal;

	intToBigDecimal(1346, b1);
	intToBigDecimal(1346, b2);
	cout<<compareBigDecimal(b1,b2)<<endl;
}

void test_question_1()
{
	int_to_big_decimal();
	str_to_big_decimal();
	compare_big_decimal();
}

int main()
{
	test_question_1();

	return 0;
}