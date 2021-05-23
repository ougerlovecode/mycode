#include <iostream>
#include <cstdlib>
#include<algorithm>
#include<vector>
#define maxn 200006
using namespace std;
vector<int> tree[maxn]; 
long long fa[maxn],vis[maxn];
long long odd,even,depth;
long long sum,size[maxn],dep[maxn];
void Dfs(int u)
{
	if(vis[u] == 0)
	{
		dep[u] = dep[fa[u]] + 1;
		if((dep[u]&1))//ÆæÊý
			odd++;
		else
			even++; 
	}
  	size[u] = 1;
	vis[u] = 1;
    vector<int>::iterator it;
	for(it=tree[u].begin();it!=tree[u].end();it++)
	{
		int v=*it;
     	if(vis[v] == 0)
     	{
     	fa[v] = u;
 		Dfs(v);
 		size[u] += size[v];
	 	}
	}
}
int main() 
{
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	Dfs(1);
	for(int i=1;i<=n;i++)
	{
		sum+=size[i]*(n-size[i]);
	}
	printf("%lld\n",(odd*even+sum)/2);
}
