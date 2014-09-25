/***
 *** This program is to operate two sets.
 ***/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

#define MAX_SIZE 100
#define MAX_NUM(x,y)	((x)>(y))?(x):(y)
#define MIN_NUM(x,y)	((x)<(y))?(x):(y)

using namespace std;

queue<int> myQ;	//global STL variable is so useful!

int InputIntSet(int *set, int len);
int IntersectIntSet(int *set1, int len1, int *set2, int len2, int* res);
int UnionIntSet(int *set1, int len1, int *set2, int len2, int *res);
int DifferenceIntSet(int *set1, int len1, int *set2, int len2, int *res);

int main()
{
	char *buffer[1000];
	int i = 0, setCnt = 0, len1, len2, res_size;
	int *set1, *set2, *result;
	char operator_;

	// process for input
	while(scanf("%s", buffer[i]) != EOF || setCnt < 3)
	{
		if(i == 0 && buffer[i][0] != '{')	return 0;
		//if(buffer[i][0] == '\n')	break;
		if(buffer[i][0] == '{')
		{
			setCnt++;
			i++;
			continue;
		}
		else if(buffer[i][0] == '}')
		{
			switch(setCnt)
			{
				case 1:
					len1 = InputIntSet(set1, myQ.size());
					break;
				case 2:
					len2 = InputIntSet(set2, myQ.size());
					break;
				default:
					break;
			}
			i++;
			continue;
		}
		else if(buffer[i][0] == '+' || buffer[i][0] == '-' || buffer[i][0] == '*')
		{
			operator_ = buffer[i][0];
			i++;
			continue;
		}
		int num;
		sscanf(buffer[i], "%d", &num);
		i++;
		myQ.push(num);
	}
	
	// operating
	switch(operator_)
	{
		case '+':
			res_size = UnionIntSet(set1, len1, set2, len2, result);
			break;
		case '*':
			res_size = IntersectIntSet(set1, len1, set2, len2, result);
			break;
		case '-':
			res_size = IntersectIntSet(set1, len1, set2, len2, result);
			break;
		default:
			break;
	}
	printf("{ ");
	for(i = 0; i < res_size; i++)
	{
		cout << result[i] << " ";
	}
	cout << "}" << endl;
	return 0;
}

int InputIntSet(int *set, int len)
{
	int *temp = new int[len];
	int i = 0;
	while(!myQ.empty())
	{
		temp[i++] = myQ.front();
		myQ.pop();
	}

	set = new int[len];
	i = 0;
	while(!myQ.empty())
	{
		int now = temp[i];
		if(i>0 && set[i-1] == now)	continue;
		// same elements will be ignored.
		set[i] = now;
		i++;
	}
	sort(set, set+i);
	return i;
}

int IntersectIntSet(int *set1, int len1, int *set2, int len2, int *res)
{
	int res_size = MAX_NUM(len1, len2), cnt = 0;
	res = new int[res_size];
	int i, j;
	i = j = 0;
	while(i<len1)
	{
		int now = set1[i];
		j = 0;
		while(j<len2)
		{
			if(now == set2[j])
			{
				cnt++;
				res[i] = now;
				break;
				// if one element is discovered, then break.
				// because same elements were ignored in the set.
			}
			j++;
		}
		i++;
	}
	return cnt;
}

int UnionIntSet(int *set1, int len1, int *set2, int len2, int *res)
{
	int res_size = len1+len2, cnt = 0, i, j;
	res = new int[res_size];
	i = j = 0;
	while(i < len1 || j < len2)
	{
		if(i >= len1)	res[cnt++] = set2[j++];
		else if(j >= len2)	res[cnt++] = set1[i++];
		else
		{			
			if(set1[i] < set2[j])
			{
				res[cnt++] = set1[i++];
			}
			else
			{
				res[cnt++] = set2[j++];
			}
		}
	}
	return cnt;
}

int DeferenceIntSet(int *set1, int len1, int *set2, int len2, int *res)
{
	int res_size = MAX_NUM(len1, len2), cnt = 0;
	res = new int[res_size];
	int *intersect = new int[res_size];
	int len3 = IntersectIntSet(set1, len1, set2, len2, intersect);
	for(int i=0;i<len1;i++)
	{
		int now = set1[i];
		bool find = false;
		for(int j=0;j<len3;j++)
		{
			if(now == intersect[j])
			{
				find = true;
				break;
			}
		}
		if(!find)
			res[cnt++] = now;
	}
	return cnt;
}
