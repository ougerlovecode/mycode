#include <iostream>
#include <cstdlib>
#include<algorithm>
#include<vector>
#define N 200060
using namespace std;
struct Eage
{
	int x;
	int y;
};
bool cmp(Eage a,Eage b)
{
	if(a.x!=b.x)
	{
		return a.x<b.x;
	}
	return a.y>b.y;
}
bool cmp2(int a,int b)
{
	return a<b;
}
Eage e1;
vector<Eage> e;
int a[N],a1[N],first[N],nxt[N],y_t[N],x_t[N];
void dfs(int now,vector<int> *q,int flag_before)
{
	for(int i=first[now];i!=-1;i=nxt[i])
	{
		int v=e[i].y;
		if(x_t[v]==0)//到叶节点了
		{
			q->push_back(v);
		}
		else
		{
			int flag=0;
			if(a1[v]==1||flag_before==1)
			{
				flag=1;
			}
			vector<int> vec;
			dfs(v,&vec,flag);//点7
			vec.insert(vec.begin(),v);
			if(a1[v]==1&&flag_before==0)//有标记且为第一个标记的
			{
				sort(vec.begin(),vec.end(),cmp2);
			} 
			vector<int>::iterator it;
			for(it=vec.begin();it!=vec.end();it++)//复制到q里面 
			{
				q->push_back(*it);
				//printf("%d\n",*it);
			}
		}
	}
}
int main() 
{
	for(int i=0;i<=200006;i++)
	{
		first[i]=-1;
		nxt[i]=-1;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a1[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d",&e1.x,&e1.y);
		e.push_back(e1);
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<n-1;i++)
	{
		y_t[e[i].y]++;
		x_t[e[i].x]++;
		nxt[i]=first[e[i].x];
		first[e[i].x]=i;
	}
	int a5; 
	for(int i=1;i<=n;i++)
	{
		if(y_t[i]==0)
			{
				a5=i;
			}
	}
	vector<int> vec;
	int flag=a1[a5];
	/*if(flag)
	{
		sort(a,a+n+1);
		cout<<"[";
		for(int i=1;i<n;i++)
		{
			printf("%d,",a[i]);
		}
		cout<<a[n]<<"]"<<endl;
		return 0;
	}*/ 
	dfs(a5,&vec,flag);
	vec.insert(vec.begin(),a5);
	if(a1[a5]==1)//有标记
			{
				sort(vec.begin(),vec.end(),cmp2);
			} 
	cout<<"[";
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end()-1;it++)
    cout<<*it<<",";
    cout<<*it<<"]"<<endl;
    return 0;
}
