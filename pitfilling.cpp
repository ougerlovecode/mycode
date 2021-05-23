#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstring>
#define N 2000006
using namespace std;
long int a[N];
int main()
{
	int n=0;
	while((scanf("%d",&n))!=EOF)
	{
		stack<long int> s;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}//输入数据
		for(int i=1;i<=n;i++)
		{
			if(!s.empty())//如果栈不为空 
			{
				int h=a[i]-s.top();
				if((h<0&&(-h)%2==0)||(h>0&&h%2==0)||h==0)//相差偶数个 
				{
					s.pop();
					continue;
				}
				if((h<0&&(-h)%2!=0)||(h>0&&h%2!=0))
				{
					s.push(a[i]);
					continue;
				}
			}
			else 
			{
				s.push(a[i]);
				continue;
			}
		}
		if(s.size()==1||s.size()==0)
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	
    return 0;
}
