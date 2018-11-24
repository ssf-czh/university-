/*
	Kruskal 最小生成树算法 
	以边贪心 应用于少边多点的图 算法复杂度：nlong(n) n是边数 所以适用于稀疏图（少边多点） 
	先把所有边按从小到大排序
	因为最小生成树是有n-1条边构成且不连通
	所以判断一条边是否为最小生成树的边 就是判断加入它是否构成回路（连通）是的话就不要 一直到n-1停止
	 
*/
#include <bits/stdc++.h>
#define N 100010
using namespace std;
struct Edge
{
	int u,v,val;
}edge[N];
int n,m;//n个点 m条边 
int fa[N];
bool cmp(Edge a,Edge b)
{
	return a.val<b.val;
}
int findfa(int a)
{
	if(a==fa[a])return a;
	int f=findfa(fa[a]);
	fa[a]=f;
	return f;
}
int kru()//返回最小权值和 
{
	int sum = 0;
	int cnt=0;
	for(int i=0;cnt<n-1;i++)
	{
		//cout<<"777"<<endl;
		int u=edge[i].u,v=edge[i].v,val=edge[i].val;
		int fau=findfa(u);
		int fav=findfa(v);
		if(fav==fau)
		{
			//cout<<"555"<<endl;
			continue;
		}
		else 
		{
			//cout<<"999"<<endl;
			sum+=val;
			fa[fav]=fau;
			cnt++;
		}
	}
	//cout<<"888"<<endl;
	return sum;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		edge[i].u=u;
		edge[i].v=v;
		edge[i].val=val;		
	}
	sort(edge,edge+m,cmp);//nlongn
	for(int i=0;i<n;i++)
	fa[i]=i;
	cout<<kru();
	//cout<<endl<<"666";
	return 0;
 } 
 /*
 6 9
 0 1 1
 0 2 5
 0 3 6
 1 2 8
 1 4 4
 2 3 7
 2 4 2
 3 5 3
 4 5 9
 
 */
