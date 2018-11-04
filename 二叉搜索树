书P313
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val,bal;
    node *lchild,*rchild,*father;
};
node *creat(int x)
{
    node *t=new node;
    t->lchild=0;
    t->rchild=0;
    t->bal=0;
    t->val=x;
    return t;
}
void insert(int x,node * &r)
{
    if(r==NULL)
    {
        node *temp=creat(x);
        temp->father=p;
        r=temp;
    }
    if(r->val==x)return;
    else if(x<r->val)insert(x,r->lchild);
    else insert(x,r->rchild);
}
/*//针对设置父亲结点的二叉树
void insert(int x,node * &r,node *p)
{
    if(r==NULL)
    {
        node *temp=creat(x);
        temp->father=p;
        r=temp;
    }
    if(r->val==x)return;
    else if(x<r->val)insert(x,r->lchild,r);
    else insert(x,r->rchild,r);
}
*/
void dfs(node *r)
{
    if(r==0)return;
    dfs(r->lchild);
    cout<<r->val<<"  ";
    dfs(r->rchild);
}
node *findmax(node *r)
{
    while(r->rchild!=NULL)
    r=r->rchild;
    return r;
}
node *findmin(node *r)
{
    while(r->lchild!=NULL)
    r=r->lchild;
    return r;
}
void deletenode(node *&r,int x)
{
    //初始r不为空 即树不是空树;
    if(r->val==x)
    {
        if(r->lchild==NULL&&r->rchild==NULL)r=NULL;
        else if(r->lchild)//左子树不为空 找左子树中 最大的元素结点
        {
            node *temp=findmax(r->lchild);
            r->val=temp->val;

        //    temp->father->rchild=temp->lchild;//针对有父亲结点的二叉树
            deletenode(r->lchild,temp->val);
        }
        else
        {
            node *temp=findmin(r->rchild);
            r->val=temp->val;
            cout<<"666"<<endl;
            //temp->father->lchild=temp->rchild;//针对有父亲结点的二叉树
               deletenode(r->rchild,temp->val);
        }
    }
    else if(x<r->val)deletenode(r->lchild,x);
    else deletenode(r->rchild,x);
}
int main()
{
    node *r=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        insert(t,r);//insert(t,r,NULL);针对有父亲结点的二叉树
    }
    dfs(r);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        deletenode(r,t);
        dfs(r);
        cout<<endl;
    }

    return 0;
}
