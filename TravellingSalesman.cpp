#include <iostream>
using namespace std;

int graph[10][10];
int vis[10];
int t,n;
int ans = 999999;

void TSP(int pos,int count,int cost)
{
	if(count == n && graph[pos][0])
	{
		ans = min(ans,cost + graph[pos][0]);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i] == 0 && graph[pos][i])
		{
			vis[i] = 1;
			TSP(i,count+1,cost + graph[pos][i]);
			vis[i] = 0;
		}
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				graph[i][j] = 0;
			}
			vis[i] = 0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>graph[i][j];
			}
		}
		vis[0] = 1;
		TSP(0,1,0);

		cout<<ans<<endl;
	}


	return 0;
}