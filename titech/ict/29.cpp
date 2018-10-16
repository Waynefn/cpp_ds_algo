/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/ict_h29.pdf
选择科目5->最佳行动方式(DFS搜索)

1.	0~3的有向路径
	<0,1,3>
	<0,2,3>
	<0,1,2,3>
2.	
	a)行动数组为[0,2,0,0,0]时<1,2,3>的迁移score
		0.8 * 0.7 = 0.56
	b)行动数组为[0,0,0,0,0]和[1,1,0,0,0]时1~3的迁移score分别多大
		1~3的路径为<1,3> + <1,2,3>
		[0,0,0,0,0] = 0.4 + 0.42 = 0.82
			<1,3> = 0.4
			<1,2,3> = 0.6 * 0.7 = 0.42
		[1,1,0,0,0] = 0.9 + 0.07 = 0.97
			<1,3> = 0.9
			<1,2,3> = 0.1 * 0.7 = 0.07
		[1,1,0,0,0]模式的score更大
	c)[0,0,0,0,0]模式下,x1=1~3的分数,x2=2~3的分数,求y=0~3的分数(关键!后续解题的思路)
		x1 = <1,3> + <1,2,3> = <1,3> + <1,2>*<2,3> = 0.4+0.6*0.7=0.82
		x2 = <2,3> = 0.7
		0~3的路径分数  y = <0,1,3> + <0,2,3> + <0,1,2,3>
						= <0,1>*<1,3> + <0,2>*<2,3> + <0,1>*<1,2>*<2,3>
						= 0.8*0.4 + 0.2*0.7 + 0.8*0.6*0.7
						= 0.32+0.14+0.336 = 0.796
		y = <0,1,3> + <0,2,3> + <0,1,2,3>
		  = <0,1>*<1,3> + <0,2>*<2,3> + <0,1>*<1,2>*<2,3>
		  = <0,1>*(<1,3> + <1,2>*<2,3>) + <0,2>*<2,3>
		  = <0,1>*x1 + <0,2>*x2	
		  = 0.8*0.82 + 0.2*0.7 = 0.796
*/	
#include <iostream>

using namespace std;

#define N (10)

int numArcs(int s);						// 与s相连的顶点个数
int nextNode(int s, int i);				// 与s相连的第i个顶点
int numActions(int s);					// s可以选择的行动case
float arcScore(int s, int a, int i);	// s选择行动a方式到第i个顶点的score

int policy[N] = {0};	// 最大分数行动方式的结果
int visited[N] = {0};
float maxScore[N];		// maxScore[i]记录顶点i到goal的最大分数

// 找到curPos~goal的最大分数行动方式policy[]
float optPolicy(int curPos, int goal)
{
	int i, a, opt;
	float acc, max;

// 已经访问过的顶点,说明起点到curPos的分数已经求得,直接返回分数即可
	if(visited[curPos] == 1)
		return maxScore[curPos];

// 访问到goal时,无需计算,直接返回1
	if(curPos == goal)				// coding 现在的顶点等于goal
	{
		policy[curPos] = 0;			// goal无需再行动,行动方式默认为0
		maxScore[curPos] = 1.0;	
		visited[curPos] = 1;
		return 1.0;
	}

//	DFS方式搜索,对于{0,3}的最大score求解,先递归地求解终点3的前一个节点2的score{2,3},得到结果后再逐步回溯求解
	for(i = 0; i < numArcs(curPos); i++)
		if(visited[curPos] == 0)
			maxScore[nextNode(curPos, i)] = optPolicy(nextNode(curPos, i), goal);	// coding

//	找到最大价值的行动方式
	opt = 0; max = 0.0;
	for(a = 0; a < numActions(curPos); a++)	// 遍历每种行动方式,最后寻找最大值
	{
		acc = 0.0;
		/*	
			curPos = 0, goal = 3
			{0~3} = <0,1>*{1,3} + <0,2>*{2,3} ...
			i : 是0可以到达的点1和2,根据题意每种路径的分数都要考虑
			arcScore(curPos, a, i) : 0走到下一步,即<0,1>和<0,2>在a方式下的分数
			maxScore[nextNode(curPos, i)] : i=1和i=2到goal的最大值,类比于已经计算得到的{1,3}和{2,3}
			acc = acc + ... : 0~i~3所有可能路径的分数之和
		*/
		for(i = 0; i < numArcs(curPos); i++)
			acc = acc + arcScore(curPos, a, i) * maxScore[nextNode(curPos, i)];	// coding
		if(max < acc)
		{
			max = acc	// coding
			opt = a;
		}
	}
	policy[curPos] = opt;
	maxScore[curPos] = max;
	visited[curPos] = 1;
	return max;
}

int main()
{

	return 0;
}