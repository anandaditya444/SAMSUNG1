#include <iostream>
using namespace std;

int graph[100][100];
int col[200];

bool issafe(int src,int c,int v)
{
  for(int i=0;i<v;i++)
  {
    if(graph[src][i])
    {
      if(col[i] == c)
        return false;
    }
  }
return true;
}

bool isBipartite(int src,int v)
{
  if(src == v)
    return true;
  for(int c=1;c<=2;c++)
  {
    if(issafe(src,c,v))
    {
      col[src] = c;
      if(isBipartite(src + 1,v)
        return true;
      col[src] = 0;
    }
  }
return false;
}

int main()
{
  int v,e,x,y;
  cin>>v>>e;
  for(int i=1;i<=e;i++)
  {
    cin>>x>>y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  if(isBipartite(0,v))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;


return 0;
}
