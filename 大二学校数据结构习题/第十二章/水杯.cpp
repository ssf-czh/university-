//并查集的操作
//如果暴力 时间复杂度太高
//next[i]表示第i个水杯的下一个不满水杯的编号 初始化为本身 
#include <bits/stdc++.h>
#define N 100000+10
using namespace std;
int full[N];
int cur[N];
int next[N];
int findnext(int x)
{
	if(next[x]==x)return x;
	int f=findnext(next[x]);
	next[x]=f;
	return f;
}//路径压缩 
void merge(int a,int b)//b=a+1 如果a满了之后，a的next就等于b的next
{
	next[a]=next[b];
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>full[i];
	for(int i=0;i<=n+1;i++)
	next[i]=i;
	int q;
	cin>>q;
	while(q--)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			int x,y;
			cin>>x>>y;
			while(y)
			{
				x=findnext(x);
//				cout<<"xxx="<<x<<endl;
				if(x==n+1)break;
//				cout<<"! "<<full[x]-cur[x]<<endl;
				if(full[x]-cur[x]>=y)
				{
					
					cur[x]+=y;
					y=0;
//					cout<<cur[x]<<" !"<<endl;
				}
				else
				{
					y-=(full[x]-cur[x]);
					cur[x]=full[x];
					merge(x,x+1);
				}
			}	
		}
		else
		{
			int x;cin>>x;
			cout<<cur[x]<<endl;
		}
	}
	return 0;
}
