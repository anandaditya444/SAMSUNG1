#include <iostream>
using namespace std;

int vis[100];
int grid[100][100];
int ans[100];
int idx = 0;
int n,m;

void dfs(int src)
{
vis[src] = 1;
for(int i=0;i<n;i++)
 if(grid[src][i])
   if(!vis[i])
     dfs(i);

ans[idx++] = src;
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

for(int i=0;i<n;i++)
 if(!vis[i])
  dfs(i);
for(int i=n-1;i>=0;i--)
cout<<ans[i]<<" ";
cout<<endl;



return 0;
}
