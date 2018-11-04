书P355

//默认堆顶是最小值
#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int heap[maxn];
void downadjust(int p,int n)
{
    //n就是heap[0]
    int val=heap[p];
    int i=p,j=2*i;//j是左孩子
    while(j<=n)//至少有左孩子
    {
        if(j+1<=n&&heap[j+1]<heap[j])//右孩子val比左孩子小val
        j++;
        //这时候heap[j]已经是左右孩子中最小的了
        if(val<=heap[j])break;
        else
        {
            swap(heap[i],heap[j]);
            i=j;
            j=i*2;    
        }
    }
}
int delroot()
{
    int temp=heap[1];
    heap[1]=heap[heap[0]];//把最后一个提前到第一个 除了第一个root，在root的子树都是heap
    heap[0]--;//个数减一 就是二叉树减一
    //维护heap
    downadjust(1,heap[0]);//此操作有描述，自底而上 前提是子树已经是heap
    return temp;
}
void add(int x)//添加 就是把他放在最后一个heap[heap[0]+1]处 向上调整
{
    heap[heap[0]+1]=x;
    heap[0]++;
    int i=heap[0];
    int j=i/2;//j是当前元素的父亲结点；
    while(j>=1)
    {
        if(x>heap[j])break;
        else{
            swap(heap[i],heap[j]);
            i=j;
            j=i/2;
        }
    }
    
}
int main()
{
    int n;//n为堆的大小
    cin>>n;
    heap[0]=n;
    //也可以把heap[0]作为堆的大小
    for(int i=1;i<=n;i++)//////注意!!!这是i是从1开始 树的标记是1开始
    cin>>heap[i];
    for(int i=n/2;i>=1;i--)
    {
        downadjust(i,heap[0]);//因为近似满二叉树不是叶子结点的最大编号一定是n/2
        //donnadjust()是当前左右子树已经是heap时才作用
        //因为从n/2+1到n都是叶子结点就是heap
        //downadjusr是回溯 自底而上的
    }
    cout<<"*****************************************"<<endl;
    for(int i=1;i<=n;i++)
    cout<<heap[i]<<" ";
    cout<<endl;
    cout<<"*****************************************"<<endl;
    
    int get_val=delroot();//删除优先级最高的 就是heap[1]
    cout<<get_val<<endl;
    for(int i=1;i<=heap[0];i++)
    cout<<heap[i]<<" ";
    cout<<endl;
    cout<<"*****************************************"<<endl;
    int ele;
    cin>>ele;
    add(ele);
    for(int i=1;i<=heap[0];i++)
    cout<<heap[i]<<" ";
    cout<<endl;
    cout<<"*****************************************"<<endl;
    return 0;
}














