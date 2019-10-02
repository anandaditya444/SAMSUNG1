#include <iostream>
using namespace std;

int main()
{
  int idx = 1,s,e,n,k,a[100],t;
  cin>>t;
  while(t--)
  {
    cin>>s>>e>>n>>k;
    for(int i=0;i<n;i++)
      cin>>a[i];
    int num = 0;
    for(int i=s;i<=e;i++)
    {
    	int cur = i;
    	int cnt = 0;
    	while(cur > 0)
    	{
    	   int rem = cur%10;
    	   
    	   for(int j=0;j<n;j++)
    	   {
    	      if(rem == a[j])
    	      {
    	      	  cnt++;
    	      	 // break;
    	      }
    	   }
    	   cur /= 10;
    	}
    	if(cnt <= k)
    	   num++;
    }
    cout<<"#"<<idx<<" "<<e-s+1-num<<endl;
    idx++;
  }
    


return 0;
}
