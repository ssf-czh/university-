#include <bits/stdc++.h>
using namespace std;
bool vis[100000+10];
struct node
{
	int v,val;
	node(int a, int b)
	{
		v=a;val=b;
	}
};
vector<node> adj[100000+10];
void add(int u,int v,int val)
{
	adj[u].push_back(node(v,val));
	adj[v].push_back(node(u,val));
}
int dfs(int s,int flag)//flag 表示当前s顶点有没水 有水1 没水0 
{
//	if(vis[s])return 0;
	vis[s]=true;
	int sm=0;
	for(int i=0;i<adj[s].size();i++)//浇一棵树 等于浇这棵树的子树 并且判断是否要在自己结点浇水 
	{	
		int temp;
		int v=adj[s][i].v;
		int val=adj[s][i].val;
		if(vis[v])continue;
		if(val==1)temp=dfs(v,1);//如果s-v之间有水 
		else temp=dfs(v,0);//没水 
		if(temp)flag=1;//如果有浇水的话 当前顶点一定会有水 
		sm+=temp;
	}
	if(flag==0)sm++;//如果当前顶点没有水的话 就要多浇一次水  需要在自己结点浇水 
	return sm;
}
int main()
{
	fill(vis,vis+100020,false);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
	}
	cout<<dfs(1,1);
	return 0;
}
