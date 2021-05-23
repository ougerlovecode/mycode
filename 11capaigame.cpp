#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200060
int shoupai[N]={0},paidui[N]={0};
int main(int argc, char *argv[]) 
{
	int n,i=0,i0=0,a[N]={0},h=0,ok=1,ans=0;
	char t,c;
	scanf("%d",&n);
	scanf("%c",&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&shoupai[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&paidui[i]);
	}
	for(i=0;i<n;i++){
		if(shoupai[i]!='0'){
			a[shoupai[i]]=0;
		}
	}
	for(i=1;i<=n;i++){
		if(paidui[i]!=0){
			a[paidui[i]]=i;
			if(i-(paidui[i]-2)>0){//
				h=(i-(paidui[i]-1))>h?(i-(paidui[i]-1)):h;
			}
		}
		if(paidui[i]==1){
			i0=i;//
		}
	}
	for(i=i0;i<=n;i++){
		if(paidui[i]==i-i0+1){//�ƶѵײ��պ�ΪΪ123..... 
			ok=1;
		}
		else {
			ok=0;
			break;
		}
	}
	if(ok){//�����123...... m
		for(i=n-i0+2;i<=n;i++){// ��m+1��n,�Ƿ�׼���� 
			if(a[i]<i+i0-n-1)//
				continue;
			else break; 
		} 
		if(i==n+1){// ׼���� 
			ans=i0-1;
		}
		else{// δ׼����
		ans=h+n;
		}
	}
	else{//�Ƶײ���123...... m
		ans=h+n;
	}
	printf("%d\n",ans);
	//getchar();
	return 0;
}
