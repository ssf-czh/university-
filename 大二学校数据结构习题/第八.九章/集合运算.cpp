//简单的 set 容器使用 
#include <bits/stdc++.h>
using namespace std;
set<int> a,b,c,a_b,b_a,aub,anb;
void funa_b()
{
	for(set<int> ::iterator it=a.begin();it!=a.end();it++)
	{
		int t=*it;
		if(b.find(t)==b.end())a_b.insert(t);
	}
}
void funb_a()
{
	for(set<int> ::iterator it=b.begin();it!=b.end();it++)
	{
		int t=*it;
		if(a.find(t)==a.end())b_a.insert(t);
	}	
}
void funaub()
{
	aub=a;
	for(set<int> ::iterator it=b.begin();it!=b.end();it++)
	{
		int t=*it;
		//if(a.find(t)==a.end())b_a.insert(t);
		aub.insert(t);
	}	
}
void funanb()
{
	for(set<int> ::iterator it=b.begin();it!=b.end();it++)
	{
		int t=*it;
		if(a.find(t)!=a.end())anb.insert(t);
	}
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int temp;cin>>temp;
		a.insert(temp);
	}
	for(int i=0;i<m;i++)
	{
		int temp;cin>>temp;
		b.insert(temp);
	}
	for(int i=0;i<k;i++)
	{
		int temp;cin>>temp;
		c.insert(temp);
	}
	funa_b();
	funb_a();
	funaub();
	funanb();
	if(c==a_b||c==b_a||c==aub||c==anb)
	for(set<int> ::iterator it=c.begin();it!=c.end();it++)
	cout<<*it<<" ";
	else cout<<"What a pity!";
	return 0;
} 
