//建立一个mxa数组 mxa[i]表示第i个之后的最大的数 
#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int n;
int a[100010];
int mxa[100010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=n-1;i>=0;i--)
	{
		mxa[i]=a[i];
		mxa[i]=max(mxa[i],mxa[i+1]);
	}
	for(int i=0;i<n;)
	{
		int mx=mxa[i];
		//找到最大的数 并且一直入栈 
		while(s.empty()||s.top()<mx)
		{
			s.push(a[i++]);
			if(i>=n)break;
		}
		//最大的数出栈 
		cout<<s.top()<<" ";
		s.pop();
		//如果栈顶比最大的数来的大 就一直出栈 
		while(s.size()&&i<n&&s.top()>mxa[i])
		{
			cout<<s.top()<<" ";
			s.pop();
		}
	}
	while(s.size())
	{
		cout<<s.top()<<" ";
			s.pop();
	}
	return 0;
}
