#include <bits/stdc++.h>

using namespace std;

/**********************************************
    栈计算中缀表达式
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

void Calc(stack<int> *val, stack<char> *op)
{
    int n2 = val->top(); val->pop();
    int n1 = val->top(); val->pop();
    char c = op->top(); op->pop();
    switch(c)
    {
        case '+':   val->push(n1+n2);   break;
        case '-':   val->push(n1-n2);   break;
        case '*':   val->push(n1*n2);   break;
        case '/':   val->push(n1/n2);   break;
    }
}

void CalcInfix(const char *str)
{
    cout<<str<<" = ";
    stack<int> val;
    stack<char> op;
    op.push('N');
    for(int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if(IsNum(c))
            val.push(c-'0');
        else if(c == '(')
            op.push(c);
        else if(c == ')')
        {
            while(op.top() != '(')
                Calc(&val, &op);
            op.pop();
        }
        else
        {
            while(OpLv(c) <= OpLv(op.top()))
                Calc(&val, &op);
            op.push(c);
        }
    }
    while('N' != op.top())
        Calc(&val, &op);
    cout<<val.top()<<endl;
}

int main()
{
    CalcInfix("2-3+5");
    CalcInfix("2*(3+6)/3");
    CalcInfix("2-3*4+5");       
    CalcInfix("(2-3)*(4+5)");   
    CalcInfix("2-(3*4+5)"); 

    return 0;   
}