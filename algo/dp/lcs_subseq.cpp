#include <bits/stdc++.h>

using namespace std;

#define M (100)
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"|"; cout<<endl;}}
/**********************************************
    LCS(Longest common subsequence)
        x:ABCBDAB
        y:BDCABC
        LCS = 4 -> BCAB,BDAB
    d[i][j]：x的前i串x[0]~x[i-1],y的前j串y[0]~y[i-1],得到的最长公共子串
    **尚未引入flag[][]，无法正确显示所有LCS结果
**********************************************/
void lcs_result(int d[M][M], const char *x, int i, const char *y, int j)
{
    while(i && j)
    {
        if(x[i-1] == y[j-1])
        {
            cout<<x[i-1]<<"-";
            i--,j--;
        }
        else
        {
            if(d[i-1][j] > d[i][j-1])       // 找到相对大的上一层子问题
                i--;
            else if(d[i-1][j] < d[i][j-1])  // 找到相对大的上一层子问题
                j--;
            else                            // 两个子问题相等，则递归去寻找所有可能性
            {
                lcs_result(d, x, i-1, y, j);
                lcs_result(d, x, i, y, j-1);
                return;
            }
        }
    }
}

void lcs(const char *x, const char *y)
{
    int m = strlen(x);
    int n = strlen(y);
    int d[M][M];
    for(int i = 0; i <= m; i++)
        d[i][0] = 0;
    for(int j = 0; j <= n; j++)
        d[0][j] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(x[i-1] == y[j-1])    d[i][j] = d[i-1][j-1] + 1;
            else                    d[i][j] = max(d[i-1][j], d[i][j-1]);
    // PRINT_MATRIX(d, m+1, n+1);
    lcs_result(d, x, m, y, n); cout<<endl;
    cout<<"LCS["<<x<<"]["<<y<<"] = "<<d[m][n]<<endl;
}

int main()
{
    lcs("ABCBDAB", "BDCABC");

    return 0;
}