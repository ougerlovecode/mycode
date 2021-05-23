#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200060
struct Dragon
{
    long long x,y;
};
struct Dragon dragon1[N],dragon2[N],dragon;
void Qsort1(struct Dragon *arr, long long low, long long high){
    if (high <= low) return;
    long long i = low;
    long long j = high + 1;
    struct Dragon key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i].y < key.y)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j].y > key.y)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        struct Dragon temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    struct Dragon temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    Qsort1(arr, low, j - 1);
    Qsort1(arr, j + 1, high);
}
void Qsort2(struct Dragon *arr, long long low, long long high){
    if (high <= low) return;
    long long i = low;
    long long j = high + 1;
    struct Dragon key = arr[low];
    while (true)
    {
        /*从左向右找比key小的值*/
        while (arr[++i].y+arr[i].x > key.y+key.x)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key大的值*/
        while (arr[--j].y+arr[j].x < key.y+key.x)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        struct Dragon temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    struct Dragon temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    Qsort2(arr, low, j - 1);
    Qsort2(arr, j + 1, high);
}
int main()
{
    long long n=0,j1=1,j2=1,ans=0,A=0;
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        
        scanf("%lld %lld",&dragon.x,&dragon.y);
        if(dragon.y>0)
        {
            dragon1[j1].x=dragon.x;
            dragon1[j1].y=dragon.y;
            j1++;
        }
        else
        {
            dragon2[j2].x=dragon.x;
            dragon2[j2].y=dragon.y;/* code */
            j2++;
        }
    }
    j1--;
    j2--;
    Qsort1(dragon1, 1,j1);//经验大于0的龙升序排列
    for (int i = 1; i <= j1; i++)
    {
        if (A<dragon1[i].x)
        {
            ans+=dragon1[i].x-A;
            A=dragon1[i].x+dragon1[i].y;
        }
        else
        {
            A+=dragon1[i].y;
        }
    }
    Qsort2(dragon2, 1,j2);
    for (int i = 1; i <= j2; i++)
    {
        if (A<dragon2[i].x)
        {
            ans+=dragon2[i].x-A;
            A=dragon2[i].x+dragon2[i].y;
        }
        else
        {
            A+=dragon2[i].y;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
