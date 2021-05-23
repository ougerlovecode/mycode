#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstring>
#define N 2000006
using namespace std;
long int a[N];
int main()
{
	int n=0,ok=1,hmax=0;
	while((scanf("%d",&n))!=EOF)
	{
		hmax=0;
		ok=1;
		stack<long int> s;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}//输入数据
		for(int i=1;i<=n;i++)
		{
			hmax=hmax>a[i]?hmax:a[i];
			if(!s.empty())//如果栈不为空 
			{
				int h=a[i]-s.top();
				if(h==0)//相等
				{
					s.pop();
					continue;
				}
				if(h>0)
				{
					ok=0;
					break;
				}
				if(h<0)
				{
					s.push(a[i]);
				}
			}
			else 
			{
				s.push(a[i]);
				continue;
			}
		}
		if(((s.size()==1&&s.top()>=hmax)||s.size()==0)&&ok)//
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	
    return 0;
}
