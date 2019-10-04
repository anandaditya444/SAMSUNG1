#include <iostream>
using namespace std;

int grid[100][100];

int main()
{
int n,m,k;
cin>>n>>m>>k;

for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
    cin>>grid[i][j];
int size = 1;
for(int i=1;i<=20;i++)
  size *= 2;
int *hash = (int *)calloc(size,sizeof(int));

for(int i=0;i<n;i++)
{
int key = 0,zero = 0;
for(int j=0;j<m;j++)
{
  key += (grid[i][j]*(1 << j);
  if(grid[i][j] == 0)
    zero++;
}
if((k-zero) >= 0 && (k-zero)%2 == 0)
  hash[key] += 1;
}

int ans = 0;
for(int i=0;i<size;i++)
{
if(hash[i] > ans)
  ans = hash[i];
}
}

cout<<ans<<endl;

return 0;
}
