#include <iostream>  
#include <cstdlib> 
#include <math.h>
using namespace std;
int main()
{
    int a,tot=16;
    while((scanf("%d",&a))!=EOF)
    {
        tot++;
    }
    int n = sqrt(tot);
    for(int i=0;i<n;i++)
    {
        for(int i1=0;i1<n;i1++)
        {
            cout<<'1';
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