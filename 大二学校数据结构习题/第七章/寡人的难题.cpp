//普通的kru最小生成树算法 

#include <bits/stdc++.h>
#define N 50000+10
using namespace std;
struct edge
{
	int u,v,val;
};
bool cmp(const edge &a,const edge &b)
{
	return a.val<b.val;
}
int n,m;
edge Edge[200000+10];
int father[N];
int findfather(int x)
{
	if(x==father[x])return x;
	int f=findfather(father[x]);
	father[x]=f;
	return f;
}
int kru()
{
	int sm=0;
	for(int i=0;i<n;i++)
	father[i]=i;
	int cnt=0;
	sort(Edge,Edge+m,cmp);
	for(int i=0;i<m;i++)
	{
		int fa=findfather(Edge[i].u);
		int fb=findfather(Edge[i].v);
		if(fa!=fb)
		{ 	
			sm+=Edge[i].val;
			father[father[fb]]=fa;
			cnt++;
			if(cnt>=n-1)break;
		}
	}
	return sm;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>Edge[i].u>>Edge[i].v>>Edge[i].val;
	}
	cout<<kru();
	return 0;
}
