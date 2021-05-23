#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{	
	int n, i,j=0,k=0,tot[N]={0},num=0,len,tot1=0,T0=0,l=0,r=0,b1[N]={0},b2[N]={0};
	char a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&a);
		len=strlen(a);
		for(j=0;j<len;j++){
			if(a[j]=='('){
				a[j]=-1;
			}
			else if(a[j]==')'){
				a[j]=1;
			}
			tot[k]+=a[j];//计算权值 
		}
		tot1=0;
		if(tot[k]==0){//非法串或（）
			for(j=0;j<len;j++){
			tot1+=a[j];
			if(tot1>0){//不合法串 
				tot[k]=0;
				break;
			}
			}
			if(j==len){
				k++;
				T0++;
			}//合法串 
			   
		} 
		if(tot[k]<0){//左括号倾向串，从左往右计算权值，计算过程中出现正值则为不合法串 
			for(j=0;j<len;j++){
			tot1+=a[j];
			if(tot1>0){//不合法串 
				tot[k]=0;
				break;
			}
			}
			if(j==len)//合法串 
			   k++;
		}
		if(tot[k]>0){//同理 
			for(j=len-1;j>=0;j--){
			tot1+=a[j];
			if(tot1<0){//不合法串 
				tot[k]=0;
				break;
			}
			}
			if(j==-1)//合法串 
			   k++;
		}
	}//存好合法串，权值存入tot【】 
	for(i=0;i<k;i++){
		if(tot[i]<0){
			//totl[l]=-tot[i];
			b1[-tot[i]]++;
			l++;
		}
		else if(tot[i]>0){
			//totr[r]=tot[i];
			b2[tot[i]]++;
			r++;
		}
	}
	for(i=0;i<150000;i++){
		num+=b1[i]<b2[i]?b1[i]:b2[i];
	}
	/*for(i=0;i<k;i++){//找出匹配的情况，算出最多的匹配数num
		for(j=i+1;j<k&&(tot[i]!=0);j++){
			if((tot[i]+tot[j])==0){
				num++;
				tot[j]=0;
				break;
			}			//好好检查，可能超时 ,靠，果然有一个超了，等我再改改,dalaonb,我懂了 
		}
	}*/
	printf("%d\n",num+(T0>>1));
	return 0;
}
