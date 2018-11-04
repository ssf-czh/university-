图论 bfs 微博问题 
P365
#include <bits/stdc++.h>
#define INF 100010
#define N 10010
using namespace std;
int n,L;
struct node
{
    int id,layer;
    node(int a)
    {
        id=a;
    }
    node()
    {
        ;
    }
};
vector <node> adj[N];
bool isinq[N]={false};
queue <node> q;
int bfs(int s)
{
    int ans=0;
    node temp(s);
    temp.layer=0;
    q.push(temp);
    int u=temp.id;
    isinq[u]=true;
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        u=top.id;
        for(int i=0;i<adj[u].size();i++)
        {
            node temp=adj[u][i];
            temp.layer=top.layer+1;
            if(temp.layer<=L&&isinq[temp.id]==false)
            {
                ans++;
                q.push(temp);
                isinq[temp.id]=true;
            }
        }
    }
    return ans;
}
int main()
{
    cin>>n>>L;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        for(int j=0;j<temp;j++)
        {
            int t;
            cin>>t;
            adj[t].push_back(node(i));
        }
    }
    int temp;
    cin>>temp;
    for(int i=0;i<temp;i++)
    {
        int t;
        cin>>t;
        fill(isinq,isinq+N,false);
        cout<<bfs(t)<<endl;
    }
    return 0;
}
//数据：
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
ans：4 5
