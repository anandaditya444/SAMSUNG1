#include <iostream>
using namespace std;

#define lim 50

int n,m;
int oilmines[2*lim];
int dp_max[lim][lim][lim];
int dp_min[lim][lim][lim];

void DP()
{
  for(int i=0;i<m;i++)
  {
    for(int 
  }


}

int main()
{
  int t;
  cin>>t;
  int ctr = 1;
  while(t--)
  {
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
      int x;
      cin>>x;
      oilmines[i] = x;
      oilmines[m+i] = x;
    }
    m *= 2;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<m;j++)
      {
        for(int k=0;k<m;k++)
        {
          dp_max[i][j][k] = -1;
          dp_min[i][j][k] = 999999;
        }
      }
    }
    DP();
  
  }


return 0;
}
