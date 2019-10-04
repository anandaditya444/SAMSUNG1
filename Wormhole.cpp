#include <iostream>
using namespace std;

int t,n,sx,sy,dx,dy;
int vis[10];
int wh[10][5];
int ans;

int min(int x,int y)
{
	if(x < y)
		return x;
	return y;
}

// void abs(int x)
// {
// 	if(x < 0)
// 		return -x;
// 	return x;
// }

int distance(int sx,int sy,int dx,int dy)
{
	return abs(sx-dx)+abs(sy-dy);
}

void fn(int sx,int sy,int dx,int dy,int dis)
{
	ans = min(ans,distance(sx,sy,dx,dy)+dis);
	for(int i=0;i<n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			int temp = distance(sx,sy,wh[i][0],wh[i][1])+wh[i][4]+dis;
			fn(wh[i][2],wh[i][3],dx,dy,temp);
			temp = distance(sx,sy,wh[i][2],wh[i][3])+wh[i][4]+dis;
			fn(wh[i][0],wh[i][1],dx,dy,temp);
			vis[i] = 0;
		}
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		ans = 999999;
		cin>>n;
		cin>>sx>>sy>>dx>>dy;
		for(int i=0;i<n;i++)
		{
			vis[i] = 0;
			for(int j=0;j<5;j++)
			{
				cin>>wh[i][j];
			}
		}
		fn(sx,sy,dx,dy,0);
		cout<<ans<<endl;
	}



	return 0;
}