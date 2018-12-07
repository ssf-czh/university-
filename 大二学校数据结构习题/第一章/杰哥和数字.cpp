//这道题暴力过不了
//需要优化 通过p=a*b 一定有a<=sqrt(p) b>=sqrt(p) 或者有b<=sqrt(p) a>=sqrt(p) 
//注意判断 a=b=sqrt(p) 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool num[10]={false};
bool judge(int n)
{
	while(n)
	{
		if(num[n%10]==true)return true;
		n/=10;
	}
	return false;
}
int main()
{
    ll n;
    cin>>n;
    ll temp=n;
    while(temp)
    {
       num[temp%10]=true;
       temp/=10;
	}
	int sum=0;
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(judge(i))
			sum++;
			if(i!=n/i&&judge(n/i))
			sum++;
			
		}
	}
	cout<<sum;
	return 0;
}
