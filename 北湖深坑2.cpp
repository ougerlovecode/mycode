#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100003
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	long long ml=0,mr=0,a[N],n=0,hmax=0,i,i0=0,T,white=0,ans=0,tot=0;
	scanf("%lld",&T);
	for(;T>0;T--){
		ml=0;
		mr=0;
		i0=0;
		white=0;
		tot=0;
		//memset(a,0,sizeof(a));
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++){
			if(a[i]>ml){
				white+=(i-1)*(a[i]-ml);
				hmax=a[i];
				i0=i;
				ml=a[i];
			}
			tot+=a[i];
		}
		for(i=n-1;i>=i0;i--){
			if(a[i]>mr){
				white+=(n-i)*(a[i]-mr);
				mr=a[i];
			}
		}
		ans=hmax*n-white-tot;
		printf("%lld\n",ans);	
	}
	return 0;
}
