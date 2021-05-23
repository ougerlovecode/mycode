#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200060
struct Dragon
{
    long long x,y;
};
struct Dragon dragon1[N],dragon2[N],dragon,b[N]; 
using namespace std;
bool cmp1(Dragon a,Dragon b)
{
	if(a.x!=b.x)
	{
		return a.x<b.x;
	}
	return a.y>b.y;
}
bool cmp2(Dragon a,Dragon b)
{
	return (a.y+a.x)>(b.y+b.x);
}
int main()
{
	long long n=0,j1=1,j2=1,ans=0,A=0;
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        
        scanf("%lld %lld",&dragon.x,&dragon.y);
        if(dragon.y>=0)
        {
            dragon1[j1]=dragon;
            j1++;
        }
        else
        {
            dragon2[j2]=dragon;
            j2++;
        }
    }
    j1--;
    j2--;
	sort(dragon1+1,dragon1+j1+1,cmp1);
	for (int i = 1; i <= j1; i++)
    {
        if (A<dragon1[i].x)
        {
            ans+=dragon1[i].x-A;
            A=dragon1[i].x+dragon1[i].y;
        }
        else
        {
            A+=dragon1[i].y;
        }
    }
	sort(dragon2+1,dragon2+j2+1,cmp2);
	for (int i = 1; i <= j2; i++)
    {
        if (A<dragon2[i].x)
        {
            ans+=dragon2[i].x-A;
            A=dragon2[i].x+dragon2[i].y;
        }
        else
        {
            A+=dragon2[i].y;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


