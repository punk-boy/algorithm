#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <time.h>
#define range 10
typedef long long LL;
using namespace std;
LL ** s = NULL;
LL matrix_chain(int * p, int n)
{
	LL ** m = (LL **)malloc(sizeof(LL *) * n);
	s = (LL **)malloc(sizeof(LL *) * n);
	for(int i=0;i<n;i++)
	{
		m[i] = (LL *)malloc(sizeof(LL) * n);
		s[i] = (LL *)malloc(sizeof(LL) * n);
	}
	for(int i=0;i<n;i++)
		m[i][i] = 0;		
	for(int r=2;r<=n;r++)
	{
		for(int i=0;i<n-r+1;i++)
		{
			int j = i+r-1;
			int k = i;
			m[i][j] = m[i+1][j] + p[i-1] * p[k] * p[j];
			s[i][j] = i;
			for(k=i+1;k<=j;k++)
			{
				if(m[i][j] > m[i][k-1] + m[k][j] + p[i-1]*p[k]*p[j])
				{
					m[i][j] = m[i][k-1] + m[k][j] + p[i-1]*p[k]*p[j];
					s[i][j] = k;
				}
			}
		}
	}
    return m[1][n-1];
}

int main()
{
	long start, end;
	const int plen = 1000;
	int p[plen];
    for(int i=0;i<plen;i++)
        p[i] = rand() % range;
	
	
	int *** a;
	a = (int ***)malloc(sizeof(int **) * (plen-1));
	for(int i=0;i<plen-1;i++)
	{
		a[i] = (int **)malloc(sizeof(int *) * p[i]);
		for(int j=0;j<p[i];j++)
			a[i][j] = (int *)malloc(sizeof(int) * p[i+1]);
			
		// generatie the data
		for(int m=0;m<p[i];m++)
			for(int n=0;n<p[i+1];n++)
				a[i][m][n] = rand() % range;
				
		// outout the data
		/*for(int m=0;m<p[i];m++)
		{
			for(int n=0;n<p[i+1];n++)
			{
				printf("%d\t", a[i][m][n]);
			}
			printf("\n");
		}
		printf("----------------------------------------------------\n");
		*/
	}
	

	start = clock();
	LL result = matrix_chain(p, plen);
	end = clock();
	for(int i=0;i<plen;i++) printf("%d\t",p[i]);
	printf("\nresult = %ld\n", result);
	printf("time consumed : %.2lf seconds\n", 1.0 * (end - start) / CLOCKS_PER_SEC);

	
	return 0;
}


