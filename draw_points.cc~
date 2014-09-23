#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int x, y, save_x, save_y;
	char **x_y_plane;
	while(true)
	{
		cin >> x >> y;
		if(x<0 || y<0)	break;

		// initializing array
		if(x_y_plane == null)
		{
			x_y_plane = (char**)malloc(sizeof(char*)*(y+1));
			for(int i=0;i<=y;i++)
				x_y_plane[i] = (char*)malloc(sizeof(char)*(x+1));
		}
		else
		{
			if(y > save_y)
			{
				x_y_plane = (char**)realloc(sizeof(char*)*(y+1));
				if(x > save_x)
				{
					for(int i=save_y;i<=y;i++)
						x_y_plane[i] = (char*)malloc(sizeof(char)*(x+1));
				}
				else
				{
					for(int i=save_y;i<=y;i++)
						x_y_plane[i] = (char*)malloc(sizeof(char)*(save_x+1));
				}
			}
			else if(x > save_x)
			{
				if(y > save_y)
				{
					x_y_plane = (char**)realloc(sizeof(char*)*(y+1));
					for(int i=0;i<=y;i++)
					{
						if(x_y_plane[i] == null)	x_y_plane[i] = (char*)malloc(sizeof(char)*(x+1));
						else	x_y_plane[i] = (char*)realloc(sizeof(char)*(x+1));
					}
				}
				else
				{
					for(int i=0;i<=save_y;i++)
						x_y_plane[i] = (char*)realloc(sizeof(char)*(x+1));
				}
			}
			
		}

		// drawing
		for(int i=0;i<=y;i++)
		{
			for(int j=0;j<=x;j++)
			{
				if(i == y && j == x)	x_y_plane[i][j] = '*';
				if(x_y_plane[i][j] == '*')	continue;
				else	x_y_plane[i][j] = '.';
			}
			cout << x_y_plane[i] << endl;
		}

		// save previous x, y
		save_x = x;
		save_y = y;
	}
	free(x_y_plane);
	return 0;
}
