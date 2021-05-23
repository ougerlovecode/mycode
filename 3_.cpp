#include <iostream>  
#include <cstdlib> 
#include <algorithm> 
#include <string.h>
using namespace std;
char a[1000];
int min_[200];
int max_[200];
int main()
{
    char c;
    int i=0;
    while(1)
    {
        c = getchar();
        if(c<='z'&&c>='a')
        {
            a[++i] = c;
        }
        else if(c=='\n')
        {
            break;
        }
        else
        {
            continue;
        }
    }
    int num_min =i,num_max=i,num=i;
   int flag1=0;
    while((c = getchar())!='\n')
    {
        if(c<='z'&&c>='a')
        {
            if(flag1==0)
                flag1=1;
            else
            {
                flag1=0;
            }
            if(flag1==0)
                 {min_[c] = 1;num_min--;}
            else if(flag1==1)
                {max_[c] = 1;num_max--;}
        }
        else if(c=='\n')
        {
            break;
        }
        else
        {
            continue;
        }
    }
    for(int i=1,tot=0;i<=num;i++)
    {
        if(min_[a[i]]==1)
        ;
        else
        {
            cout<<a[i];tot++;
              if(tot==num_min)
                break ;
            else
            {
                cout<<',';
            }
        }
       
    }
    cout<<endl;
     for(int i=1,tot=0;i<=num;i++)
    {
        if(max_[a[i]]==1)
            ;
        else
        {
            cout<<a[i];tot++;
            if(tot==num_max)
             break;
            else
            {
                cout<<',';
            }
        }
    }
    cout<<endl;
    system("pause");
}