#include<stdio.h>
int a[100];
void merge(int l,int mid,int h);
void mergesort(int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		mergesort(l,mid);
		mergesort(mid+1,h);
		
		merge(l,mid,h);
	}
}
void merge(int l,int mid,int h)
{
	int k=l;
	int i=l;
	int j=mid+1;
	int b[100];
	int q;
	
	while((k<=mid)&&(j<=h))
	{
		if(a[k]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(k>mid)
	{
		for(q=j;q<=h;q++)
		{
			b[i]=a[q];
			i=i+1;
		}
	}
	else
	{
		for(q=k;q<=mid;q++)
		{
			b[i]=a[q];
			i=i+1;
		}
	}

}
int main()
{
	int n;
	printf("\nEnter Size : ");
	scanf("%d",&n);
	int l,h;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	l=a[0];
	h=a[n-1];
	mergesort(l,h);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
