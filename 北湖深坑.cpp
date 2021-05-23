#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 110000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int ml[N],mr[N],a[N],T,n,i;
	long long tot=0;
	scanf("%d",&T);
	for(;T>0;T--){
		tot=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(ml,0,sizeof(ml));
		memset(mr,0,sizeof(mr));
		
	    for(i=1;i<=n;i++){
		    scanf("%d",&a[i]);
	    }
	    for(i=1;i<=n;i++){
	    	ml[i]=a[i-1]>ml[i-1]?a[i-1]:ml[i-1];
		} 
		for(i=n;i>0;i--){
			mr[i]=a[i+1]>mr[i+1]?a[i+1]:mr[i+1];
		}
	    for(i=1;i<=n;i++){
	    	if(ml[i]>=mr[i]&&mr[i]>a[i])
	    	   tot+=mr[i]-a[i];
	    	else if(ml[i]<mr[i]&&ml[i]>a[i])
	    	   tot+=ml[i]-a[i];
		}
	    printf("%lld\n",tot);    
	}
	return 0;
}
