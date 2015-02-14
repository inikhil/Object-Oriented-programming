#include<iostream>
using namespace std;
class heap{
    public:
        int i;
        int k;
        heap(){i=0;}
        heap(int j){i=j;}
        int parent(int i){return i/2;}
        int left(int i){return 2*i;}
        int right(int i){return 2*i+1;}
        void max_heapify(int *p,int i);
        int get_values(int i){return i;}
};
void heap::max_heapify(int *p,int i)
{
    int l,r,largest,t;
    l=left(i);
    cout<<p[2]<<" ";
    r=right(i);
    if((l<=10)&&p[l]>p[i])
        largest=l;
    else
        largest=i;
    if((r<=10)&&p[r]>p[largest])
        largest=r;
    if(largest!=i)
    {
        t=p[i];
        p[i]=p[largest];
        p[largest]=t;
        max_heapify(p,largest);
    }
}
int main()
{
    int i;
    heap a[10]={16,14,10,8,7,9,3,2,4,1};
    heap *p;
    p=a;
    for(i=0;i<10;i++)
    {
        cout<<p->get_values(a[i].i)<<" ";
        p=p+i;
       // p=p+i;
    }
    p=a;
    for(i=0;i<10;i++)
    {
       cout<<p<<" ";
    }/*
   //p->max_heapify(2);
    //a[10].max_heapify(p,2);
    //cout<<a[10].get_values(p);*/
}
