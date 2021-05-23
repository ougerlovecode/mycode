#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 
int main(int argc, char *argv[]) 
{
 /*#ifndef ONLINE_JUDGE
	//freopen("infile.txt", "r", stdin);
	freopen("outfile.txt", "w", stdout);
#endif	*/
	
	int num[70000]={0},Unicodenow=0,z=0,nofound=1;
	unsigned char a[N],c,p1,p2,p3;
	while(scanf("%c",&c)!=EOF){
		if(c<128&&c>0){ 
			continue; 
		}
		else if(c<224&&c>191){
			a[0]=c;
			scanf("%c",&a[1]);
			Unicodenow=((a[0]-(1<<7)-(1<<6))<<6)+(a[1]-(1<<7));
		}
		else if(c>223&&c<240){
			a[0]=c;
			scanf("%c%c",&a[1],&a[2]);
			Unicodenow=((a[0]-(1<<7)-(1<<6)-(1<<5))<<12)+((a[1]-(1<<7))<<6)+(a[2]-(1<<7));
		}
		num[Unicodenow]++;
	}
	for(int i=0;i<70000;i++){
		if(num[i]>1){
			nofound=0;
			if(i>>11){//
				p1=(i>>12)+(1<<7)+(1<<6)+(1<<5);
				p2=((i>>6)&((1<<6)-1))+(1<<7);
				p3=(i&((1<<6)-1))+(1<<7);
				printf("%c%c%c %#06x %d\n",p1,p2,p3,i,num[i]);
			}
			else if(i>>6){//
				p1=(i>>6)+(1<<7)+(1<<6);
				p2=(i&((1<<6)-1))+(1<<7);
				printf("%c%c %#06x %d\n",p1,p2,i,num[i]);
			}	
		}
		
	}
	if(nofound){
		printf("No repeat!\n");
	}
	return 0;
}
