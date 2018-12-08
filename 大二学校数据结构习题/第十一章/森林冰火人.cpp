//直接暴力不行 需要优化一下 start 就是把已经是0的雪人堆给去掉 
#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<n;i++)
	{
		int t;cin>>t;
		b.push_back(t);
	}
	int start=0;
	for(int i=0;i<n;i++)
	{
		int sm=0;
		while(start<n&&a[start]==0)
		{
			start++;
		}
		for(int j=start;j<=i;j++)
		{
			if(a[j]>=b[i])
			{
				a[j]-=b[i];
				sm+=b[i];
			}
			else
			{
				sm+=a[j];
				a[j]=0;
			}
		}
		cout<<sm<<" ";
	}
	return 0;
 } 
