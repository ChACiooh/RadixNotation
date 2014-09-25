#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int x, y, max_x, max_y;
	max_x = max_y = 0;
	vector< pair<int, int> > points;
	while(true)
	{
		cin >> x >> y;
		if(x<0 || y<0)	break;
		if(max_x<x)	max_x = x;
		if(max_y<y)	max_y = y;
		points.push_back(make_pair(x, y));
		for(int i=0;i<=max_y;i++)
		{
			for(int j=0;j<=max_x;j++)
			{
				bool marked = false;
				for(int k=0;k<points.size();k++)
				{
					if(j == points[k].first && i == points[k].second)
					{
						marked = true;
						cout << "*";
						break;
					}
				}
				if(marked)	continue;
				else cout << ".";
			}
			cout << endl;
		}
	}
	return 0;
}
