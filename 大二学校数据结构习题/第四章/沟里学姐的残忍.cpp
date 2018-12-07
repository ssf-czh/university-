//通过前缀和 然后遍历一遍即可
//a[i]为前i个的前缀和 
//a[j]-a[i-1]为第i个到第j个的总和 
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int a[N];
int n,k;
int main()
{
	a[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[i]=a[i-1]+t;
	} 
	int b,e,mx=-110000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i+k&&j<=n;j++)
		{
			if(a[j]-a[i-1]>mx)
			{
				b=i;
				e=j;
				mx=a[j]-a[i-1];
			}
		}
	}
	cout<<mx<<" "<<b<<" "<<e;
	return 0;
}
