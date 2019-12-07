#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define N 100

int greed_algo(int * d, int * w, const int n)
{
    int tmp, totalReduce = 0, i, j;
    int finished[24+1];
    int no[N];
    memset(finished, 0, sizeof(finished));
    for(i=0;i<n;i++) no[i] = i+1;
    /*------------- sort array w and d by w -------------*/
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(w[j] < w[j+1])
            {
                tmp = w[j];
                w[j] = w[j+1];
                w[j+1] = tmp;

                tmp = d[j];
                d[j] = d[j+1];
                d[j+1] = tmp;

                tmp = no[j];
                no[j] = no[j+1];
                no[j+1] = tmp;
            }
        }
    }
    /*------------- arrange work -------------*/
    for(i=0;i<n;i++) // the rank of the task
    {
        for(j=d[i];j>0;j--) // the time
        {
            if(finished[j] == 0)
            {
                finished[j] = no[i]; // finished the job no[i] at time j
                printf("no=%d\tt=%d\t * d=%d\tw=%d\n", no[i], j, d[i], w[i]);
                break;
            }
        }
        if(j == 0) totalReduce += w[i];
    }
    /*------------- print result -------------*/
    printf("Table of (Task No)/(The Time to solve It)-----------\nTask No:\t");
    for(int i=0;i<n;i++)
        printf("%d\t", no[i]);
    printf("\nTime   :\t");
    for(i=0;i<n;i++)
    {
        for(j=1;j<=24;j++)
        {
            if(finished[j] == no[i])
            {
                printf("%d\t", j);
                break;
            }
            if(j == 24)
            {
                printf("0\t");
                break;
            }
        }
    }
    printf("\n");
    /*------------- print another result -------------*/
    printf("Table of (Time)/(The Task we need to solve in that time)-----------\nTime:\t");
    for(i=1;i<=24;i++)
        printf("%d\t", i);
    printf("\nT No:\t");
    for(i=1;i<=24;i++)
        printf("%d\t", finished[i]);
    printf("\n");
    return totalReduce;
}

int main()
{

    /*
    int n = 8;
    int d[N] = {10, 8, 9, 3, 2, 5, 3, 8};
    int w[N] = {5, 10, 10, 3, 2, 5, 8, 9};
    */


    int n = 30;
    int d[N] = {
        2, 10, 15, 6, 7, 19, 14, 17, 12, 16, 
        24, 3, 18, 18, 3, 12, 9, 21, 21, 21,
        15, 16, 9, 2, 17, 18, 19, 20, 9, 20,
    };

    int w[N] = {
        21, 22, 14, 17, 20, 19, 20, 15, 21, 30,
        20, 23, 12, 11, 19, 13, 16, 10, 14, 13,
        12, 14, 11, 18, 18, 19, 15, 14, 13, 10,

    };


    int res = greed_algo(d, w, n);

    printf("----------------\ntotalReduce:%d\n", res);

    return 0;
}









