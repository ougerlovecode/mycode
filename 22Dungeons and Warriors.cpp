#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define N 104
int a[N][N]; //表示的是.#*矩阵
int stepArr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //表示上下左右4个方向
int visit[N][N][55];
int start_x,start_y,end_x,end_y,m,n,k,T,ans,t;
struct Node
{
	int x;
	int y;
	int time;
	Node (int x1,int y1,int time1):x(x1),y(y1),time(time1){}
};

int BFS()
{
	Node node(start_x,start_y,0);
	queue<Node> q;
	q.push(node);
	while(!q.empty())
 {
	node=q.front();
	q.pop();
	/*if(node.x==end_x&&node.y==end_y)
	{
		return node.time;
	}*/
	//visit[node.x][node.y][node.time%k]=1;
	for(int i=0;i<4;i++)
	{
		int x=node.x+stepArr[i][0];
		int y=node.y+stepArr[i][1];
		t=node.time;
		if(x>0&&y>0&&x<=n&&y<=m&&visit[x][y][(t+1)%k]==0&&a[x][y]=='.')//可以通过 
		{
			visit[x][y][(t+1)%k]=1;
			Node next(x,y,t+1);
			q.push(next);
		}
		else if(x>0&&y>0&&x<=n&&y<=m&&visit[x][y][(t+1)%k]==0&&(a[x][y]==42)&&((t+1)%k==0))//可以通过 ，是怪物且怪物不在 
		{
			visit[x][y][(t+1)%k]=1;
			Node next(x,y,t+1);
			q.push(next);
		}
		else if(x>0&&y>0&&x<=n&&y<=m&&a[x][y]=='E'&&visit[x][y][(t+1)%k]==0)
		{
			return t+1;
		}
	}
	}
	return-1;
 }
 int main()
{
	scanf("%d",&T);
	for(int i1=1;i1<=T;i1++)
{
	scanf("%d %d %d",&n,&m,&k);
	getchar();//吸收换行符 	
	memset(visit,0,sizeof(int)*N*N*55) ;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			if(a[i][j]=='S')
			{
				start_x=i;
				start_y=j;
				a[i][j]='.';
			}
			if(a[i][j]=='E')
			{
				end_x=i;
				end_y=j;
			}
		}
		getchar();//吸收换行符 
	}//cin
	ans=BFS();
	printf("%d\n",ans);
}
}

