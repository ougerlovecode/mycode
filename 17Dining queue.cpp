#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	int n=0;
	queue<string> q1;
	char opr[50]={'0'},name[50]={'0'},t='0';
	scanf("%d",&n);
	scanf("%c",&t);
	for(int i=1;i<=n;i++)
	{
		cin>>opr;
		if(opr[0]=='A')
		{
			scanf("%s",name);
			q1.push(name);
			continue;
		}
		if(opr[0]=='Q'&&opr[8]=='d')
		{
			if(q1.empty()==false)
			{
				cout<<q1.front()<<endl;
			}
			else 
			{
				printf("Empty queue\n");
			}
			continue;
		}
		if(opr[0]=='Q'&&opr[8]=='l')
		{
			if(q1.empty()==false)
			{
				cout<<q1.back()<<endl;
			}
			else 
			{
				printf("Empty queue\n");
			}
			continue;
		}
		if(opr[0]=='L')
		{
			if(q1.empty()==true)
			{
				continue;
			}
			q1.pop();
			continue;
		}
		printf(" \n");
	}
}
 
