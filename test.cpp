#include <iostream>  
#include <cstdlib> 
#include <algorithm> 
#define N 1000009
using namespace std;
long long a[N][3];
int comp(const void*a,const void*b)
{
	return((long long*)a)[2]-((long long*)b)[2];
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i][1]>>a[i][2];
    }
    qsort(a,n,sizeof(long long)*3,comp);
    long long t0=0;
    int tot=0;
    int ans=0;
    while(tot<n)
    {
        int i1=0;
        if(tot)
        {
            for(i1=0;a[i1][0]==1;i1++)
                ;
        }
        t0=a[i1][2];
        tot++;
        for(int i=i1;i<n;i++)
        {
        if(a[i][0] == 0)
        {
            if(a[i][1]>=t0)
            {
                t0=a[i][2];
                a[i][0]=1;
                tot++;
            }
        }
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
