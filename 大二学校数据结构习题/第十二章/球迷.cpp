//普通并查集的查找 合并操作 
#include <bits/stdc++.h>
#define N 100000+10
using namespace std;
int father[N];
int sm=0;
int findfather(int x)
{
	if(x==father[x])return x;
	int f=findfather(father[x]);
	father[x]=f;
	return f;
}
int main()
{
	for(int i=0;i<N;i++)
	father[i]=i;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		int fa=findfather(a);
		int fb=findfather(b);
		if(fa!=fb)father[fb]=fa;
	}
	for(int i=1;i<=n;i++)
	{
		if(father[i]==i)sm++;
	}
	cout<<sm;
	return 0;
 } 
