//注意用到了dp思想
//pre[i]是以第i个元素为结尾的最长子段个数
//last[i]是以第i个元素为开头的最长子段个数
//用到了拼接 如果第i个的话满足可拼接条件 pre[i-1]和last[i+1]拼接 就是把第i个变一下 
#include <bits/stdc++.h>
using namespace std;
int main()
{ int n;
cin>>n;
int t=1;
 while(t--)
 { vector<int> v(n); 
 vector<int> pre(n,1); 
 vector<int> last(n,1); 
 for(int i=0;i<n;i++)
 { cin>>v[i]; } 
 for(int i=1;i<n;i++)
 { pre[i]=v[i]>v[i-1]?pre[i-1]+1:1; }
  for(int i=n-2;i>=0;i--)
  {  
  last[i]=v[i+1]>v[i]?last[i+1]+1:1; 
  }
   int res=1;
//for(int i=0;i<pre.size();i++)
//cout<<pre[i]<<" ";
//cout<<endl;
//for(int i=0;i<last.size();i++)
//cout<<last[i]<<" ";
//cout<<endl;
for(int i=1;i<n-1;i++)
{   
    res=max(res,pre[i]);
	res=max(res,last[i]); 
	if(v[i+1]-v[i-1]>=2) 
	res=max(res,pre[i-1]+last[i+1]+1); 
}
	res=max(res,1+last[1]);
	res=max(res,1+pre[n-2]);
	cout<<res<<endl; } 
	
	return 0; 
}
