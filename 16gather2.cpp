#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 500006
int x[N]={0},Min_XX[N],max_X[N],y[N]={0},YY_mIn[N],YMaX__[N];
void swap(int *a,int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
void U_P_mIn__(int* a, int node, int size)
{
	int f=(node-1)/2,z=node;
	if(a[f]<a[z]&&f>-1)
	{
		swap(&a[f],&a[z]);
		U_P_mIn__(a,f,size);
	}
}
void dow__n_H___min(int* a, int node, int size)//�³�
{
        int left = (node<<1) + 1;
        int right = (node<<1) + 2;
        int max = node;
        if( left < size && a[left] > a[max])
                max = left;
        if( right < size && a[right] > a[max])
                max = right;
        if(max != node)
        {
                swap( &a[max], &a[node]);
                dow__n_H___min(a, max, size);
        }
}

void up_max(int* a, int node, int size)
{
	int f=(node-1)/2,z=node;
	if(a[f]>a[z]&&f>-1)
	{
		swap(&a[f],&a[z]);
		up_max(a,f,size);
	}
}
void down_heap_max(int* a, int node, int size)//�³� 
{
        int left = (node<<1) + 1;
        int right = (node<<1) + 2;
        int max = node;
        if( left < size && a[left] < a[max])
                max = left;
        if( right < size && a[right] < a[max])
                max = right;
        if(max != node)
        {
                swap( &a[max], &a[node]);
                down_heap_max(a, max, size);
        }
}
int main()
{
	int T=0;
	scanf("%d",&T);
	long long ans=0,ansy=0;
	int n=0,mid,midy,l=0,r=0,ly=0,ry=0,i=0;
	for(int i1=1;i1<=T;i1++)
	{
		printf("Case: %d\n",i1);
		n=0,l=0,r=0,ly=0,ry=0;
		ans=0,ansy=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x[i],&y[i]); 
		}
		Min_XX[0]=x[1];l++;
		YY_mIn[0]=y[1];ly++;
		printf("0.0000\n");
		for(i=2;i<=n;i++)
		{
			if(l==r)
			{
				if(x[i]<=max_X[0])
				{
					Min_XX[l++]=x[i];
					U_P_mIn__(Min_XX,l-1,l);
					ans+=(x[i]-Min_XX[0])>0?(x[i]-Min_XX[0]):(Min_XX[0]-x[i]);
				}
				else if(x[i]>max_X[0])
				{
					Min_XX[l++]=max_X[0];
					U_P_mIn__(Min_XX,l-1,l);
					max_X[0]=x[i];
					down_heap_max(max_X,0,r);
					ans+=x[i]-Min_XX[0];//ok
				}
			}
			else if(l==(r+1)) 
			{
				if(x[i]>=Min_XX[0])
				{
					ans+=x[i]-Min_XX[0];//ok
					max_X[r++]=x[i];
					up_max(max_X,r-1,r);
				}
				else if(x[i]<Min_XX[0])
				{
					ans+=Min_XX[0]-x[i];//ok
					max_X[r++]=Min_XX[0];
					up_max(max_X,r-1,r);
					Min_XX[0]=x[i];
					dow__n_H___min(Min_XX,0,l);
				}
			}
			if(ly==ry)
			{
				if(y[i]<=YMaX__[0])
				{
					YY_mIn[ly++]=y[i];
					U_P_mIn__(YY_mIn,ly-1,ly);
					ansy+=(y[i]-YY_mIn[0])>0?(y[i]-YY_mIn[0]):(YY_mIn[0]-y[i]);
				}
				else if(y[i]>YMaX__[0])
				{
					YY_mIn[ly++]=YMaX__[0];
					U_P_mIn__(YY_mIn,ly-1,ly);
					YMaX__[0]=y[i];
					down_heap_max(YMaX__,0,ry);
					ansy+=y[i]-YY_mIn[0];//ok
				}
			}
			else if(ly==(ry+1)) 
			{
				if(y[i]>=YY_mIn[0])
				{
					ansy+=y[i]-YY_mIn[0];//ok
					YMaX__[ry++]=y[i];
					up_max(YMaX__,ry-1,ry);
				}
				else if(y[i]<YY_mIn[0])
				{
					ansy+=YY_mIn[0]-y[i];//ok
					YMaX__[ry++]=YY_mIn[0];
					up_max(YMaX__,ry-1,ry);
					YY_mIn[0]=y[i];
					dow__n_H___min(YY_mIn,0,ly);
				}
			}
			printf("%lld.0000\n",ans+ansy);
		}
	} 
	return 0;
}
