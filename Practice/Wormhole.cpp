#include <iostream>
using namespace std;

int t,n,sx,sy,dx,dy;
int wh[10][15];
int vis[10];
int ans = 999999;

void fun(int sx,int sy,int dx,int dy,int dist)
{
ans = min(ans,distance(sx,sy,dx,dy)+dist);
for(int i=0;i<n;i++)
{
if(vis[i] == 0)
{
vis[i] = 1;
int temp = distance(sx,sy,wh[i][0],wh[i][1]) + wh[i][4] + dist;
fun(wh[i][2],wh[i][3],dx,dy,temp);
temp = distance(sx,sy,wh[i][2],wh[i][3]) + wh[i][4] + dist;
fun(wh[i][0],wh[i][1],dx,dy,temp);
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
cin>>sx>>sy>>dx>>dy;

for(int i=0;i<n;i++)
{
vis[i] = 0;
for(int j=0;j<5;j++)
cin>>wh[i][j];
}

fun(sx,sy,dx,dy,0);
cout<<ans<<endl;
}


return 0;
}

