#include <iostream>
#include <cstdlib>
#include<algorithm>
#include<vector>
#define N 13
using namespace std;
struct OP
{
	int x_1;int x_2;
	int y_1;int y_2;
};
vector<OP> ans1;
int m,n,a[N][N];
int dx[5]={0,0,1,-1,0},dy[5]={0,1,0,0,-1};
int l,now;
void dfs_0(int x1,int y1,int q[N][N],int vis[N][N])//置零 
{
	q[x1][y1]=0;
	if(vis[x1][y1]) return;//
	vis[x1][y1]=1;
	for(int i=1;i<=4;i++)//四个方向去查看
	{
		int x_2=x1+dx[i],y_2=y1+dy[i];
		if(x_2>=1&&x_2<=n&&y_2>=1&&y_2<=m)
		{
			if(now==q[x_2][y_2])
			{
				/*l++;
				if(l>=3) return true;*/
				dfs_0(x_2,y_2,q,vis);
			}
		}
	} 
} 
int cha_dfs(int x1,int y1,int q[N][N],int vis[N][N])//检查连续的块儿
{
	vis[x1][y1]=1;
	int l0=l;
	for(int i=1;i<=4;i++)//四个方向去查看
	{	
		int x_2=x1+dx[i],y_2=y1+dy[i];
		if(vis[x_2][y_2]) continue;
		if(x_2>=1&&x_2<=n&&y_2>=1&&y_2<=m)
		{
			if(q[x1][y1]==q[x_2][y_2])
			{
				l++;
				if(l>=3) return true;
				if(cha_dfs(x_2,y_2,q,vis))
				{
					return true;
				}
			}
		}
	}
	l=l0;
	return false;
}
void note(int x1,int y1,int x2,int y2)//储存答案^^ 
{
	OP o;
	o.x_1=x1;o.x_2=x2;o.y_1=y1;o.y_2=y2;
	ans1.push_back(o);
}
void swap(int x1,int y1,int x2,int y2,int q[N][N])
{
	int temp;
	temp=q[x1][y1];
	q[x1][y1]=q[x2][y2];
	q[x2][y2]=temp;
}
void copy(int p[N][N],int q[N][N])//给每个阶段备份^^ 
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			q[i][j]=p[i][j];
		}
	}
}
bool cha_0(int q[N][N])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(q[i][j])//q[i][j]不为0 
				return false;
		}
	}
	return true;
}
void vis_0(int vis[N][N])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=0;
		}
		
	}
}
int dfs(int a_before[N][N])
{
	if(cha_0(a_before))//全部为0，完成，返回 
		return true;
	int a_now[N][N]={0};
	for(int i1=1;i1<=n;i1++)
	{
	  for(int j1=1;j1<=m;j1++)
	  {
	  	if(a_before[i1][j1]!=0&&a_before[i1][j1-1]==0&&a_before[i1-1][j1]==0&&a_before[i1+1][j1]==0&&a_before[i1][j1+1]==0)
	  		return false;
	  	if(a_before[i1][j1]==0)
	  		continue;
	  	//copy(a_before,a_now);
		for(int i=0;i<3;i++)//模拟不动和向右及向下； 
		{ 
		/*for(int i0=1;i0<=n;i0++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a_now[i0][j]<<",";
		}
		cout<<endl;
	}*/
		int x2=i1+dx[i],y2=j1+dy[i];
		if(a_before[i1][j1]==0||a_before[x2][y2]==0)
				continue;
		if(y2>m) continue;
		if(x2>n) continue;
		copy(a_before,a_now);
		int vis[N][N]={0};
		if(!i)//i=0
		{
			l=1;
			vis_0(vis);
			now=a_now[i1][j1];
			if(now&&cha_dfs(i1,j1,a_now,vis))//三个可消 
			{
				vis_0(vis);
				if(now)
					dfs_0(i1,j1,a_now,vis);//置零 
				if(dfs(a_now))
				{
					note(i1,j1,x2,y2);//记录 
					return true;
				}
				//if(ans1.size()!=0)
				//	;//ans1.erase(ans1.end()-1)
			}
			
		}
		else
		{
			if(a_now[i1][j1]==a_now[x2][y2])//剪枝 
				continue;
			swap(i1,j1,x2,y2,a_now);
			l=1;
			vis_0(vis);
			now=a_now[i1][j1];
			int ok1=0,ok2=0;
			if(now&&cha_dfs(i1,j1,a_now,vis))// //三个可消
			{
				vis_0(vis);
				dfs_0(i1,j1,a_now,vis);//置0
				ok1=1;
			}
			l=1;
			vis_0(vis);
			now=a_now[x2][y2];
			if(now&&cha_dfs(x2,y2,a_now,vis))//三个可消
			{
				vis_0(vis);
				dfs_0(x2,y2,a_now,vis);//置0 
				ok2=1;
			}
			if(ok1||ok2)
			{
				if(dfs(a_now))//成功 
				{
					note(i1,j1,x2,y2);//记录
					return true;
				}
			}
		}
		}
	  }
	}
	return false; 
}
int main() 
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(a);
	int k=ans1.size();
	printf("%d\n",k);
	OP op;
	vector<OP>::iterator it;
	for(it=ans1.end()-1;it!=ans1.begin()-1;it--)
	{
		op=*it;
		cout<<op.x_1<<" "<<op.y_1<<" "<<op.x_2<<" "<<op.y_2<<endl;
	}
}
