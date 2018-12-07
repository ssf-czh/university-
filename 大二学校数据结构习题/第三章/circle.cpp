//类似括号匹配问题 
//最后标准是看栈是否为空 如果匹配都成功 最后是个空栈 
#include  <bits/stdc++.h>
using namespace std;
stack <int> s;
int a[200000+10];
int cnt=1;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		while(!s.empty())
		s.pop();
		fill(a,a+100000+10,0);
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int u,v;			
			cin>>u>>v;
			a[u]=cnt;
			a[v]=cnt;
			cnt++;
		}
		for(int i=1;i<=2*n;i++)
		{
			if(a[i])//如果i有边的话 
			{
				if(s.empty())
				s.push(a[i]);
				else if(s.top()!=a[i])s.push(a[i]);
				else s.pop();
			}
		}
		if(s.empty())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

            

