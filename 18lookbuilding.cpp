#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstring>
#define N 1000006
using namespace std;
struct house
{
	int height,color;
};
house building[N];
int ans1,ans[N],a[N];
int main()
{
	int T=0,n=0,j=0;
	scanf("%d",&T);
	for(j=1;j<=T;j++)
	{
		ans1=0;
		stack<house> s1;
		memset(building,0,1000006);
		memset(ans,0,1000006);
		memset(a,0,1000006);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&building[i].color);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&building[i].height);
		}//��������
		for(int i=1;i<=n;i++)
		{
			while(!s1.empty())//��ջ��Ϊ�գ� 
			{
				if(building[i].height<s1.top().height)//¥���߶�С��top ʱ 
				{
					break;
				}
				if(a[s1.top().color]==1)//��1��Ϊ0
				{
					ans1--;
				}
				a[s1.top().color]--;//��¼ĳһ��ɫ���ֵĴ��� 
				s1.pop();
			}
			s1.push(building[i]);
			if(a[building[i].color]==0)//��0��Ϊ 1
			{
				ans1++;
			}
			a[building[i].color]++;//��¼ĳһ��ɫ���ֵĴ��� 
			ans[i]=ans1;
		}
		for(int i=1;i<n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
    return 0;
}
