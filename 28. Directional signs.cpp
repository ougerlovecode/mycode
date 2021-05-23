#include <iostream>
#include <cstdlib>
#include<algorithm>
#define N 2020
using namespace std;
int n,a[N];
long long ans,dp[N][N];
int main() 
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	dp[1][a[0]]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=2006;j++)
		{
			if(dp[i-1][j]!=0)
			{
				int left=min(j,a[i-1]);
				int right=max(j,a[i-1]);
				if(a[i]<=left)
				{
					dp[i][right]=(dp[i][right]+dp[i-1][j])%2147483647;
				}
				else if(a[i]>=right)
				{
					dp[i][left]=(dp[i][left]+dp[i-1][j])%2147483647;
				}
				else if(a[i]>left&&a[i]<right)
				{
					dp[i][right]=(dp[i][right]+dp[i-1][j])%2147483647;
					dp[i][left]=(dp[i][left]+dp[i-1][j])%2147483647;
				}
			}
		}
	}
	for(int i=1;i<=2006;i++)
	{
		ans=(ans+dp[n][i])%2147483647;
	}
	ans=ans%2147483647;
	printf("%lld\n",ans%2147483647);
}
