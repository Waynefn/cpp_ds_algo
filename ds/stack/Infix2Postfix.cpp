#include <iostream>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

/**********************************************
    中缀转后缀表达式
**********************************************/
bool IsNum(char c)
{
	return c >= '0' && c <= '9';
}

int OpLv(char c)
{
	if(c == '(' || c == ')')    return 0;
	if(c == '+' || c == '-')	return 1;
	if(c == '*' || c == '/')	return 2;
	return -1;
}

void Infix2Postfix(const char *str)
{
	cout<<str<<" = ";
	stack<char> s;
	s.push('N');
	for(int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
// case1：数字直接输出
		if(IsNum(c))
			cout<<c;
		else if(c == '(')
			s.push(c);
		else if(c == ')')
		{
			while(s.top() != '(')
				cout<<s.top(), s.pop();
			s.pop();
		}
		else
		{
			while(OpLv(c) <= OpLv(s.top()))
				cout<<s.top(), s.pop();
			s.push(c);
		}
	}
	while('N' != s.top())
		cout<<s.top(), s.pop();
	cout<<endl;
}

int main()
{
	Infix2Postfix("2-3*4+5");		// 234*-5+
	Infix2Postfix("(2-3)*(4+5)");	// 23-45+*
	Infix2Postfix("2-(3*4+5)");		// 234*5+-
	Infix2Postfix("2-3+5");			// 23-5+
}