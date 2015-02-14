#include<iostream>
using namespace std;
int a[11];
int tx=10;
int parent(int i)
{
    return (i/2);
}
int left(int i)
{
    return (2*i);
}
int right(int i)
{
    return (2*i+1);
}
void max_heapify(int i)
{
    int l,r,largest,t;
    l=left(i);
    r=right(i);
    if(l>tx)
    {
        return;
    }

    //cout<<l;
    //cout<<r;
    //cout<<a[l];
    if((l<=tx) &&(a[l]>a[i]))
        {
        largest=l;
        //cout<<largest<<" ";
        }

    if(l<=tx)
    {
        if(a[l]<a[i])
        {
        largest=i;
        //cout<<largest<<" ";
        }
    }
    if(r<=tx)
    {
        if(a[r]>a[largest])
        {
        largest=r;
        //cout<<largest<<" ";
        }
    }
    if(largest!=i)
    {
        t=a[largest];
        a[largest]=a[i];
        a[i]=t;
        max_heapify(largest);
    }

}
void build_maxheap()
{
    int i;
    for(i=5;i>0;i--)
    {
        max_heapify(i);
    }
}
void print()
{
    int i;
    for(i=1;i<11;i++)
    {
            cout<<a[i]<<" ";
    }
}
void heapsort()
{
    int m,i,j;
    build_maxheap();
    for(i=10;i>1;i--)
    {
        m=a[i];
        a[i]=a[1];
        a[1]=m;
        tx=tx-1;
        max_heapify(1);
        print();
        cout<<"\n";

    }
}
int main()
{
    int i,n;
    a[0]=7558;
    for(i=1;i<11;i++)
    {
        cin>>a[i];
    }
    heapsort();
    for(i=1;i<11;i++)
    {
            cout<<a[i]<<" ";
    }
    return 0;

}
