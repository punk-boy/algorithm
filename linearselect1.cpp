#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

int ordinaryselect(vector<int> & s, int low, int high, int k)
{
	sort(s.begin(), s.end());
	return s[k];
}


int linearselect(vector<int> & s, int low, int high, int k)
{
	int n = high - low + 1;
	if (n < 75)
	{
		sort(s.begin(), s.end());
		return s[k];
	}
	
	int q = (int)ceil(1.0 * n / 5);
	
	vector<vector<int> > inner(q, vector<int>(5, 0));
	
	for(int i=low;i<=high;i++)
		inner[i/5][i%5] = s[i];
		
	for(int i=0;i<inner.size();i++)
		sort(inner.begin(), inner.end());
	
	// generate the M & x
	vector<int> M;
	for(int i=0;i<inner.size();i++)
	{
		int center = (int)ceil(1.0 * inner[i].size() / 2);
		M.push_back(inner[i][center]);
	}
		
	int x = linearselect(M, 0, M.size()-1, (int)ceil(1.0 * q / 2));
	
	//generate the A, B, C
	vector<int> A, B, C;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] < x)
			A.push_back(s[i]);
		else if(s[i] == x)
			B.push_back(s[i]);
		else
			C.push_back(s[i]);
	}
	
	
	if(A.size() > k)
		return linearselect(A, 0, A.size()-1, k);
	else if(A.size() + B.size() < k)
		return linearselect(C, 0, C.size()-1, k-A.size()-B.size());
	else
		return x;
}


int main()
{
	// global variables
	double start, end, gen, ls, os;
	const int LEN = 1024;
	vector<int> array(LEN);
	int k = LEN / 2;
	int result, lresult, oresult;
	
	// generate the array data
	start = clock();
	srand((unsigned)time(NULL));
	for (int i=0;i<LEN;i++)
		array[i] = rand() % 1024 + 1;
	/*Sleep(5000);*/
	end = clock();
	gen = end - start;
	
	
	// output the array data;
	for(int i=0;i<1024;i++)
	{
		printf("%d\t", array[i]);
	}
	
	// linear select
	start = clock();
	lresult = result = linearselect(array, 0, array.size() - 1, k);
	end = clock();
	ls = end - start;
	
	// ordinary slect (powered by quick sort)
	start = clock();
	oresult = result = ordinaryselect(array, 0, array.size() - 1, k);
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



