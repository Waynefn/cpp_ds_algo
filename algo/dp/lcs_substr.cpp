#include <bits/stdc++.h>

using namespace std;

#define M (100)
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"|"; cout<<endl;}}
/**********************************************
    LCS(Longest common substring)
        x:ABCFBC
        y:ABFCAB
        LCS = 2 -> AB
    d[i][j]：x的前i串x[0]~x[i-1],y的前j串y[0]~y[i-1],得到的最长公共子串
    * 公共子串是连续的,一旦不匹配则需要重新计数lcs
**********************************************/
void lcs_result(const char *x, int last, int cnt)
{
    if(cnt == 0)
        return;
    lcs_result(x, last-1, cnt-1);
    cout<<x[last-1]<<endl;
}

void lcs(const char *x, const char *y)
{
    int m = strlen(x), n = strlen(y);
    int d[M][M];
    int last = 0;
    for(int i = 0; i <= m; i++)
        d[i][0] = 0;
    for(int j = 0; j <= n; j++)
        d[0][j] = 0;
    int max_lcs = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = 0;    // 一旦不匹配就归零，接下来重新计算
            if(d[i][j] > max_lcs)
            {
                max_lcs = d[i][j];
                last = i;   // 记录最长子串的末尾，输出时往前倒推即可得到结果
            }
        }
    }
    // PRINT_MATRIX(d, m+1, n+1);
    lcs_result(x, last, max_lcs);
    cout<<"LCS["<<x<<"]["<<y<<"] = "<<max_lcs<<endl;
}

int main()
{
    lcs("ABCBDAB", "BDCABC");

    return 0;
}