P327
--！
//AVL树的简单操作
#include <bits/stdc++.h>
using namespace std;
struct node//带有高度的结点 一般初始为1
{
    int val,height;
    node *lchild,*rchild;    
};
node *newnode(int x)
{
    node *temp=new node;
    temp->val=x;
    temp->lchild=0;
    temp->rchild=0;
    temp->height=1;
    return temp;
}
int getheight(node *r)//注意NULL
{
    if(r==NULL)return 0;
    else return r->height;
}
void updateheight(node *r)//更新当前r的高度  加上本身 +1
{
    r->height=max(getheight(r->lchild),getheight(r->rchild))+1;
}
int getbal(node *r)//获得平衡因子 注意是左边减去右边
{
    return getheight(r->lchild)-getheight(r->rchild);
}
void R(node *&r)//右旋
{
    node *temp=r->lchild;
    r->lchild=temp->rchild;
    temp->rchild=r;
    updateheight(r);// 先更新r结点的高度
    updateheight(temp);//再更新temp结点的高度
    r=temp;
}
void L(node *&r)//左旋
{
    node *temp=r->rchild;
    r->rchild=temp->lchild;
    temp->lchild=r;
    updateheight(r);// 先更新r结点的高度
    updateheight(temp);//再更新temp结点的高度
    r=temp;
}
void insert(int x,node *&r)
{
    if(r==NULL)
    {
        node *temp=newnode(x);
        r=temp;
        return;
    }
    else
    {
        if(r->val==x)return;
        else if(x<r->val)
        {
            insert(x,r->lchild);
            updateheight(r);//采用了回溯的思想 只有在insert()后才可以update高度
            int bal=getbal(r);
            if(bal==2)
            {
                if(getbal(r->lchild)>=0)R(r);
                else
                {
                    L(r->lchild);
                    R(r);
                }
            }
        }
        else
        {
            insert(x,r->rchild);
            updateheight(r);
            int bal=getbal(r);
            if(bal==-2)
            {
                if(getbal(r->rchild)<0)L(r);
                else
                {
                    R(r->rchild);
                    L(r);
                }
            }
        }
    }
    
}
void dfs(node *r)
{
    if(r==0)return;
    dfs(r->lchild);
    cout<<r->val<<"  ";
    dfs(r->rchild);
}
int main()
{
    node *r=NULL;//空树;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        insert(t,r);
    }
    dfs(r);
    return 0;
}
