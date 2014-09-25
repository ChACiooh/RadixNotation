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

using namespace std;

queue<int> myQ;	// global STL variable is so useful!

/*** The functions that help to make sets. ***/
int InputIntSet(int *set, int len);
int IntersectIntSet(int *set1, int len1, int *set2, int len2, int* res);
int UnionIntSet(int *set1, int len1, int *set2, int len2, int *res);
int DifferenceIntSet(int *set1, int len1, int *set2, int len2, int *res);

void printSet(int *set, int len)
{
    cout << "{ ";
    for(int i=0;i<len;i++)
        cout << set[i] << " ";
    cout << "}" << endl;
}

int main()
{
    do
    {
        // declaring variables
        char buffer[1000][1000];
        int i = 0, len1, len2, res_size;
        int setCnt, openCnt, closeCnt;
        int set1[MAX_SIZE], set2[MAX_SIZE], result[2*MAX_SIZE];
        char operator_;
        bool sign = false, error = false;
        len1 = len2 = res_size = setCnt = openCnt = closeCnt = 0;

        // process for input
        while(setCnt < 2)
        {
            int file_stream = scanf("%s", buffer[i]);
            if(file_stream == EOF)  return 0;
            if(i == 0 && buffer[i][0] != '{')	return 0;
            char temp = getchar();
            if(buffer[i][0] == '{')
            {
                if(sign)    return 0;
                openCnt++;
                if(openCnt > 1)
                {
                    error = true;
                    break;
                }
                i++;
                continue;
            }
            else if(buffer[i][0] == '}')
            {
                closeCnt++;
                if(openCnt == closeCnt)
                {
                    openCnt = closeCnt = 0;
                    setCnt++;
                }
                else
                {
                    error = true;
                    break;
                }

                sign = true;

                // Input the int_sets.
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
                if(temp == '\n')	break;
                continue;
            }
            else if((buffer[i][0] == '+' || buffer[i][0] == '-' || buffer[i][0] == '*') && sign)
            {
                operator_ = buffer[i][0];
                i++;
                sign = false;
                continue;
            }
            if(temp == '\n' && openCnt!=closeCnt)   return 0;

            int num;
            sscanf(buffer[i], "%d", &num);
            i++;
            myQ.push(num);
        }
        if(error)   continue;

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
                res_size = DifferenceIntSet(set1, len1, set2, len2, result);
                break;
            default:
                break;
        }
        printSet(result, res_size);
    }while(true);
	return 0;
}

int InputIntSet(int *set, int len)
{
    if(len == 0)    return 0;
	int i = 0;
	while(!myQ.empty())
	{
		int now = myQ.front();
		myQ.pop();
		if(i>0 && set[i-1] == now)  continue;
		// same elements are ignored.
		set[i++] = now;
	}
	sort(set, set+i);
	return i;
}

int IntersectIntSet(int *set1, int len1, int *set2, int len2, int *res)
{
    int cnt = 0;
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
				res[cnt++] = now;
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
    int cnt, i, j;
	cnt = i = j = 0;
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
			else if(set1[i] > set2[j])
			{
				res[cnt++] = set2[j++];
			}
			else
            {
                res[cnt++] = set1[i];
                i++;
                j++;
            }
		}
	}
	return cnt;
}

int DifferenceIntSet(int *set1, int len1, int *set2, int len2, int *res)
{
	int res_size = MAX_NUM(len1, len2), cnt = 0;
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
	delete[](intersect);
	return cnt;
}
