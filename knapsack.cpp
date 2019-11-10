#include <stdio.h>
#include <iostream>
#include <string.h>

#define N 100
int dp[N][N];

inline int max(int a, int b)
{
	return a>b?a:b;
}

inline int min(int a, int b)
{
	return a<b?a:b;
}
int knapsack(int * v, int * w, int c, int n)
{
	int jmax = min(w[n-1]-1, c);
	for(int j=0;j<=jmax;j++)
		dp[n-1][j] = 0;
	for(int j=w[n-1];j<=c;j++)
		dp[n-1][j] = v[n-1];	
	for(int i=n-2;i>=1;i--)
	{
		int jMax = min(w[i]-1, c);
		for(int j=0;j<jMax;j++)
			dp[i][j] = dp[i+1][j];
		for(int j=w[i];j<=c;j++)
			dp[i][j] = max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
	}
	dp[0][c] = dp[1][c];
	if(c >= w[1])
		dp[0][c] = max(dp[0][c], dp[1][c-w[0]]+v[0]);
	return dp[0][c];
}

int main()
{
	int n = 4;
	int c = 9;
	int w[N] = {2, 3, 4, 5};
	int v[N] = {3, 4, 5, 7};
	int ret = knapsack(v, w, c, n);
	printf("%d\n", ret);
	return 0;
}







