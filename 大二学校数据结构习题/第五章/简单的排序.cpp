
//由于数字在数组可开区域 所以可以用桶排序  

//#include <bits/stdc++.h>
//using namespace std;
//int a[200000+10];
//int main()
//{
//	int n;
//	int t;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&t);
//		a[t+100000]++;
//	}
//	for(int i=0;i<=2e5;i++)
//	{
//		for(int j=0;j<a[i];j++)
//		printf("%d ",i-100000);
//	}
//	return 0;
//} 


#include <stdio.h>
int a[100000+1];
int b[100000+1];
int main()
{
	int n,i,j;
	int t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t>=0)
		a[t]++;
		else
		b[t*-1]++;
	}
	for( i=100000;i>=0;i--)
	{
		for(j=0;j<b[i];j++)
		printf("%d ",i*-1);
	}
	for(i=0;i<=100000;i++)
	{
		for(j=0;j<a[i];j++)
		printf("%d ",i);
	}
	return 0;
} 
