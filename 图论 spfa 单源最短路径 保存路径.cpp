P378
#include <bits/stdc++.h>
#define INF 100010
#define N 10010
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
int d[N],w[N]={0},sm[N]={0};
bool inq[N]={false};
queue <int> q;
set<int> pre[N];
void add(int a,int b,int c)
{
    adj[a].push_back(node(b,c));
    adj[b].push_back(node(a,c));
}
int n,m,s,e,num[N]={0},ss[N]={0};
bool spfa(int s)
{
    fill(d,d+N,INF);
    d[s]=0;
    num[s]=1;
    ss[s]=w[s];
    q.push(s);
    inq[s]=true;
    sm[s]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].v;
            int val=adj[u][i].val;
           if(d[u]+val<d[v])
           {
               num[v]=num[u];
               pre[v].clear();
               pre[v].insert(u);
               ss[v]=ss[u]+w[v];
            d[v]=d[u]+val;
            if(!inq[v])
            {
                q.push(v);
                sm[v]++;
                inq[v]=true;
                if(sm[v]>=n)return false;
            }
           }
           else if(d[u]+val==d[v])
           {
                  if(ss[u]+w[v]>ss[v])
                ss[v]=ss[u]+w[v];
                //num[v]+=num[u];
                  pre[v].insert(u);
                  num[v]=0;
                  for(set<int>::iterator it=pre[v].begin();it!=pre[v].end();it++)
                  num[v]+=num[*it];
           }
          
        }

    }
    return true;
}
/*void dfs(int s)
{
    fill(d,d+N,INF);
    d[s]=0;
    num[s]=1;
    sm[s]=w[s];
    for(int i=0;i<n-1;i++)
    {
        for(int u=0;u<n;u++)
        {
            //int v=adj[u].v;
            for(int j=0;j<adj[u].size();j++)
            {
                int v=adj[u][j].v;
                if(d[u]+adj[u][j].val<d[v])
                {
                    d[v]=d[u]+adj[u][j].val;
                    sm[v]=sm[u]+w[v];
                    num[v]=num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }
                else if(d[u]+adj[u][j].val==d[v])
                {
                    if(sm[u]+w[v]>sm[v])
                    sm[v]=sm[u]+w[v];
                    pre[v].insert(u);
                    num[v]=0;
                    for(set<int> ::iterator it=pre[v].begin();it!=pre[v].end();it++)
                    {
                        num[v]+=num[*it];
                    }
                }
            }
        }
    }    
}*/
void dfs(int e,int dep)
{
    
    if(e==s)
    {
        cout<<e<<" ";
        return;
    }
    for(set<int>:: iterator it=pre[e].begin();it!=pre[e].end();it++)
    {
        dfs(*it,dep+1);
        cout<<e<<" ";
        if(dep==0)cout<<endl;

    }
    
}
int main()
{
    cin>>n>>m>>s>>e;
    for(int i=0;i<n;i++)
    cin>>w[i];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
//    dfs(s);
    spfa(s);
    //cout<<num[e];
    /*for(int i=0;i<n;i++)
    {
        cout<<d[i]<<" ";
    }*/
    //for(set<int> ::iterator it=pre[2].begin();it!=pre[2].end();it++)
    //    cout<<*it<<" ";
    //cout<<d[e]<<" "<<num[e]<<" "<<ss[e];
    dfs(e,0);
      return 0;
}
