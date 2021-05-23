#include <iostream>
#include <cstdlib>
#include<algorithm>
#define N 100006
int dp[4040];
using namespace std;
int main() 
{
	int n,V,a[N],ans_0=0;
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]%=V;
	}
	dp[0]=1;
	dp[V]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=2*V;j>=V;j--)
		{
			if(a[i]==0&&j==2*V)
			{
				dp[j]=(dp[j]+dp[j-a[i]]+1)%10000000;
			}
			else
			{
				dp[j]=((dp[j]+dp[j-a[i]])%10000000);
			}
		}
		for(int j=V-1;j>=0;j--)
		{
			dp[j]=dp[j+V];
		}/**/
	}
	printf("%d\n",dp[2*V]);
	return 0;
}
