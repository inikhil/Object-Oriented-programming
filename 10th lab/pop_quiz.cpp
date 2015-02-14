#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class node{
    public:
    node(double k,double k1,int i,node *p=0,string co)
    {
        key1=k;
        key2=k1;
        id=i;
        next=p;
        col=co;
    }
    node *next;
    double key1,key2;
    int id;
    string col;
};
class lst{
    public:
    lst(int n1,double r1){n=n1;r=r1;};
    node** adjacencylist(node** temp,double** a);
    void printadjlist(node** temp);
    void dfs(node **temp,node** vertex);
    void dfsvisit(node **temp,int i,node** vertex);
    void connected(node **temp);
    int n;
    double r;
};
/*void lst::connected(node **temp,int i)
{
    node *p,*q;
    int k,j;
    p=temp[i];
    if((p!=0)&&(p->col=="WHITE"))
    {
        cout<<"\n";
        cout<<"the connected components for  "<< i <<" are ";
    }
    while(p!=0)
    {
        if(p->col=="WHITE")
        {
            i=p->id;
            cout<<p->id<<"--> ";
            for(k=0;k<n;k++)
            {
                for(q=temp[k];q!=0;q=q->next)
                {
                    if((q->id)==i)
                    {
                        q->col="GREY";
                    }
                }
            }
            p=temp[i];
        }
        else
        {
            p=p->next;
        }
    }
    if(i<n-1)
    {
        connected(temp,i+1);
    }
}*/
void lst::dfs(node** temp,node** vertex)
{
    node* p;
    int i;
    p=temp[0];
    for(i=0;i<n;i++)
    {
        p=vertex[i];
        if(p->col=="WHITE")
        {
            cout<<"\n";
            cout<<"The connected components are : " ;
            dfsvisit(temp,i,vertex);
        }
    }
}
void lst::dfsvisit(node** temp,int i,node **vertex)
{
    int v;
    node* q;
    vertex[i]->col="GRAY";
    cout<<vertex[i]->id<<"-->";
    q=temp[i];
    while(q!=0)
    {
        if(vertex[q->id]->col=="WHITE")
        {
            dfsvisit(temp,q->id,vertex);
        }
        q=q->next;
    }
    //return temp;
}
void lst::printadjlist(node** temp)
{
    node *p;
    int i;
    for(i=0;i<n;i++)
    {
        p=temp[i];
        cout<<"The adjacency list for "<<i<<" is ";
        while(p!=0)
        {
            cout<<p->key1<<","<<p->key2<<","<<p->id<<".....";
            p=p->next;
        }
        cout<<"\n";
        cout<<"\n";
    }
}
node** lst::adjacencylist(node** temp,double** a)
{
    node *p,*q;
    int i,j;
    double x1,x2,y1,y2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x1=a[i][0];
            y1=a[i][1];
            x2=a[j][0];
            y2=a[j][1];
            if((x1!=x2)||(y1!=y2))
            {
                if((((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<4*r*r))
                {
                    if(temp[i]==0)
                    {
                        temp[i]=new node(x2,y2,j,0,"WHITE");
                        p=temp[i];
                    }
                    else
                    {
                        q=new node(x2,y2,j,0,"WHITE");
                        p->next=q;
                        p=q;
                    }
                }
            }
        }
    }
    printadjlist(temp);
    return temp;
}
int main()
{
    int i,n,l;
    node *p,*q;
    double r;
    srand(time(NULL));
    cout<<"Input your value of n: ";
    cin>>n;
    cout<<"Input your value of l: ";
    cin>>l;
    cout<<"Input your value of r: ";
    cin>>r;
    //double a[n][2];
    double** a = new double*[n];
    for(i = 0 ; i < n ; i++)
        a[i] = new double[2];
    for(i=0;i<n;i++)
    {
        a[i][0]=((double)rand()/RAND_MAX)*l;
        a[i][1]=((double)rand()/RAND_MAX)*l;
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }
    cout<<"\n";
    node** vertex;
    vertex=new node*[n];
    node** temp=new node*[n];
    for(i=0;i<n;i++)
    {
       temp[i]=0;
       vertex[i]=0;
    }
    for(i=0;i<n;i++)
    {
        vertex[i]=new node(a[i][0],a[i][1],i,0,"WHITE");
    }
    lst ob(n,r);
    temp=ob.adjacencylist(temp,a);
    ob.dfs(temp,vertex);
    return 0;
}

