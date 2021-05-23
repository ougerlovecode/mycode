#define N 300006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 300006
long long a[N],b[N];
long long ans;
void merge_sort(int l,int r)
{
	if(r-l>0)//如果整个区间中元素个数大于1，则继续分割 
	{
		int mid=(l+r)/2;
		int i=l;
		int p=l,q=mid+1;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		//printf("%d-%d %d-%d\n",p,mid,q,r);
		while(p<=mid||q<=r)
		{
			if(q>r||(p<=mid&&a[p]<=a[q]))
				b[i++]=a[p++];
			else
			{
				b[i++]=a[q++];
				ans+=mid-p+1;
			}
		 }
		 for(i=l;i<=r;i++)
		 	a[i]=b[i];
	}
}
int main(int argc, char *argv[]) 
{
	int n;
	scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		merge_sort(1,n);
		printf("%lld\n",ans);
	return 0;
}
