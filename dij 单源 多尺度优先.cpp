
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
