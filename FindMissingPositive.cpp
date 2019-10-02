#include <iostream>
using namespace std;

int a[100];
int vis[1000];

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<1000;i++)
			vis[i] = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i] <= 0)
				continue;
			vis[a[i]] = 1;
		}
		for(int i=1;i<1000;i++)
		{
			if(vis[i] == 0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}




	return 0;
}