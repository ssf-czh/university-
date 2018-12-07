#include <bits/stdc++.h>
#define N 50000+10
#define INF 100000010
using namespace std;
struct node
{
	int v,val;
	node(int a,int b)
	{
		v=a;val=b;
	}
};
vector <node> adj[N];
int n,m,t,k;
int d[N];
bool inq[N];
int sm[N];
void add(int u,int v,int val)
{
	adj[u].push_back(node(v,val));
	adj[v].push_back(node(u,val));
}
bool spfa(int s)
{
	queue <int> q;
	fill(d,d+N,INF);
	fill(inq,inq+N,0);
	fill(sm,sm+N,0);
	d[s]=0;
	q.push(s);
	inq[s]=1;
	sm[s]++;
	while(!q.empty())
	{
		int u=q.front();
		if(u>=n+2)return false;
		q.pop();
		inq[u]=0;
		for(int j=0;j<adj[u].size();j++)
		{
			int v=adj[u][j].v;
			int val=adj[u][j].val;
			if(d[v]>d[u]+val)
			{
				d[v]=d[u]+val;
				if(!inq[v])
				{
				 inq[v]=1;
				 q.push(v);
				 sm[v]++;	
				}	
				
			}
		}
		
	}
	return true;
}
int main()
{
	cin>>n>>m>>t>>k;
	for(int i=0;i<m;i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
	}
	for(int i=0;i<t;i++)
	{
		int t;cin>>t;
		add(0,t,0);
	}
	for(int i=0;i<k;i++)
	{
		int t;cin>>t;
		add(t,n+1,0);
	}
	if(spfa(0))
	for(int i=0;i<=n+1;i++)
	cout<<d[i]<<" ";
	return 0;
}
