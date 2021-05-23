#include <iostream>
#include <cstdlib>
#include<algorithm>
#include<vector> 
#define N 5
using namespace std;
int main() 
{
	long long n,k,m,t=0;
	vector<long long> vec;
	scanf("%lld,%lld,%lld",&n,&k,&m);
	if(k>n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}
	if((n<1)||(k<1)||(m<1))
	{	
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		vec.push_back(i);
	}
	while(vec.size()>1)
	{
		for(int i=0;i<m-1;i++,k++)
		{
			if(k>=vec.size())
			{
				k=0;
			}
		}
		long long a=vec[k-1];
		t++;
		if(t==10)
			{
				t=0;
				printf("%lld\n",a);
			}
		else
		{
			printf("%lld ",a);
		}
		vec.erase(vec.begin()+k-1);
		if(k>vec.size())
			{
				k=1;
			}
	}
	printf("%lld\n",vec.front());
	return 0;
}
