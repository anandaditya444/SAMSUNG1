#include <bits/stdc++.h>
using namespace std;

int fmwn(bool* visited,int* weight,int n)
{
  int min=-1;
  for(int i=0;i<n;i++)
  {
    if(!visited[i] && (min==-1 || weight[i]<weight[min]))
      min=i;
  }
  return min;
}

void dijkstra(int **edge,int n)
{
  bool* visited=new bool[n];
  int* weight=new int[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=false;
    weight[i]=INT_MAX;
  }
  weight[0]=0;
  for(int i=0;i<n-1;i++)
  {
    int mwn=fmwn(visited,weight,n);
    visited[mwn]=true;
    for(int j=0;j<n;j++)
    {
      if(edge[mwn][j])
      {
        if(!visited[j])
        {
          if((weight[mwn]+edge[mwn][j])<(weight[j]))
            weight[j]=weight[mwn]+edge[mwn][j];
        }
      }
    }
  }

for(int i=0;i<n;i++)
{
  cout<<i<<" "<<weight[i]<<endl;
}
}

int main()
{
  int n, E;
  cin >> n >> E;

  int** edge=new int*[n];
  for(int i=0;i<n;i++)
  {
    edge[i]=new int[n];
    for(int j=0;j<n;j++)
      edge[i][j]=0;
  }
  int u,v,w;
  for(int i=0;i<E;i++)
  {
    cin>>u>>v>>w;
    edge[u][v]=w;
    edge[v][u]=w;
  }
  dijkstra(edge,n);  
  return 0;
}