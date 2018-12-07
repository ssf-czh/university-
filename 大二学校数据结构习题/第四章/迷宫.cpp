//最简单的bfs模板 

#include <bits/stdc++.h>
using namespace std;
char mp[1001][1001];
struct node
{
	int x,y,step;
	node(int a,int b,int c)
	{
		x=a;y=b;step=c;
	}
	node()
	{
		
	}
};
int v[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
node s,e;
queue <node> q; 
bool vis[1001][1001];
int n,m;
bool judge(int x,int y)
{
	if(vis[x][y]==true||x<=0||x>n||y<=0||y>m||mp[x][y]=='#')return false;
	return true;
}
int bfs()
{
	
	q.push(s);
	vis[s.x][s.y]=true;
	while(!q.empty())
	{
		node temp=q.front();
		if(temp.x==e.x&&temp.y==e.y)return temp.step;
//		cout<<temp.x<<" "<<temp.y<<"   !"<<endl;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int X=temp.x+v[i][0];
			int Y=temp.y+v[i][1];
			if(judge(X,Y))
			{
				q.push(node(X,Y,temp.step+1));
				vis[X][Y]=true;
			}
		}
		
	}
	return -1;
}
int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]=='S')
			{
				s.x=i;
				s.y=j;
				s.step=0;
			}
			if(mp[i][j]=='E')
			{
				e.x=i;
				e.y=j;
			}
		}
		getchar();
	}
	cout<<bfs();
	return 0;
}
