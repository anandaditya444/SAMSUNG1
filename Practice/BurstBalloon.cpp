#include <iostream>
using namespace std;

int n;
int ball[500];
int dp[500][500];

int solve()
{
for(int len=1;len<=n;len++)
{
  for(int i=0;i<=n-len;i++)
  {
    int j = i + len - 1;
    for(int k=i;k<=j;k++)
    {
      int lval = 1;
      int rval = 1;
      if(i != 0)
        lval = ball[i-1];
      if(j != n-1)
        rval = ball[j+1];
      int before = 0,after = 0;
      if(i != k)
        before = dp[i][k-1];
      if(j != k)
        after = dp[k+1][j];
      dp[i][j] = max(dp[i][j],before + after + lval*ball[k]*rval);
    }
  }
}
return dp[0][n-1];

}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>ball[i];
	int ans = solve();
	cout<<ans<<endl;

return 0;
}
