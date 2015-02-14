#include<iostream>
#include<cmath>
using namespace std;
class node{
    public:
    node(int key,node *q=0,node *r=0)
    {
        k=key;
        next=q;
        nn=r;
    }
    int k;
    node *next;
    node *nn;
};
class hash{
    public:
    hash(){};
    hash(int d){m=d;};
    int hashinsert(node *p,int k);
    int hashsearch(node *p,int k);
    int hf(int k);
    int print(node *p);
    int del(node *p,int k);
    int k,i;
    int m;
    int *p;
};

int hash::hashinsert(node *p,int k)
{
    int i=0,j;
    if(hashsearch(p,k)==0)
    {
        cout<<"please enter different number already present"<<endl;
        return 0;
    }
    node *q=0,*r=0;
    j=hf(k);
    while(i!=j)
    {
        p=p->nn;
        i++;
    }
    q=new node(k);
    r=p->next;
    p->next=q;
    q->next=r;
}
int hash::hashsearch(node *p,int k)
{
    int i=0,j;
    j=hf(k);
    while(i!=j)
    {
        p=p->nn;
        i++;
    }
    p=p->next;
    while(p!=0)
    {
        if(p->k==k)
        {
            return 0;
        }
        p=p->next;
    }
    return 1;

}
int hash::hf(int k)
{
    return (k%m);
}
int hash::print(node *start)
{
    int i;
    node *q=0;
    q=start;
    for(i=0;i<m;i++)
    {
        start=start->next;
        while(start!=0)
        {
            cout<<start->k<<"-->";
            start=start->next;
        }
        q=q->nn;
        start=q;
        cout<<"\n";
    }
}
int hash::del(node *p,int k)
{
    int i=0,f,j;
    node *q,*r;
    f=hashsearch(p,k);
    if(f==0)
    {
        j=hf(k);
        while(i!=j)
        {
            p=p->nn;
            i++;
        }
        while(p!=0)
        {
            r=p;
            p=p->next;
            q=p->next;
            if(p->k==k)
            {
                r->next=q;
                return 0;
            }
        }
    }
    else
        cout<<"Not found "<<endl;
}
int main()
{
    int n,i,m,t,e=1;
    node *a,*start;
    node *b;
    cout<<"Enter your size of array: "<<endl;
    cin>>n;
    for(i=0;i<=(n-1);i++)
    {
        e=e*2;
    }
    hash ob(e);
    for(i=0;i<e;i++)
    {
        if(i==0){
        a=new node(0);
        start=a;
        }
        b=new node(0);
        a->nn=b;
        a=b;
    }
    for(i=0;i<n;i++)
    {
        cout<<"Enter your value to insert: ";
        cin>>t;
        ob.hashinsert(start,t);
    }
   /* for(i=0;i<e;i++)
    {
        cout<<start->k<<" ";
        start=start->nn;
    }*/
    while(m!=4)
    {
        cout<<"1 to insert "<<endl;
        cout<<"2 to print "<<endl;
        cout<<"3 to delete"<<endl;
        cout<<"4 to exit :"<<endl;
        cin>>m;
        switch(m){
        case 1:
            cout<<"enter value to insert ";
            cin>>t;
            ob.hashinsert(start,t);
            break;
        case 2:
            ob.print(start);
            break;
        case 3:
            cout<<"Enter value to delete : ";
            cin>>t;
            ob.del(start,t);
            break;
        }

    }
    return 0;
}
