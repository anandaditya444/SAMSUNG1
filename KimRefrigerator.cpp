#include <iostream>
using namespace std;

int t,n,sx,sy,dx,dy,ans;
int x[105],y[105];
int vis[105];

void dfs(int cust,int sx,int sy,int dist)
{
	if(cust == n+1 && sx == dx && sy == dy)
	{
		if(dist < ans)
			ans = dist;
		return;
	}
	int cur = dist;
	for(int i=0;i<=n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			dist += abs(sx-x[i])+abs(sy-y[i]);
			dfs(cust+1,x[i],y[i],dist);
			vis[i] = 0;
			dist = cur;
		}
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		ans = 99999;
		cin>>n;
		cin>>sx>>sy;
		for(int i=0;i<n+1;i++)
		{
			vis[i] = 0;
			cin>>x[i]>>y[i];
		}
		dx = x[0];
		dy = y[0];
		dfs(0,sx,sy,0);
		cout<<ans<<endl;
	}



	return 0;
}