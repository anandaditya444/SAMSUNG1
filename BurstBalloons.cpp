#include <iostream>
using namespace std;

int ball[500];
int dp[500][500];
int n;

int max(int a,int b)
{
   if(a > b)
      return a;
   return b;
}

int solve()
{
   for(int len=1;len<=n;len++)
   {
      for(int i=0;i<=n-len;i++)
      {
        int j = i + len - 1;
        for(int k=i;k<=j;k++)
        {
          int lvalue = 1;
          int rvalue = 1;
          
          if(i != 0)
            lvalue = ball[i-1];
          if(j != n-1)
            rvalue = ball[j+1];
           
          int before = 0,after = 0;
          if(i != k)
            before = dp[i][k-1];
          if(j != k)
            after = dp[k+1][j];
            
          dp[i][j] = max(dp[i][j],before + after + lvalue*ball[k]*rvalue);
        }
      }
   }
   return dp[0][n-1];
}

int main()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cin>>ball[i];
   }
   int ans = solve();
   cout<<ans<<endl;

return 0;
}
