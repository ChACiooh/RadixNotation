#include <iostream>
#include <string>
#include <cstdio>
#define MAX_SIZE 100

using namespace std;

class calSet
{
	int* InputIntSet(int* buf, int buflen);  // Get one set input { ... } from cin.
	int* IntersectIntSet(const int* set1, int set1size, const int* set2, int set2size, int* set_ret, int buflen);
	int* UnionIntSet(const int* set1, int set1size, const int* set2, int set2size, int* set_ret, int buflen);
	int* DifferenceIntSet(const int* set1, int set1size, const int* set2, int set2size, int* set_ret, int buflen);
}

int main()
{
	do
	{
		int set1[MAX_SIZE], set2[MAX_SIZE], set_ret[MAX_SIZE];
		int *buf = new int[10000];
		int len = 0;
		calSet cs = new calSet;
		while(scanf("%d", &buf[len++])!=EOF)
		{
			
		}
	}
	return 0;
}

int* InputeIntSet(int* buf, int buflen)
{
	
}