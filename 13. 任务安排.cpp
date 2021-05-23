#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 300060
using namespace std;
struct mission
	{
		int start,end;
	};
struct mission ms[N];
void Qsort(struct mission *arr, int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    struct mission key = arr[low];
    while (true)
    {
        /*���������ұ�key���ֵ*/
        while (arr[++i].end < key.end)
        {
            if (i == high){
                break;
            }
        }
        /*���������ұ�keyС��ֵ*/
        while (arr[--j].end > key.end)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*����i,j��Ӧ��ֵ*/
        struct mission temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*����ֵ��j��Ӧֵ����*/
    struct mission temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}
 
int main()
{
 	int ans=0,i,j,n=0;
 	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ms[i].start);
		scanf("%d",&ms[i].end);
	}
    Qsort(ms, 1,n);

    for(i=1;j<=n;)
	{
		for(j=i+1;j<=n;j++)
		{
			if(ms[j].start>=ms[i].end)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	printf("%d\n",ans+1); 
	return 0;
}
