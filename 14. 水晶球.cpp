#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#define N 100006  
long long n,k=1,i0=0;  
struct crystalstone  
{  
   long long a,b,c,snum;  
};  
struct crystalstone crst[N],cr[N];  
long long min=0;  
long long max=0;  
void Qsort(struct crystalstone *arr, long long low, long long high){  
    if (high <= low) return;  
    long long i = low;  
    long long j = high + 1;  
    struct crystalstone key = arr[low];  
    while (true)  
    {  
        /*���������ұ�keyС��ֵ*/  
        while (arr[++i].b > key.b)  
        {  
            if (i == high){  
                break;  
            }  
        }  
        /*���������ұ�key���ֵ*/  
        while (arr[--j].b < key.b)  
        {  
            if (j == low){  
                break;  
            }  
        }  
        if (i >= j) break;  
        /*����i,j��Ӧ��ֵ*/  
        struct crystalstone temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    }  
    /*����ֵ��j��Ӧֵ����*/  
    struct crystalstone temp = arr[low];  
    arr[low] = arr[j];  
    arr[j] = temp;  
    Qsort(arr, low, j - 1);  
    Qsort(arr, j + 1, high);  
}  
int main(int argc, char *argv[])   
{  
    long long a0[3];  
    scanf("%lld",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%lld %lld %lld",&a0[0],&a0[1],&a0[2]);  
        for(int j=1;j<=2;j++)  
        {  
            int m=0;  
            for(int j1=0;j1<3-j;j1++)  
            {  
                if(a0[j1]>a0[j1+1])  
                {  
                    m=a0[j1];  
                    a0[j1]=a0[j1+1];  
                    a0[j1+1]=m;  
                }  
            }  
        }  
        crst[i].a=a0[0];  
        crst[i].b=a0[1];  
        crst[i].c=a0[2];  
        crst[i].snum=i;  
        if(max<crst[i].a)  
        {  
            max=crst[i].a;  
            i0=i;  
        }  
    }  
    int j=1;  
    for(int i=1;i<=n;i++)//�ӵ�crst[]С�ڵ���max�ģ����ֵ��ں���Ҳû��   
    {  
        if(crst[i].b>max)  
        {  
            cr[j]=crst[i];  
            j++;//�µ�����cr[],�������ںϺ���ܸ��õ�ˮ��ʯ   
        }  
    }  
    j--;  
    Qsort(cr,1,j);//��cr[]����������   
    for(int i=1;i<j;i++)  
    {  
        if(cr[i].b==cr[i+1].b&&cr[i].c==cr[i+1].c)//���ں�   
        {  
            min=(cr[i].a+cr[i+1].a)<cr[i].b?(cr[i].a+cr[i+1].a):cr[i].b;   
            if(min>max)// �ж��ںϺ��ˮ��ʯ��̱��Ƿ����max   
            {  
                max=min;  
                k=2;  
                i0=i;  
            }  
        }  
    }  
    if(k==2)  
    {  
        long long m=cr[i0].snum<cr[i0+1].snum?cr[i0].snum:cr[i0+1].snum;  
        long long n=cr[i0].snum>cr[i0+1].snum?cr[i0].snum:cr[i0+1].snum;  
        printf("%lld\n",k);  
        printf("%lld %lld\n",m,n);  
    }  
    if(k==1)  
    {  
        printf("%lld\n",k);  
        printf("%lld\n",i0);  
    }  
      
    //printf("%d\n",max);  
    return 0;  
}  
