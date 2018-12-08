//简单的映射map的操作 把边排序完弄成一一对应的字符串 再映射
//初始如果三角形不存在 则默认为0
//也可以用mp.count(string temp)来判断个数或者用mp.find(string temp)==mp.end()来判断是否存在 
#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str[3];
		cin>>str[0]>>str[1]>>str[2];
		sort(str,str+3);
		string temp=str[0]+" "+str[1]+" "+str[2];
		mp[temp]++;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string str[3];
		cin>>str[0]>>str[1]>>str[2];
		sort(str,str+3);
		string temp=str[0]+" "+str[1]+" "+str[2];
		cout<<mp[temp]<<endl;
	}
	return 0;
}
