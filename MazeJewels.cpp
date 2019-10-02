#include <iostream>
using namespace std;

int n,mx_jewels;
int a[100][100],maze[100][100],sol[100][100];

void dfs(int x,int y,int jewels)
{
  if(maze[x][y] == 3 || maze[x][y] == 1)
    return;

  if(maze[x][y] == 2)
    jewels += 1;

  maze[x][y] = 3;

  if(x == n-1 && y == n-1)
  {
    if(jewels > mx_jewels)
      mx_jewels = jewels;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         sol[i][j] = maze[i][j];
      }
    }
    return;
  //  if(a[x][y] == 2)
    //  maze[x][y] = 2;
  }
  if((x-1) >= 0)
    dfs(x-1,y,jewels);
  if((y-1) >= 0)
    dfs(x,y-1,jewels);
  if((x+1) < n)
    dfs(x+1,y,jewels);
  if((y+1) < n)
    dfs(x,y+1,jewels);

  if(a[x][y] == 2)
    maze[x][y] = 2;
  else if(a[x][y] == 0)
    maze[x][y] = 0;

}

int main()
{
  int t,idx = 1;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
          a[i][j] = -1;
          maze[i][j] = -1;
          sol[i][j] = -1;
       }
    }
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
          cin>>maze[i][j];
          a[i][j] = maze[i][j];
       }
    }
    mx_jewels = 0;
    dfs(0,0,0);
    cout<<"Case  #"<<idx<<endl;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         cout<<sol[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<mx_jewels<<endl;
    idx++;
  }

  return 0;
}
