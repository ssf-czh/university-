/* 原本n**2 变成n*logn*/
//笔记374

#include <bits/stdc++.h>
#define N 100010
#define INF 10000010
using namespace std;
struct edge{
     int v,val;
     edge(){}
     edge(int a,int b){v=a;val=b;}
     //对小于号进行重载 const 和friend不能省略
     //对优先队列的重载很特别 因为优先级 所以如果是val属性小的优先级高的话
	 //那么 return的时候就应该和sort相反 即val大的排前面 
     friend bool operator < (const edge &a,const edge &b)   
     {
         if(a.val==b.val) return a.v<b.v;
         else return a.val>b.val;
     }
 };
vector<edge> G[N];
bool vis[N];
int d[N];
int n,m,s;
void add(int u,int v,int val)//加边操作 
{
	G[u].push_back(edge(v,val));
	G[v].push_back(edge(u,val));
}
void dijkstra(int s)
{
	fill(vis,vis+n,false);
	fill(d,d+n,INF);
	d[s]=0;
	vis[s]=true; 
	//priority_queue <edge,vector<edge>, greater<edge> > q;
	priority_queue<edge> q;
	q.push(edge(s,0));
	while(!q.empty())
	{
		edge temp = q.top();
		q.pop();
		int u=temp.v; 
		if(vis[u])continue;//因为在队列过程中某一个u可能被其他俩个点优化过2次 所以进入过2次队列，第二次没用;
		vis[u]=true;//确定 d[u] 		
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].v;
			int val = G[u][i].val;
			if(!vis[v]&&d[v]>d[u]+val)
			{
				//更新完 v点可能对后续定点有影响 所以加入队列观察 
				d[v]=d[u]+val;
				q.push(edge(v,d[v]));
			}
		}
	
	}
	
	
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
	dijkstra(s);
	for(int i=0;i<n;i++)
	cout<<d[i]<<" ";
	return 0;
 } 


这个是ds作业中的 多起点多终点问题求解
把多个起点合并成超级源点 然后一次dij
/*
#include <bits/stdc++.h>
#define N 50000+10
#define INF 100000010
using namespace std;
typedef pair<int,int> P;
struct node
{
	int v,val;
	node(int a,int b)
	{
		v=a;val=b;
	}
};
vector<node> adj[N];
int d[N];
bool vis[N]={false};
int n,t,m,k,ans=INF;//m是可到达 k是喜欢的 
int M[N]; int K[N];
void add(int u,int v,int val)
{
	adj[u].push_back(node(v,val));
	adj[v].push_back(node(u,val));
}
void dij(int s=0)
{
	//cout<<"s="<<s<<endl;
	fill(d,d+N,INF);
	fill(vis,vis+N,false);
	priority_queue<P,vector<P>,greater<P> > q;
	d[0]=0;
	q.push(P(0,0));//第一个是值 第二个是坐标 
	while(!q.empty())
	{
		P temp =q.top();
		q.pop();
	//	cout<<"789 "<<temp.second<<endl;
		if(vis[temp.second])continue	
		vis[temp.second]=true;
		int u=temp.second;
		//cout<<"size"<<adj[0].size();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].v;
			int val=adj[u][i].val;
		//	cout<<"  v:"<<v<<" val:"<<val<<"   d[v] "<<d[v]<<"  d[u]+val "<<d[u]+val<<endl;
			if(!vis[v]&&d[v]>d[u]+val)
			{
				
				d[v]=d[u]+val;
				q.push(P(d[v],v));
			}
		}
	}
		
}
int main()
{
	cin>>n>>t>>m>>k;
	for(int i=0;i<t;i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
	}
	for(int i=0;i<m;i++)
	{
		int v;
		cin>>v;
		add(0,v,0);
	}
	dij();
	for(int i=0;i<k;i++)
	{
		
		int temp;cin>>temp;
		//cout<<d[temp]<<" ";
		ans=min(ans,d[temp]);	
	}
	cout<<ans;
	
	return 0;
} 
*/
/*
6 8 0
 0 1 1
 0 3 4
 0 4 4
 1 3 2
 2 5 1
 3 2 2
 3 6 3
 4 5 3
*/
