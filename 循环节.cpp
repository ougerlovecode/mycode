#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200003
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char  a[N],a1[N],t;
	int len=0,L=0,i=0,ok=0,yuchu,jieshu,flag=1,q=0;
	scanf("%lld",&L);
	scanf("%c",&t);
	scanf("%s",&a);
	len=strlen(a);
	yuchu=len%L;
	jieshu=len/L;
	if(L==len){
			a[L-1]++;//1
			if(a[L-1]>'9'){
			for(i=L-1;i>=0;i--){
				a[i]+=q;
				if(a[i]>'9'){
					a[i]-=10;
					q=1;
				}
				else q=0;
			}
			if(q==1){
				jieshu++;
				a[0]='1';
				for(i=1;i<L;i++){
					a[i]='0';
				}
				a[L]='\0';
				for(i=0;i<jieshu;i++){
					printf("%s",a);
				}
				printf("\n");
				return 0;
			}
			}
			for(i=0;i<jieshu;i++){
				printf("%s",a);
			}
			printf("\n");
		return 0;
	}
	else if(yuchu==0){//len±»lÕû³ý 
		 for(int j=0;j<jieshu-1;j++){
		 for(i=j*L;i<(j+1)*L;i++){
			if(flag&&(a[i]>a[i+L])){
				ok=1;
				flag=0;
			}
			if(flag&&(a[i]<a[i+L])){
				flag=0;
			}
			if(j==0){
				a1[i]=a[i];
			}
		}
		}
		a1[L]='\0';
		if(ok){
			for(i=0;i<jieshu;i++){
				printf("%s",a1);
			}
			printf("\n");
		}
		else{
			a1[L-1]++;//1
			if(a1[L-1]>'9'){
			for(i=L-1;i>=0;i--){
				a1[i]+=q;
				if(a1[i]>'9'){
					a1[i]-=10;
					q=1;
				}
				else q=0;
			}
			if(q==1){
				jieshu++;
				a1[0]='1';
				for(i=1;i<L;i++){
					a1[i]='0';
				}
				a1[L]='\0';
				for(i=0;i<jieshu;i++){
					printf("%s",a1);
				}
				printf("\n");
				return 0;
			}
			}
			for(i=0;i<jieshu;i++){
				printf("%s",a1);
			}
			printf("\n");
		}
		return 0;
	}
	else{
		jieshu++;
		a1[0]='1';
		for(i=1;i<L;i++){
			a1[i]='0';
		}
		a1[L]='\0';
		for(i=0;i<jieshu;i++){
			printf("%s",a1);
		}
		printf("\n");
	}
	return 0;
}
