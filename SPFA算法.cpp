/*
   SPFA算法
   	由bellman-ford 算法优化：由于每次枚举了大量无意义操作的边 浪费时间
	   注意到 每次只有当某个顶点u 的d[u]值发生改变时，从它出发的边的领接点v的d[v]才可能
	   发生改变 所以可以做出优化：
	   		建一个队列 放d[u]改变了的u 初始把s放进去 如果u在队列里就不放 每次把队首取出递推 
			 如果为队列为空 则不存在可到达的负环 如果某个点入队超过v-1次 则存在  则算不出 
   	算法复杂度：k*n n为顶点数 如果有负环 则退化成O（ve） v是顶点个数 e是边数 就是bell算法复杂度 
	PAT A1003	
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
vector<int> temp,ans;
int sumpath=0,sumw=-1;
vector<node> adj[N];
vector<int> pre[N];
queue<int> q;
int isinq[N];
int sumN[N];
int d[N],n,m,s,e;
int w[N]; 
void add(int u,int v,int val)
{
    adj[u].push_back(node(v,val));
    adj[v].push_back(node(u,val));
}
bool Spfa(int s)//true代表算法成功 没有可到达的负环边 false则失败 
{
	fill(d,d+n,INF);
	fill(isinq,isinq+n,0);
	fill(sumN,sumN+n,0);
	d[s]=0;
	q.push(s);
	isinq[s]=1;
	sumN[s]++;
	while(!q.empty())
	{
		int u=q.front();
		if(u>n-1)return false;
		q.pop();
		isinq[u]=0;
		for(int j=0;j<adj[u].size();j++)
		{
			int v=adj[u][j].v;
			int val=adj[u][j].val;
			if(d[v]>d[u]+val)
			{
				pre[v].clear();
				pre[v].push_back(u);
				d[v]=d[u]+val;
				if(!isinq[v])
				{
				 isinq[v]=1;
				 q.push(v);
				 sumN[v]++;	
				}	
				
			}
			else if(d[v]==d[u]+val)
			{
				pre[v].push_back(u);
			}
		}
		
	}
	return true;
}
int fun()
{
	int s=0;
	for(int i=temp.size()-1;i>=0;i--)
	{
		//cout<<temp[i]<<" ";
		s+=w[temp[i]];
	}
	cout<<endl;
	return s;
}
void dfs(int s,int e)
{
	if(e==s)
	{
		sumpath++;
		temp.push_back(s);
		int sw=fun();
		if(sw>sumw)
		{
			ans=temp;
			sumw=sw;
		}
		temp.pop_back();
	}
	temp.push_back(e);
	for(int i=0;i<pre[e].size();i++)
	{
		dfs(s,pre[e][i]);
	}
	temp.pop_back();
}
int main()
{
	cin>>n>>m>>s>>e;
	for(int i=0;i<n;i++)
	cin>>w[i];
	for(int i=0;i<m;i++)
	{
		int u,v,val;
		cin>>u>>v>>val; 
		add(u,v,val);
	}
	if(Spfa(s))
	{
	    //for(int i=0;i<pre[2].size();i++)
	    //cout<<pre[2][i]<<" ";
		dfs(s,e);
	    cout<<sumpath<<" "<<sumw<<endl;
	}
	
	return 0;
 } 
