书P332

#include <bits/stdc++.h>
#define N 1001
using namespace std;
bool isroot[N];
int father[N];
int n,m;
void init()
{
    for(int i=1;i<=n;i++)
    father[i]=i;
}
int findfather(int x)
{
    if(x==father[x])return x;
    return findfather(father[x]);
    /*
      路径压缩
      if(x==father[x])return x;
      else
      {
        int f=findfather(father[x]);
        father[x]=f;
        return f;
       }
    
    
    */
}
void Union(int a,int b)
{
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa!=fb)
    {
        father[fb]=fa;
    }
}
int main()
{
    
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        //如果f(i)==i的话就说明是根节点 假如f(1)=2的话就不是
        /*；或者用一个 isroot[N]
            isroot[father[i]]=true;把头结点true 最后统计一下
          如果统计几何数量  就吧isroot弄成int  然后++;
        */  
        if(father[i]==i)sum++;
    }
    cout<<sum;
    return 0;
}
