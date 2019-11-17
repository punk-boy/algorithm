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

int shortest_common_string(char * x, char * y, int m, int n)
{
	dp[0][0] = 0;
	b[0][0] = 0;
	for(int i=1;i<=m;i++)
	{
		dp[i][0] = i;
		b[i][0] = 'U';
	}
	for(int j=1;j<=n;j++)
	{
		dp[0][j] = j;
		b[0][j] = 'L';
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				b[i][j] = 'O';
			}
			else if(dp[i-1][j] <= dp[i][j-1])
			{
				dp[i][j] = dp[i-1][j] + 1;
				b[i][j] = 'U';
			}
			else
			{
				dp[i][j] = dp[i][j-1] + 1;
				b[i][j] = 'L';
			}
		}
	}
	return dp[m][n];
}


void printSCS(char * x, char * y, int m, int n)
{
	if(m == 0 && n == 0)
	{
		return ;
	}
	if(b[m][n] == 'O')
	{
		printSCS(x, y, m-1, n-1);
		printf("%c", x[m-1]);
	}
	if(b[m][n] == 'U')
	{
		printSCS(x, y, m-1, n);
		printf("%c", x[m-1]);
	}
	if(b[m][n] == 'L')
	{
		printSCS(x, y, m, n-1);
		printf("%c", y[n-1]);
	}
}
int main()
{
	int m = 6;
	int n = 6;
	char x[N] = "CBADCB";
	char y[N] = "BCCCAD";
	printf("%s\n", x);
	printf("%s\n", y);
	int ret = shortest_common_string(x, y, m, n);
	printf("---------------\n%d\n", ret);
	printSCS(x, y, m, n);
	printf("\n");
	return 0;
}

/*
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

int shortest_common_string(char * x, char * y, int m, int n)
{
	dp[0][0] = 0;
	b[0][0] = 0;
	for(int i=1;i<=m;i++)
	{
		dp[i][0] = i;
		b[i][0] = 'U';
	}
	for(int j=1;j<=n;j++)
	{
		dp[0][j] = j;
		b[0][j] = 'L';
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				b[i][j] = 'O';
			}
			else if(dp[i-1][j] <= dp[i][j-1])
			{
				dp[i][j] = dp[i-1][j] + 1;
				b[i][j] = 'U';
			}
			else
			{
				dp[i][j] = dp[i][j-1] + 1;
				b[i][j] = 'L';
			}
		}
	}
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
	printf("======================================================\n");

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%c\t", b[i][j]);
		}
		printf("\n");
	}
	
	
	return dp[m][n];
}


void printSCS(char * x, char * y, int m, int n)
{
	if(m == 0 && n == 0)
	{
		return ;
	}
	if(b[m][n] == 'O')
	{
		printSCS(x, y, m-1, n-1);
		printf(".%d\t%d\t%c\n", m, n, x[m-1]);
	}
	if(b[m][n] == 'U')
	{
		printSCS(x, y, m-1, n);
		printf("%d\t%d\t%c\n", m, n, x[m-1]);
	}
	if(b[m][n] == 'L')
	{
		printSCS(x, y, m, n-1);
		printf("%d\t%d\t%c\n", m, n, y[n-1]);
	}
}



void printB(int m, int n)
{

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%c\t", b[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	/*
	int m = 7;
	int n = 6;
	
	char x[N] = "ABCBDAB";
	char y[N] = "BDCABA";
	
	

	int m = 6;
	int n = 6;

	char x[N] = "CBADCB";
	char y[N] = "BCCCAD";

	printf("%s\n", x);
	printf("%s\n", y);
	

	int ret = shortest_common_string(x, y, m, n);
	
	printf("---------------\n%d\n", ret);
	//printf("---------------\n");
	printSCS(x, y, m, n);
	printf("\n");
	
	
	return 0;
}







*/