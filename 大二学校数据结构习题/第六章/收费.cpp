//father[i]表示i结点通往父节点的路的权值 
//这个图为满二叉树 所以可以用数组表示 i结点父节点就是i/2 
//注意权值和 father数组要开 longlong 不然会爆数据 
#include <bits/stdc++.h>
#define N 1000010
using namespace std;
long long father[N];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;cin>>t;
		if(t==1)
		{
			int u,v;
			long long val;
			cin>>u>>v>>val;
			while(u!=v)
			{
				if(u>v)
				{
					father[u]+=val;
					u/=2;
				}
				else{
					father[v]+=val;
					v/=2;
				}
			}
		}
		else
		{
			int u,v;
			cin>>u>>v;
			long long sm=0;
			while(u!=v)
			{
				if(u>v)
				{
					sm+=father[u];
					u/=2;
				}
				else{
					sm+=father[v];
					v/=2;
				}
			}
			cout<<sm<<endl;
		}
	}
	return 0;
} 
