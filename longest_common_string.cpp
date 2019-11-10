#include <stdio.h>
#include <iostream>
#include <string.h>

#define N 100
int dp[N][N];
char b[N][N];

inline int max(int a, int b)
{
	return a>b?a:b;
}

inline int min(int a, int b)
{
	return a<b?a:b;
}

int longest_common_string(char * x, char * y, int m, int n)
{
	for(int i=0;i<=m;i++) dp[i][0] = 0;
	for(int j=0;j<=n;j++) dp[0][j] = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				b[i][j] = 'O';
			}
			else if(dp[i-1][j] >= dp[i][j-1])
			{
				dp[i][j] = dp[i-1][j];
				b[i][j] = 'U';
			}
			else
			{
				dp[i][j] = dp[i][j-1];
				b[i][j] = 'L';
			}
		}
	}
	return dp[m][n];
}
void printLCS(char * x, int m, int n)
{
	if(m == 0 || n == 0)	
	{
		return ;
	}
	if(b[m][n] == 'O')
	{
		printLCS(x, m-1, n-1);
		printf("%c", x[m-1]);
	}
	else if(b[m][n] == 'U')
		printLCS(x, m-1, n);
	else if(b[m][n] == 'L')
		printLCS(x, m, n-1);
}
int main()
{
	int m = 7;
	int n = 6;
	char x[N] = "ABCBDAB";
	char y[N] = "BDCABA";
	printf("%s\n", x);
	printf("%s\n", y);
	int ret = longest_common_string(x, y, m, n);
	printf("---------------\n%d\n", ret);
	printLCS(x, m, n);
	printf("\n");
	return 0;
}