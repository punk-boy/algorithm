#include <iostream>
#include <stdio.h>
#include <cstring>
#include <malloc.h>
const int MAX = 9999;
#define N 1001
typedef long long LL;
using namespace std;
LL n, a[N], s[N],dp[N][N];

int optimized_encode()
{
    memset(dp, MAX, sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][i] = 0;
    for(int r=1;r<=n;r++) 
    {    
        for(int i=1;i+r<=n;i++)
        {
            int j = i+r;         
            for(int k=i;k<=j;k++)
            {
                int temp = dp[i][k] + dp[k+1][j] + s[j] - s[i-1];
                if(dp[i][j] > temp) dp[i][j] = temp;
            }
        }
    }  
    return dp[1][n];
}

int main()
{
    scanf("%d",&n);
    s[0] = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i] = s[i-1] + a[i];
    }
    int result = optimized_encode();
    printf("%d\n",result);
    return 0;
}