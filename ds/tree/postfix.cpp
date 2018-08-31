#include <iostream>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

bool IsNum(char c)
{
	return c >= '0' && c <= '9';
}

int OpLv(char c)
{
	if(c == '(')				return 0;
	if(c == '+' || c == '-')	return 1;
	if(c == '*' || c == '/')	return 2;
	return -1;
}

void Infix2Postfix(const char *str)
{
	stack<char> s;
	for(int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
// case1：数字直接输出
		if(IsNum(c))
			cout<<c;
// case2：'('时直接入栈
		else if(c == '(')
			s.push(c);
// case3：')'时出栈直至遇到'('，'('也一并出栈
		else if(c == ')')
		{
			while(s.top() != '(')
				cout<<s.top(), s.pop();
			s.pop();
		}
// case4：运算符op
// 4.1：当前op优先级低于目前栈内op时，栈内op一直出栈直至'('或栈空
// 4.2 当前op入栈
		else
		{
			while((!s.empty()) && OpLv(s.top()) >= OpLv(c))
				cout<<s.top(), s.pop();
			s.push(c);
		}
	}
// 最后栈内op全部出栈
	while(!s.empty())
		cout<<s.top(), s.pop();
	cout<<endl;
}

int main()
{
	Infix2Postfix("2-3*4+5");
	Infix2Postfix("(2-3)*(4+5)");
	Infix2Postfix("2-(3*4+5)");
}