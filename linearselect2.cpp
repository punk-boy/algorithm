#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <malloc.h>

using namespace std;

int ordinaryselect(int * s, int low, int high, int k)
{
	int n = high - low + 1;
	sort(s, s+n);
	return s[k];
}


int linearselect(int * s, int low, int high, int k)
{
    
	int n = high - low + 1;
    /*printf("------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", s[i]);
    }
    printf("\n");*/


	if (n < 75)
	{
		sort(s, s+n);
		return s[k];
	}
	
	int q = (int)ceil(1.0 * n / 5);
    //printf("q = %d\n", q);
	
	//int inner[][] = new int[q][6];
	int ** inner;
    // inner = new int*[q];-----------------------------------
    inner = (int **)malloc(sizeof(int *) * q);
    // for(int i=0;i<q;i++) inner[i] = new int[6]; ---------------------------------
    for(int i=0;i<q;i++) inner[i] = (int *)malloc(sizeof(int) * 6);

	
	for(int i=0;i<q;i++)
		inner[i][5] = 0;
	
	for(int i=0;i<n;i++)
	{
		inner[i/5][i%5] = s[i];
		inner[i/5][5] ++; 
	}
		
	for(int i=0;i<q;i++)
		sort(inner[i], inner[i]+5);
	
	// generate the M & x
	// int *M = new int[q]; ------------------------------
    int * M = (int *)malloc(sizeof(int) * q);
	for(int i=0;i<q;i++)
	{
		int center = (int)ceil(1.0 * inner[i][5] / 2);
		M[i] = inner[i][center];
	}
		
	int x = linearselect(M, 0, q-1, (int)ceil(1.0 * q / 2));
    //printf("x=%d\n", x);	
	//generate the A, B, C
	int MAX_LEN = (int)ceil(1.0 * 3 * n / 4);
	// int * A = new int[MAX_LEN], *B = new int[MAX_LEN], *C = new int[MAX_LEN], la = 0, lb = 0, lc = 0; ----------------------------------
    int * A = (int *)malloc(sizeof(int) * MAX_LEN), la = 0;
    int * B = (int *)malloc(sizeof(int) * MAX_LEN), lb = 0;
    int * C = (int *)malloc(sizeof(int) * MAX_LEN), lc = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] < x)
			A[la++] = s[i];
		else if(s[i] == x)
		{
			B[lb++] = s[i];
		}	
		else
		{
			C[lc++] = s[i];
		}
	}
	
	
	if(la > k)
		return linearselect(A, 0, la-1, k);
	else if(la + lb < k)
		return linearselect(C, 0, lc-1, k-la-lb);
	else
		return x;
}


int main()
{
	// global variables
	double start, end, gen, ls, os;
	const int LEN = 102400;
	const int range = 1024;
	int * array = new int[LEN];
	int k = LEN / 2;
	int result, lresult, oresult;
	
	// generate the array data
	start = clock();
	srand((unsigned)time(NULL));
	for (int i=0;i<LEN;i++)
		array[i] = rand() % range + 1;
	/*Sleep(5000);*/
	end = clock();
	gen = end - start;
	
	
	// output the array data;
	for(int i=0;i<LEN;i++)
	{
		printf("%d\t", array[i]);
	}
    
	
	// linear select
	start = clock();
    lresult = result = linearselect(array, 0, LEN - 1, k);
	end = clock();
	ls = end - start;
	
	// ordinary slect (powered by quick sort)
	start = clock();
	oresult = result = ordinaryselect(array, 0, LEN - 1, k);
	end = clock();
	os = end - start;
	
	
	// output the time consume
	printf("\n");
	
	printf("* generating     time consumed : %.2lf seconds\n", gen / CLOCKS_PER_SEC);
	printf("* linearselect   time consumed : %.2lf seconds\n", ls  / CLOCKS_PER_SEC);
	printf("     result : %d\n", lresult);
	printf("* ordinaryselect time consumed : %.2lf seconds\n", os / CLOCKS_PER_SEC);
	printf("     result : %d\n", oresult);
	return 0;
}



