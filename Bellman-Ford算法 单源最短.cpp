/*
	Bellman-Ford 算法 单源最短路径 
	Dijkstra升级  可以处理负权边 但处理不了 负环图（这个负环图需要能从源点到达） 
	可升级为spfa算法 
*/
/*
    思想是 如果最短路径存在 则路径长度一定不超过顶点数N 因为不可能走了一个环
	所以每个点的最短路径都是唯一的 就是一颗最短路径树  所以这棵树最高就是N 
	所以只要从源点 （树的根） 一层层往下递推（最多n-1次 因为d[s] 源点为0）就行
	并且 还要多一步判断是否有负环图 （再递推一次） 如果d数组有改变 则存在 返回false
	 
	 递推就是列举每条边(u->v) (d[v]>d[u]+len(u->v))的话就更新 每次递推一层 
*/
#include <bits/stdc++.h>
#define N 100010
#define INF 10000010
using namespace std;
struct node
{
    int v,val;
    node(int a,int b)
    {
        v=a;val=b;
    }
};
vector<node> adj[N];
int d[N],n,m,s;
void add(int u,int v,int val)
{
    adj[u].push_back(node(v,val));
    adj[v].push_back(node(u,val));
}
bool Bellman_Ford(int s)//true代表算法成功 没有可到达的负环边 false则失败 
{
	fill(d,d+n,INF);
	d[s]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int u=0;u<n;u++)
		{
			for(int j=0;j<adj[u].size();j++)
			{
				int v=adj[u][j].v;
				int val=adj[u][j].val;
				if(d[v]>d[u]+val)
				{
					d[v]=d[u]+val;
				}
			}
		}
	}
	for(int u=0;u<n;u++)
		{
			for(int j=0;j<adj[u].size();j++)
			{
				int v=adj[u][j].v;
				int val=adj[u][j].val;
				if(d[v]>d[u]+val)
				{
					return false;
				}
			}
		}
	return true;
}
int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		int u,v,val;
		cin>>u>>v>>val; 
		add(u,v,val);
	}
	if(Bellman_Ford(s))
	{
	for(int i=0;i<n;i++)
	cout<<d[i]<<" ";
	}
	
	return 0;
 } 
