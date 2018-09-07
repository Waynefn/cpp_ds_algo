#include <iostream>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

/**********************************************
    栈计算后缀表达式
**********************************************/
bool IsNum(char c)
{
    return c >= '0' && c <= '9';
}

int OpLv(char c)
{
    if(c == '(' || c == ')')    return 0;
    if(c == '+' || c == '-')    return 1;
    if(c == '*' || c == '/')    return 2;
    return -1;
}

void Calc(stack<int> *val, char c)
{
    int n2 = val->top(); val->pop();
    int n1 = val->top(); val->pop();
    switch(c)
    {
        case '+':   val->push(n1+n2);   break;
        case '-':   val->push(n1-n2);   break;
        case '*':   val->push(n1*n2);   break;
        case '/':   val->push(n1/n2);   break;
    }
}

void CalcPostfix(const char *str)
{
    cout<<str<<" = ";
    stack<int> val;
    for(int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if(IsNum(c))
            val.push(c-'0');
        else
            Calc(&val, c);
    }
    cout<<val.top()<<endl;
}

int main()
{
    CalcPostfix("234*-5+");
    CalcPostfix("23-45+*");
    CalcPostfix("234*5+-");

    return 0;
}