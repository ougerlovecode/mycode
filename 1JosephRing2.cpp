#include <iostream>
#include <cstdlib>
#include<algorithm> 
#define N 5
struct Node
{
	int num;
	struct Node *p; 
};
using namespace std;
int main() 
{
	int n,k,m;
	scanf("%d,%d,%d",&n,&k,&m);
	if(k>n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}
	if((n<1)||(k<1)||(m<1))
	{	
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	Node *head;
	head->p=NULL;
	for(int i=1;i<=n;i++)
	{
		Node node;
		
	}
	return 0;
}
