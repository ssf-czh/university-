//主要vector 删除需要从后面开始往前删 不然删的顺序会乱 
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;cin>>t;
		a.push_back(t);
	}
	while(m--)
	{
		int tt;cin>>tt;
		int temp=tt-1;
		while(temp<a.size())
		temp+=tt;
		temp-=tt;
//		cout<<"temp="<<temp<<endl;
//		vector<int> :: iterator it;
		while(temp>=0)
		{
			a.erase(a.begin()+temp);
			temp-=tt;
		}
	}
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++)
	cout<<a[i]<<" ";
	return 0;
 } 
