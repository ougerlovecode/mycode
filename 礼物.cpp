#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 400040
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void bubbleSort (int arr[], int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) /* ��ѭ��Ϊ����������len��������len-1�� */
        for (j=0; j<len-1-i; j++) { /* ��ѭ��Ϊÿ�˱ȽϵĴ�������i�˱Ƚ�len-i�� */
            if (arr[j] > arr[j+1]) { /* ����Ԫ�رȽϣ��������򽻻�������Ϊ������ң�����֮�� */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}
 
int main(int argc, char *argv[])
{	
	char b[11000]={'0'},a[N]={'0'},a1[N]={'0'};
	int i=0,i0=0,j=0,k=0,k0=0,lena,lenb,num[N],tot[11000]={0},ok=0;
	scanf("%s",&a1);
	scanf("%s",&b);
	lenb=strlen(b);
	lena=strlen(a1);
	strcpy(a,a1);
	strcat(a,a1);
	for(;;){
		j=0;
		k=0;
		for(i=i0;i<lena;i++){
		if(a[i]==b[j]){
			i0=i+1;
			j++;
			tot[k++]=i+1;
			break;
		}
		}
		for(i=i0;i<(i0-1+lena);i++){
			if(a[i]==b[j]){
				j++;
				tot[k++]=i+1;
			}
		}
		if(j>=lenb){
			break;
		}
	}
	for(i=0;i<k;i++){
		if(tot[i]>lena){
			tot[i]-=lena;
		}
	}
	bubbleSort (tot,k);//ð������ 
    for (i=0; i<k-1; i++)
        printf ("%d ", tot[i]);
    printf ("%d\n", tot[i]);
    
	return 0;
}
