p374





#include <bits/stdc++.h>
#define N 1010
#define INF 100010
using namespace std;
struct node
{
   int v, val;
   node(int a,int b)
   {
       v=a;val=b;
    }    
};
int bianhao=-1;
vector<node> adj[N];
int d[N];
int ansmax=-1,anssum=INF;
bool vis[N]={false};
void add(int a,int b,int c)
{
    adj[a].push_back(node(b,c));
    adj[b].push_back(node(a,c));
}
map<string ,int> strtoint;
map<int ,string>inttostr;
int n,m,k,len;
int cnt;
int sti(string temp)
{
    if(strtoint.find(temp)!=strtoint.end())
    return strtoint[temp];
    strtoint[temp]=cnt;
    inttostr[cnt]=temp;
    return cnt++;
}
void dijkstr()
{
    //printf("%d,%d\n",n+1,cnt-1);
    for(int p=n+1;p<cnt;p++)
    {
        fill(d,d+N,INF);
        fill(vis,vis+N,false);
        d[p]=0;
        for(int i=0;i<n+m;i++)
        {
            int MIN=INF,u=-1;
            for(int j=1;j<=n+m;j++)
            {
                if(vis[j]==false&&d[j]<MIN)
                {
                    u=j;
                    MIN=d[j];
                }
            }
            if(u==-1)return ;
            vis[u]=true;
            for(int k=0;k<adj[u].size();k++)
            {
                int v=adj[u][k].v;
                int val=adj[u][k].val;
                if(vis[v]==false&&d[u]+val<d[v])
                d[v]=d[u]+val;    
            }
        }
    /*    for(int l=1;l<=n;l++)
        cout<<d[l]<<" ";
        cout<<endl;*/
           int f=0;
           int tempsum=0;
           int tempmin=INF;
           for(int l=1;l<=n;l++)
           {
               if(d[l]>len)
               {   f=1;
                   break;
            }
               tempsum+=d[l];
               tempmin=min(tempmin,d[l]);
           }
           if(f)continue;
           if(tempmin>ansmax)
           {
               bianhao=p;
               ansmax=tempmin;
               anssum=tempsum;
           }
           else if(tempmin==ansmax&&tempsum<anssum)
           {
               bianhao=p;
               anssum=tempsum;
           }
                   
    }
}
int main()
{
    cin>>n>>m>>k>>len;
    cnt=n+1;
    for(int i=0;i<k;i++)
    {
        string a,b;
        int temp;
        cin>>a>>b>>temp;
        int t1,t2;
        if(a[0]=='G')t1=sti(a);
        else t1=a[0]-'0';
        if(b[0]=='G')t2=sti(b);
        else t2=b[0]-'0';
        //cout<<t1<<"    "<<t2<<"   "<<temp<<endl;
        add(t1,t2,temp);
        
    }
    dijkstr();
    if(bianhao==-1)cout<<"No Soluation";
    else
    {
        cout<<inttostr[bianhao]<<" "<<ansmax<<" ";
    printf("%.1lf",(double)anssum/n);
    }

    return 0;
}


4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
