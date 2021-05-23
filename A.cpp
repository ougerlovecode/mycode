#include <iostream>
#include <cstdlib>
#include<stack>
#define N 3
using namespace std;
int main(int argc, char *argv[]) 
{
	int T=0,A,B,t,k,x,y,i0; 
	for(int i=0;i<T;i++)
	{
		
		scanf("%d%d%d%d",&A,&B,&t,&k);
		x=t%B;
		y=A%x;
		if(y!=0)
		{
			i0=k%(y+1);
		}
		else if(y==0)
		{
			y=A%x;
			i0=k%y;
		}
		printf("%d",i0);
	}
	return 0;
}
