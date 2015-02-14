#include<iostream>
#include<cmath>
using namespace std;
class hash{
    public:
    hash(){};
    hash(int *p,int d){p=0;m=d;};
    int hashinsert(int *p,int k);
    int hashsearch(int *p,int k);
    int hf(int k,int i);
    int print(int *p);
    int del(int *p,int k);
    int k,i;
    int m;
    int *p;
};

int hash::hashinsert(int *p,int k)
{
    int i=0,j;
    while(i!=m)
    {
        j=hf(k,i);
        if(p[j]==0)
        {
            p[j]=k;
            return 0;
        }
        else
        {
            i=i+1;
        }
    }
}
int hash::hashsearch(int *p,int k)
{
    int i=0,j;
    while(i!=m)
    {
        j=hf(k,i);
        if(p[j]==k)
        {
            return j;
        }
        i=i+1;
    }
    return 0;
}
int hash::hf(int k,int i)
{
    int a,b;
    a=k%m;
    b=1+k%(m-1);
    return ((a+i*b)%m);
}
int hash::print(int *start)
{
    int i;
    for(i=0;i<m;i++)
    {
        cout<<start[i]<<" ";
    }
    cout<<"\n";
}
int hash::del(int *start,int k)
{
    int i,f;
    f=hashsearch(start,k);
    if(f!=0)
    {
        start[f]=0;
    }
}
int main()
{
    int n,i,m,t,*start,e=1;
    cout<<"Enter your size of array: "<<endl;
    cin>>n;
    for(i=0;i<=(n-1);i++)
    {
        e=e*2;
    }
    int *a=new int[e];
    hash ob(a,e);
    for(i=0;i<e;i++)
    {
        a[i]=0;
    }
    start=a;
    for(i=0;i<n;i++)
    {
        cout<<"Enter your value to insert: ";
        cin>>t;
        ob.hashinsert(a,t);
    }
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
            ob.hashinsert(a,t);
            break;
        case 2:
            ob.print(a);
            break;
        case 3:
            cout<<"Enter value to delete : ";
            cin>>t;
            ob.del(a,t);
            break;
        }

    }
    return 0;
}
