#include <iostream>
using namespace std;

int a[100][100];
int vis[100][100];
int loc[100][2];
int sol = 999999,longest = 0;
int row,col;

bool issafe(int x,int y)
{
	return (x >= 0 && x < row && y >= 0 && y < col && a[x][y] == 1 && vis[x][y] == 0);
}

bool research(int x,int y,int x1,int y1,int count)
{
	if(x == x1 && y == y1)
	{
		vis[x][y] = 1;
		sol = min(sol,count);
		return true;
	}

	if(issafe(x,y))
	{
		vis[x][y] = 1;
		if(research(x-1,y,x1,y1,count+1))
			return true;
		if(research(x,y-1,x1,y1,count+1))
			return true;
		if(research(x+1,y,x1,y1,count+1))
			return true;
		if(research(x,y+1,x1,y1,count+1))
			return true;
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cin>>a[i][j];
				vis[i][j] = 0;
			}
		}
		int rare;
		cin>>rare;
		for(int i=0;i<rare;i++)
		{
			cin>>loc[i][0]>>loc[i][1];
		}

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(a[i][j] == 1)
				{
					for(int k=0;k<rare;k++)
					{
						if(research(loc[k][0],loc[k][1],i,j,0))
						{
							longest = max(longest,sol);
						}
						sol = 999999;
						for(int i=0;i<100;i++)
						{
							for(int j=0;j<100;j++)
							{
								vis[i][j] = 0;
							}
						}
					}
					longest = 0;
				}
			}
		}
		cout<<longest<<endl;
	}



	return 0;
}