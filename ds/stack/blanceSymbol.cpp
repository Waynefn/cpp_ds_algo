#include <bits/stdc++.h>

using namespace std;

/**********************************************
    栈判断符号平衡
**********************************************/
bool IsBlanced(const char *str)
{
    cout<<str<<" ";
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
                if(!s.empty() && s.top() == '(')    s.pop();    
                else                                return false;
                break;
            case ']':
                if(!s.empty() && s.top() == '[')    s.pop();
                else                                return false;
                break;
            case '}':
                if(!s.empty() && s.top() == '{')    s.pop();
                else                                return false;
                break;
            default:
                break;
        }
    }
    return s.empty();   // 注意确认栈是否为空
}

int main()
{
    cout<<IsBlanced("{[()]}")<<endl;
    cout<<IsBlanced("{[()]}}")<<endl;
    cout<<IsBlanced("{{[()]}")<<endl;
    return 0;
}