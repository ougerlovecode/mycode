#include <iostream>
#include <cstdlib>
#include<stack>
#define N 300006
using namespace std;
struct Edge
{
	int to;
	int nxt=-1;
};
struct Node
{
	int id;
};
Edge e[N];//记录第i条边的信息
int first[N];//记录节点i的第一条边编号
int ans=0;
int h,t;
int vis[N]={0};
Node start;
stack<Node> q;
int dfs(int now)
{
		
		//now=q.top();q.pop();
		for(int i=first[now];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if(v==h)
				return true;//get through
			vis[now]=1;//note this node
			if(dfs(v))//get through
				return true;
			
		}
	//vis[now]=1;
	return false;
}
int main()
{
	for(int j=0;j<N;j++)
		first[j]=-1;
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
	{
		/*for(int j=0;j<=n;j++)//<=n
			vis[j]=0;*/
		scanf("%d%d",&h,&t);
		e[i].to=t;
		e[i].nxt=first[h];
		first[h]=i;
		//vis[t]=1;
		if(dfs(t))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
}
