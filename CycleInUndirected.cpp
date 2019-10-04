#include <iostream>
using namespace std;

int grid[100][100];
int vis[100];
int n,m;

bool dfs(int src,int parent)
{
	vis[src] = 1;
	for(int i=0;i<n;i++)
	{
	   if(grid[src][i])
	   {
		if(!vis[i])
		{
		  if(dfs(i,src))
		  {
		    return true;
		  }
		}
		else
		{
			if(i != parent)
			 return true;
		}
           }
         }
return false;
}

bool iscycle()
{
for(int i=0;i<n;i++)
 if(!vis[i])
   if(dfs(i,-1))
     return true;
return false;
}

int main()
{
cin>>n>>m;
for(int i=0;i<m;i++)
{
int x,y;
cin>>x>>y;
grid[x][y] = 1;
grid[y][x] = 1;
}

if(iscycle())
{
cout<<"Cycle"<<endl;
}
else
cout<<"No Cycle"<<endl;


return 0;
}
