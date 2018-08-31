#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

void IsBlanced(const char *str)
{
	stack<char> s;
	for(int i = 0; i < strlen(str); i++)
	{
		int c = str[i];
		switch(c)
		{
			case '(':
			case '[':
			case '{':
				s.push(c);
				break;
			case ')':
				if(!s.empty() && s.top() == '(')	s.pop();	
				else								return;
				break;
			case ']':
				if(!s.empty() && s.top() == '[')	s.pop();
				else								return;
				break;
			case '}':
				if(!s.empty() && s.top() == '{')	s.pop();
				else								return;
				break;
			default:
				break;
		}
	}
	cout<<str<<" passed"<<endl;
}

int main()
{
	IsBlanced("{[()]}");
	IsBlanced("{[()]}}");
	return 0;
}