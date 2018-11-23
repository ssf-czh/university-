P407
/*
  prime是对顶点v进行贪心思想 最优子结构
  类似于Dijkstra算法 
  算法复杂度与顶点数有关 是O（v*v）
  所以适合点少边多的数据使用
*/
#include <bits/stdc++.h>
#define INF 100010
#define N 10001
using namespace std;
struct node
{
    int v,val;
    node(int a,int b)
    {
        v=a;val=b;
    }
};
int n,m;
vector <node> adj[N];
int d[N];//这里的d[v]不同于最短路径 这里是最近到达子集s的最小距离
bool vis[N];
void add(int a,int b,int c)
{
    adj[a].push_back(node(b,c));
    adj[b].push_back(node(a,c));
}
int prime(int s)
{
    int ans=0;
    fill(vis,vis+N,false);
    fill(d,d+N,INF);
    d[s]=0;
    //cout<<"n= "<<n;
    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                u=j;MIN=d[j];
            }
        }
        if(u==-1)return -1;//如果放回-1 说明生成不了最小生成树
        vis[u]=true;
        ans+=d[u];
        for(int j=0;j<adj[u].size();j++)
        {
            int val=adj[u][j].val;
            int v=adj[u][j].v;
            if(vis[v]==false&&val<d[v])
            {
                d[v]=val;
            }
        }        
    }
     return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<prime(0);
    return 0;
}
