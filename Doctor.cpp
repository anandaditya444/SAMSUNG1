#include <iostream>
using namespace std;

int t,n,e,time;
int mat[1000][1000];
finale[1000];

void dfs(int pos,int probab,int traversal)
{
	if(traversal == 0)
	{
		finale[pos] += probab;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(mat[pos][i] > 0)
			dfs(i,probab*mat[pos][i],traversal-1);
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>e>>time;
		for(int i=0;i<e;i++)
		{
				int u,v;
				float p;
				cin>>u>>v>>p;
				mat[--u][--v] = p;
		}
		cin>>start;
		int traversal = time/10;
		if(traversal == 0)
		{
			cout<<start<<endl;
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				if(mat[start][i] > 0)
				{	
					dfs(i,mat[start][i],traversal-1);	
				}
			}
		}
	}


return 0;
}
