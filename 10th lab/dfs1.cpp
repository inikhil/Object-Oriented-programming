#include<iostream>
using namespace std;
class node
{
    public:
    node(int k,string co,node *q=0)
    {
        key=k;
        col=co;
        next=q;
    }
    int key;
    string col;
    node* next;
};
void dfsvisit(node** temp,int i)
{
    int v;
    node* q;
    temp[i]->col="GRAY";
    cout<<temp[i]->key<<"-->";
    q=temp[i]->next;
    while(q!=0)
    {
        if(temp[q->key]->col=="WHITE")
        {
            dfsvisit(temp,q->key);
        }
        q=q->next;
    }
}
void dfs(node** temp, int n)
{
    node* p;
    int i;
    p=temp[0];
    for(i=0;i<n;i++)
    {
        p=temp[i];
        if(p->col=="WHITE")
        {
            cout<<"\n";
            cout<<"The connected components are : " ;
            dfsvisit(temp,i);
        }
    }
}
int main()
{
    int n,t,i,j;
    cout<<"Input your value of n : " ;
    cin>>n;
    node** temp;
    node *p,*q;
    temp=new node*[n];
    for(i=0;i<n;i++)
    {
       temp[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>t;
            if(temp[i]==0)
            {
                temp[i]=new node(t,"WHITE",0);
                p=temp[i];
            }
            else
            {
                q=new node(t,"WHITE",0);
                p->next=q;
                p=q;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        p=temp[i];
        cout<<"The adjacency list for "<<i<<" is ";
        while(p!=0)
        {
            cout<<p->key<<"--->";
            p=p->next;
        }
        cout<<"\n";
        cout<<"\n";
    }
    dfs(temp,n);
}
