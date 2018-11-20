
P379

1： 通解：
选储存第一尺度距离最短再遍历求解第二尺度


#include <bits/stdc++.h>
#define N 10010
#define INF 1000010
using namespace std;
vector <int> temp,ans;
struct node
{
    int v,val;
    node(int a,int b)
    {
        v=a;val=b;
    }
};
bool vis[N]={false};
int w[N],n,m;
int d[N];
vector <node> adj[N];
vector <int> pre[N];
void add(int u,int v,int val)
{
    adj[u].push_back(node(v,val));
    adj[v].push_back(node(u,val));
}
void dfs(int s)
{
    
    fill(d,d+n,INF);
    d[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1)return;
        vis[u]=true;
        for(int k=0;k<adj[u].size();k++)
        {
            int v=adj[u][k].v;
            if(vis[v]==false)
            {
                if(d[u]+adj[u][k].val<d[v])
                {
                    d[v]=d[u]+adj[u][k].val;
                    pre[v].clear();
                    pre[v].push_back(u);
                //    cout<<"666:::u:"<<u<<" v:"<<v;
                    //printf("  pre[%d].size()=%d\n",v,pre[v].size());
                }
                else if(d[u]+adj[u][k].val==d[v])
                {
                //    d[v]=d[u]+adj[u][k].val;
                    //cout<<"u:"<<u<<" v:"<<v;
                    pre[v].push_back(u);
                //    printf("  pre[%d].size()=%d\n",v,pre[v].size());
                }
            }
        }
    }
}
int mx=-1;
int su=0;
void ddfs(int s,int e,int sum)
{
    if(e==s)
    {   
        temp.push_back(e);
        su++;
        if(sum+w[s]>=mx)
        {
            
            ans=temp;
            mx=sum+w[s];
        }
        temp.pop_back();
        return;
    }
    temp.push_back(e);
    for(int i=0;i<pre[e].size();i++)
    {
        ddfs(s,pre[e][i],sum+w[e]);
    }
    temp.pop_back();
}
int main()
{
    //cout<<pre[2].size()<<endl;
    int a,b;
    cin>>n>>m>>a>>b;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        w[i]=temp;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dfs(a);
    ddfs(a,b,0);
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<" ";
    cout<<endl;
    cout<<su<<" "<<mx;
    return 0;
}




2：  快解
#include <bits/stdc++.h>
#define N 10010
#define INF 1000010
using namespace std;
//vector <int> temp,ans;
struct node
{
    int v,val;
    node(int a,int b)
    {
        v=a;val=b;
    }
};
int su[N]={0};
int ans[N]={0};
bool vis[N]={false};
int w[N],n,m;
int d[N];
vector <node> adj[N];
vector <int> pre[N];
void add(int u,int v,int val)
{
    adj[u].push_back(node(v,val));
    adj[v].push_back(node(u,val));
}
void dfs(int s)
{
    
    fill(d,d+n,INF);
    ans[s]=w[s];
    d[s]=0;
    su[s]=1;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1)return;
        vis[u]=true;
        for(int k=0;k<adj[u].size();k++)
        {
            int v=adj[u][k].v;
            if(vis[v]==false)
            {
                if(d[u]+adj[u][k].val<d[v])
                {
                    d[v]=d[u]+adj[u][k].val;
                    ans[v]=ans[u]+w[v];
                    su[v]=su[u];
                    //pre[v].clear();
                    //pre[v].push_back(u);
                //    cout<<"666:::u:"<<u<<" v:"<<v;
                    //printf("  pre[%d].size()=%d\n",v,pre[v].size());
                }
                else if(d[u]+adj[u][k].val==d[v])
                {
                    if(ans[v]<ans[u]+w[v])
                    ans[v]=ans[u]+w[v];
                    su[v]+=su[u];
                //    d[v]=d[u]+adj[u][k].val;
                    //cout<<"u:"<<u<<" v:"<<v;
                //    pre[v].push_back(u);
                //    printf("  pre[%d].size()=%d\n",v,pre[v].size());
                }
            }
        }
    }
}
/*void ddfs(int s,int e,int sum)
{
    if(e==s)
    {   
        temp.push_back(e);
        su++;
        if(sum+w[s]>=mx)
        {
            
            ans=temp;
            mx=sum+w[s];
        }
        temp.pop_back();
        return;
    }
    temp.push_back(e);
    for(int i=0;i<pre[e].size();i++)
    {
        ddfs(s,pre[e][i],sum+w[e]);
    }
    temp.pop_back();
}*/
int main()
{
    //cout<<pre[2].size()<<endl;
    int a,b;
    cin>>n>>m>>a>>b;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        w[i]=temp;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dfs(a);
    //ddfs(a,b,0);
    //cout<<ans.size()<<endl;
    /*for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<" ";
    cout<<endl;*/
    cout<<su[b]<<" "<<ans[b];
    return 0;
}

//用优先队列改良后

/*
#include <bits/stdc++.h>
#define N 100010
#define INF 10000010
using namespace std;
vector<int> pre[N];
int w[N];
struct edge{
     int v,val;
     edge(){}
     edge(int a,int b){v=a;val=b;}
     friend bool operator < (const edge &a,const edge &b)   
     {
         if(a.val==b.val) return a.v<b.v;
         else return a.val>b.val;
     }
 };
vector<edge> G[N];
bool vis[N];
int d[N];
int n,m,s,e,sumpath=0,sumw=-1;
vector<int> temp,ans;
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
		vis[u]=true;//确定 d[u] 		
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].v;
			int val = G[u][i].val;
			if(!vis[v]&&d[v]>d[u]+val)
			{
				pre[v].clear();
				pre[v].push_back(u);
				d[v]=d[u]+val;
				q.push(edge(v,d[v]));
			}
			else if(!vis[v]&&d[v]==d[u]+val)
			{
				pre[v].push_back(u);
			}
		}
	
	}	
}
int fun()
{
	int s=0;
	for(int i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<" ";
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
	dijkstra(s);
	dfs(s,e);
	cout<<sumpath<<" "<<sumw;
	return 0;
 } 
 
 /*
 5 6 0 2
 1 2 1 5 3
 0 1 1
 0 2 2
 0 3 1
 1 2 1
 2 4 1
 3 4 1
 
 */
*/
