#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 110000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int n,h0,a[N],i=0,h=0;
	long long t=0;
	scanf("%d %d",&n,&h0);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	    }
	a[n]=h0;
    for(i=1;i<=n;i++){
    	h=a[i]-a[i-1];
    	if(h>0)
    	   {
    	   	 t+=h;
		   }
	}
    printf("%lld\n",t);
	return 0;
}
