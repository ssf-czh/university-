//´ò±í±©Á¦ 
#include <bits/stdc++.h>
#define N 100010
using namespace std;
bool flag[N]={false};
int n;
void init()
{
	flag[1]=true;
	flag[0]=true;
	for(int i=2;i<=N;i++)
	{
		for(int j=2;j<=sqrt(i);j++)
		if(i%j==0)
		{
			flag[i]=true;
			break;
		}
	}
}
int main()
{
	int sum=0;
	cin>>n;
	init();
	for(int i=0;i<=n;i++)
	{
		int f1=0,f2=0;
		int j;
		for(j=i-1;j>=i-10&&j>=0;j--)
		{
			if(flag[j]==false)
			{
				f1=1;break;
			}
		}
		for(j=i+1;j<=i+10;j++)
		if(flag[j]==false)
		{
			f2=1;break;
		}
		if(f1&&f2&&flag[i]==false)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
