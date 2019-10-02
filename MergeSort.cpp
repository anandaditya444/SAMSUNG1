void merge(int arr[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1];
	int R[n2];

	for(int i=0;i<n1;i++)
		L[i]= arr[l+i];
	for(int i=0;i<n2;i++)
		R[i] = arr[m+1+j];

	int i=0,j=0,k=l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k++] = L[i];
			i++;
		}
		else
		{
			arr[k++] = R[j];
			j++;
		}
	}
	while(i < n1)
	{
		arr[k++] = L[i];
		i++;
	}
	while(j < n2)
	{
		arr[k++] = R[j];
		j++;
	}
}


void mergesort(int arr[],int l,int r)
{
	// int l = 0,r = n-1;

	if(l < r)
	{
		int mid = l + (r-l)/2;

		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}





//second time

void merge(int arr[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1];
	int R[n2];

	for(int i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(int i=0;i<n2;i++)
		R[i] = arr[l+i];
	int i=0,j=0,k=0;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k++] = L[i];
			i++;
		}
		else
		{
			arr[k++] = R[j];
			j++;
		}
	}
	while(i < n1)
	{
		arr[k++] = L[i];
		i++;
	}
	while(j < n2)
	{
		arr[k++] = R[j];
		j++;
	}
}



void mergesort(int arr[],int l,int r)
{
	if(l < r)
	{
		int m = l + (r-l)/2;

		mergesort(arr,l,m);
		mergesort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}