#include <iostream>
using namespace std;

int n,m;
int grid[100][100];
int vis[100];

bool findloop(int src)
{
  if(vis[src] == 1)
   return true;
  if(vis[src] == 2)
   return false;
  vis[src] = 1;
  for(int i=0;i<n;i++)
  {
    if(grid[src][i])
    {
        if(findloop(i))
        {
           return true; 
        }
    }
  }
 vis[src] = 2;
return false;
  
}

bool iscycle()
{
for(int i=0;i<n;i++)
{
  if(!vis[i])
  {
    if(findloop(i))
    {
      return true;
    }
  }
}
return false;
}

int main()
{
cin>>n>>m;
// for(int i=0;i<n;i++)
// {
// 	for(int j=0;j<m;j++)
// 	{
// 		cin>>grid[i][j];
// 	}
// }

for(int i=0;i<m;i++)
{
int x,y;
cin>>x>>y;
grid[x][y] = 1;
//grid[y][x] = 1;
}

if(iscycle())
cout<<"Cycle"<<endl;
else
cout<<"No cycle"<<endl;


return 0;
}
