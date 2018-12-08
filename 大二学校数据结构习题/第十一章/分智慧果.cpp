//优先队列的应用 算法复杂度在nlogn 
//#include <bits/stdc++.h>
//using namespace std;
//priority_queue<int ,vector<int>,less<int> > q;
//int main()
//{
//	int n;
//	int t;
//	cin>>n;
//	cin>>t;
//	for(int i=0;i<n-1;i++)
//	{
//		int tt;cin>>tt;
//		q.push(tt);
//	}
//	int sm=0;
//	while(!q.empty())
//	{
//		int mx=q.top();
////		cout<<"max= "<<mx<<endl;
////		cout<<"t= "<<t<<endl;
//		if(t>=mx)break;
//		q.pop();
//		t++;
//		mx--;
//		sm++;
//		q.push(mx);
//	}
//	cout<<sm;
//	return 0;
//}



#include <bits/stdc++.h>
using namespace std;
priority_queue <int, vector<int>, less<int> > q;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int fst;
	cin>>fst;
	for(int i=0;i<n-1;i++)
	{
		int t;
		cin>>t;
		q.push(t);
	}
	while(!q.empty())
	{
		int t=q.top();
		q.pop();
		if(fst>=t)break;
		fst++;
		ans++;
		q.push(--t);
	}
	cout<<ans;
	return 0;
}

