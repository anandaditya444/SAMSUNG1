#include <iostream>
using namespace std;

int t,n,m;
int graph[100][100];
int path[100];

bool issafe(int v,int pos)
{
if(graph[path[pos-1]][v] == 0)
 return false;
for(int i=0;i<pos;i++)
if(path[i] == v)
 return false;

return true;
}

bool hamil(int pos)
{
if(pos == n)
{
if(graph[path[pos-1]][path[0]] == 1)
 return true;
else
 return false;
}

for(int v=1;v<n;v++)
{
if(issafe(v,pos))
{
path[pos] = v;
if(hamil(pos+1))
 return true;
path[pos] = -1;
}
}
return false;
}

int main()
{
cin>>t;
while(t--)
{
cin>>n>>m;
for(int i=1;i<=m;i++)
{
int x,y;
cin>>x>>y;
graph[x][y] = 1;
graph[y][x] = 1;
}
path[0] = 1;
if(hamil(1))
{
for(int i=0;i<n;i++)
cout<<path[i]<<" ";
cout<<endl;
}
else
{
cout<<"Cycle doesn't exist"<<endl;
}
}


return 0;
}
