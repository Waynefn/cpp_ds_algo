#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

bool IsNum(char c)
{
	return c >= '0' && c <= '9';
}

int OpLv(char c)
{
	if(c == '(' || c == ')')	return 0;
	if(c == '+' || c == '-')	return 1;
	if(c == '*' || c == '/')	return 2;
	return -1;
}

int Calc(int n1, int n2, char c)
{
	int ret;
	switch(c)
	{
		case '+':	ret = n1+n2;	break;
		case '-':	ret = n1-n2;	break;
		case '*':	ret = n1*n2;	break;
		case '/':	ret = n1/n2;	break;
	}
	return ret;
}

/**********************************************
    计算中缀表达式
**********************************************/
int CalcInfix(const char *str)
{
	stack<int> val;
	stack<char> op;
	for(int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if(IsNum(c))
			val.push(c-'0');
		else if(op.empty() || c == '(' || OpLv(c) > OpLv(op.top()))
			op.push(c);
		else if(c == ')')
		{
			while(op.top() != '(')
			{
				int n2 = val.top(); val.pop();
				int n1 = val.top(); val.pop(); 
				int ret = Calc(n1,n2,op.top());
				val.push(ret); op.pop();
			}
			op.pop();
		}
		else 
		{
			while(!op.empty() && OpLv(c) <= OpLv(op.top()))
			{
				int n2 = val.top(); val.pop();
				int n1 = val.top(); val.pop(); 
				int ret = Calc(n1,n2,op.top());
				val.push(ret); op.pop();
			}
			op.push(c);
		}
	}
	while(!op.empty())
	{
		int n2 = val.top(); val.pop();
		int n1 = val.top(); val.pop(); 
		val.push(Calc(n1,n2,op.top())); op.pop();
	}
	cout<<val.top()<<endl;
}

/**********************************************
    计算后缀表达式
**********************************************/
int CalcPostfix(const char *str)
{
	stack<int> s;
	for(int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if(IsNum(c))
			s.push(c-'0');
		else
		{
			int n2 = s.top(); s.pop();
			int n1 = s.top(); s.pop(); 
			s.push(Calc(n1,n2,c));
		}
	}
	cout<<s.top()<<endl;
}

int main()
{
	CalcInfix("2*(3+6)/3");
	CalcInfix("2-3*4+5");		CalcPostfix("234*-5+");
	CalcInfix("(2-3)*(4+5)");	CalcPostfix("23-45+*");
	CalcInfix("2-(3*4+5)");		CalcPostfix("234*5+-");
}