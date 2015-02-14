#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class node{
    public:
    node(double k,double k1,int i,node *p=0)
    {
        key1=k;
        key2=k1;
        id=i;
        next=p;
    }
    node *next;
    double key1,key2;
    int id;
};
/*class list{
    public:
    list(){};
    void adjacencylist();
    void dfs();
};*/

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
    double a[n][2];
    for(i=0;i<n;i++)
    {
        a[i][0]=((double)rand()/RAND_MAX)*l;
        a[i][1]=((double)rand()/RAND_MAX)*l;
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }
    cout<<"\n";
    node** temp=new node* [n];
    for(i=0;i<n;i++)
    {
        p=new node(a[i][0],a[i][1],1);
        temp[i]->next=p;
    }
    for(i=0;i<n;i++)
    {
        cout<<temp[i]->next->key1<<endl;
    }
    return 0;
}
