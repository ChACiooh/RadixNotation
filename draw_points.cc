#include <iostream>

using namespace std;

char arr[1000][1000];

int main()
{
	int x, y, max_x, max_y;
	max_x = max_y = 0;
	while(true)
	{
		cin >> x >> y;
		if(x<0 || y<0)	break;
		if(max_x<x)	max_x = x;
		if(max_y<y)	max_y = y;

		for(int i=0;i<=max_y;i++)
		{
			for(int j=0;j<=max_x;j++)
			{
				if(j == x && y == i)	arr[i][j] = '*';
				if(arr[i][j] == '*')	continue;
				else	arr[i][j] = '.';
			}
			cout << arr[i] << endl;
		}
	}
	return 0;
}
