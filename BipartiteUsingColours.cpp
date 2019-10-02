#include <iostream>
using namespace std;

int graph[200][200];
int color[200];

bool issafe(int src,int c,int v)
{
	for(int i=0;i<v;i++)
	{
		if(graph[src][i])
		{
			if(color[i] == c)
				return false;
		}
	}
	return true;
}

bool dfs(int src,int v)
{
	if(src == v)
		return true;
	for(int c=1;c<=2;c++)
	{
		if(issafe(src,c,v))
		{
			color[src] = c;
			if(dfs(src+1,v))
				return true;
			color[src] = 0;
		}
	}
	return false;
}

int main()
{
	int v,e,x,y;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	if(dfs(0,v))
		cout<<"Bipartite";
	else
		cout<<-1<<endl;



	return 0;
}