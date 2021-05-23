#include <iostream>  
#include <cstdlib> 
#include <math.h>
using namespace std;
int aa[900];
int a1[30][30],a2[30][30];
int main()
{
    int a,tot=0,i=0;
    while((scanf("%d",&a))!=EOF)
    {
        aa[++i] = a;
        tot++;
    }
    int n = sqrt(tot);
    int i2=0;
    for(int i=0;i<n;i++)
    {
        for(int i1=0;i1<n;i1++)
        {
            a1[i][i1] = aa[++i2];
            a2[i][i1]=a1[i][i1];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a2[i][j] = (((a2[i][k] & a2[k][j]))|(a2[i][j])); 
            }
        }
    } 
    for(int i=0;i<n;i++)
    {
        for(int i1=0;i1<n;i1++)
        {
            if(a2[i][i1])
                cout<<"1";
            else
            {
                cout<<"0";
            }
            
            if(i1==n-1)
            cout<<endl;
            else
            {
                cout<<" ";
            }
        }
    }
    system("pause");
}