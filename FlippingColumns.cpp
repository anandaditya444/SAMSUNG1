#include <iostream>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a[20][20];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int size = 1;
	for(int i=1;i<=20;i++)
		size *= 2;
	int *hash = (int *)calloc(size,sizeof(int));
	for(int i=0;i<n;i++)
	{
		int key = 0,zero = 0;
		for(int j=0;j<m;j++)
		{
			key += a[i][j]*(1 << j);
			if(a[i][j] == 0)
				zero++;
		}
		if((k-zero) >= 0 && (k-zero)%2 == 0)
			hash[key] += 1;
	}
	// for(int i=0;i<10;i++)
	// 	cout<<hash[i]<<" ";
	// cout<<endl;
	int max_val = 0;
	for(int i=0;i<size;i++)
	{
		if(hash[i] > max_val)
		{
			max_val = hash[i];
		}
	}
	cout<<max_val<<endl;

	return 0;
}