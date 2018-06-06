/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/ict_h28.pdf
选择科目5->棋盘路径探索 动态规划
	
*/
#include <iostream>

using namespace std;

#define M (3)	
#define N (4)
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"\t|"; cout<<endl;}}	

int R[M+1][N+1] = 
{
	{0,1,1,2,3},
	{1,2,3,2,1},
	{2,1,2,1,1},
	{3,1,2,1,0},
};

/***************************************
问题5.1
m*n的棋盘,每个点都有一个score.
从上图棋盘的(0,0)->(m,n)走"单调路径",经过的各个点得到的最大score
单调路径:每一步路径都必须更靠近终点
	0 1 1 2 3
	1 2 3 2 1
	2 1 2 1 1
	3 1 2 1 0
结果:
	0	1	2	4	7
	1	3	6	8	9
	3	4	8	9	10
	6	7	10	11	11
其中一条最大score的路径: 11<-11<-9<-8<-6<-3<-1<-0 保证总是选择score较大的方向即可
* i是down方向移动,j是right方向移动
代码思路:动态规划思想
	定义问题
		f[i][j]:起点到[i][j]能够获得的最大score
	状态转移
		f[i][j] = f[i-1][j] + R[i][j]	当左侧score更大时,选择左侧的score加上当前R[i][j]
				= f[i][j-1] + R[i][j]	当上面score更大时,选择上面的score加上当前R[i][j]
	子问题求解
		f[0][0] = 0
		f[i][0] = f[i-1][0] + R[i][0]	因为单调路径,第一行的点[i][0]只能从它的左侧出发到达	
		f[0][j] = f[0][j-1] + R[0][j] 	因为单调路径,第一列的点[0][j]只能从它的上面出发到达
***************************************/
void test_1()
{
	int f[M+1][N+1];
	f[0][0] = 0;
	for(int i = 1; i <= M; i++)
		f[i][0] = f[i-1][0] + R[i][0];
	for(int j = 1; j <= N; j++)
		f[0][j] = f[0][j-1] + R[0][j];

	for(int i = 1; i <= M; i++)
		for(int j = 1; j <= N; j++)
			f[i][j] = max(f[i][j-1]+R[i][j], f[i-1][j]+R[i][j]);
	cout<<"max score = "<<f[M][N]<<endl;
	PRINT_MATRIX(f,M+1,N+1);
}

/***************************************
问题5.2
问题发生小改动,只有在转方向时才允许加上R[i][j]的score值
	0 1 1 2 3
	1 2 3 2 1
	2 1 2 1 1 
	3 1 2 1 0
right_down方案:
	定义问题
		right[i][j]:下一步right的话,起点到[i][j]的最大score
		down[i][j]:下一步down的话,起点到[i][j]的最大score
	状态转移
		right[i][j] = right[i][j-1]				下一步要right,前一步也是right的,没有转弯,不能加R[i][j]		
					= down[i-1][j] + R[i][j]	下一步要right,前一步是down的,发生转弯,可以加R[i][j]
		down[i][j] 	= down[i-1][j]				下一步要down,前一步也是down的,没有转弯,不能加R[i][j]
					= right[i][j-1] + R[i][j]	下一步要down,前一步是right的,发生转弯,可以加R[i][j]
	子问题求解
		right[0][0] = down[0][0] = 0
		right[i][0] = R[i][0]		因为单调路径,起点到[i][0]只能down,下一步要right,发生转弯,可以加上R[i][0]
		right[0][j] = 0				因为单调路径,起点到[0][j]只能right,下一步要right,从未转弯,所以为0
		left[i][0] = 0				因为单调路径,起点到[i][0]只能down,下一步要down,从未转弯,所以为0
		left[0][j] = R[0][j]		因为单调路径,起点到[0][j]只能right,下一步要down,发生转弯,可以加上R[0][j]

left_up方案:
	定义问题
		left[i][j]:前一点是left的话,起点到[i][j]的最大score (下一步未定,故R[i][j]尚未计算)
		up[i][j]:前一点是up的话,起点到[i][j]的最大score (下一步未定,故R[i][j]尚未计算)
	状态转移
		left[i][j] = left[i][j-1]			[i][j]的前一步是[i][j-1],[i][j-1]也由left得到的话,[i][j-1]没有转弯,不能加R[i][j-1]
				   = up[i][j-1] + R[i][j-1]	[i][j]的前一步是[i][j-1],[i][j-1]由up得到的话,[i][j-1]发生转弯,可以加R[i][j-1]
		up[i][j] = up[i-1][j]				[i][j]的前一步是[i-1][j],[i-1][j]也由up得到的话,[i-1][j]没有转弯,不能加R[i-1][j]
				 = left[i-1][j] + R[i-1][j]	[i][j]的前一步是[i-1][j],[i-1][j]由left得到的话,[i-1][j]发生转弯,可以加R[i-1][j]
	子问题求解
		left[0][0] = up[0][0] = 0
		left[i][0] = left[0][j] = 0
		up[i][0] = up[0][j] = 0
结果:
	0	1	2	4	7
	1	3	6	8	9
	3	4	8	9	10
	6	7	10	11	11
其中一条最大score的路径: 11<-11<-9<-8<-6<-3<-1<-0 保证总是选择score较大的方向即可
***************************************/
void test_2_right_down()
{
	int f_right[M+1][N+1], f_down[M+1][N+1];
	f_right[0][0] = 0; f_down[0][0] = 0;

	for(int i = 1; i <= M; i++)
	{
		f_right[i][0] = R[i][0];
		f_down[i][0] = 0;
	}
	for(int j = 1; j <= N; j++)
	{
		f_right[0][j] = 0;
		f_down[0][j] = R[0][j];
	}

	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			f_right[i][j] = max(f_right[i][j-1], f_down[i-1][j] + R[i][j]);
			f_down[i][j] = max(f_down[i-1][j], f_right[i][j-1] + R[i][j]);
		}
	}
	cout<<"max score = "<<max(f_right[M][N], f_down[M][N])<<endl;
}

void test_2_left_up()
{
	int f_left[M+1][N+1], f_up[M+1][N+1];
	for(int i = 1; i <= M; i++)
	{
		f_left[i][0] = 0;
		f_up[i][0] = 0;
	}
	for(int j = 1; j <= N; j++)
	{
		f_left[0][j] = 0;
		f_up[0][j] = 0;
	}
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			f_left[i][j] = max(f_left[i][j-1], f_up[i][j-1] + R[i][j-1]);
			f_up[i][j] = max(f_up[i-1][j], f_left[i-1][j] + R[i-1][j]);
		}
	}
	cout<<"max score = "<<max(f_left[M][N], f_up[M][N])<<endl;
}

int main()
{
	test_1();
	test_2_right_down();
	test_2_left_up();
	return 0;
}