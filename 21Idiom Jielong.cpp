#include <iostream>
#include <cstdlib>
#include<queue>
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
	int step;
};
Edge e[N];//记录第i条边的信息 
int first[N];//记录节点i的第一条边编号
int m=0,zx,zy,ans=0;
int h,t;
int vis[N]={0};
Node now;
Node start;
queue<Node> q;
int bfs()
{
	while(!q.empty())
	{
		now=q.front();q.pop();
		for(int i=first[now.id];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if(!vis[v])
			{
				if(v==h)
					return now.step+2;
				vis[v]=1;
				Node _new;
				_new.id=v;
				_new.step=now.step+1;
				q.push(_new);
			}
		}
	}
	return -1;
}
int main()
{
	for(int j=0;j<N;j++)
		first[j]=-1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&h,&zx,&zy,&t);
		e[i].to=t;
		e[i].nxt=first[h];
		first[h]=i;
	}//build gragh
	scanf("%d%d%d%d",&h,&zx,&zy,&t);
	int h1=h,x1=zx,y1=zy,t1=t;
		start.id=t;
		start.step=1;
		//vis[h]=1;
		vis[t]=1;	//first edge
	scanf("%d%d%d%d",&h,&zx,&zy,&t);//last edge
	int h2=h,x2=zx,y2=zy,t2=t;
	if(h1==h2&&x1==x2&&y1==y2&&t1==t2)
	{
		printf("1\n");
		return 0;
	}
	q.push(start);//put in the first one
	ans=bfs();
	printf("%d\n",ans);
}
