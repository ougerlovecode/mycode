#include <iostream>
#include <cstdlib>
#include<algorithm>
#define N 500006
using namespace std;
long long dp[4][N],maxbefore=-0x3f3f3f3f3f,m=-0x3f3f3f3f3f;
int n,a[N];
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dp[1][1]=a[1];
	dp[2][2]=a[1]+a[2];
	dp[3][3]=a[1]+a[2]+a[3];
	for(int i=1;i<=3;i++)
	{
		maxbefore=-0x3f3f3f3f3f;
		for(int j=i;j<=n;j++)
		{
			if(j==i)
			{
				;
			}
			else
			{
				maxbefore=max(maxbefore,dp[i-1][j-1]);
				dp[i][j]=max(dp[i][j-1],maxbefore)+a[j];
			}
		}
	}
	for(int i=3;i<=n;i++)
	{
		m=max(m,dp[3][i]);
	}
	printf("%lld\n",m);
}
