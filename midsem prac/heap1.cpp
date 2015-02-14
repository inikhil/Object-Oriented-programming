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
class node
{
    public:
        node(int d,node *p=0)
        {
            data=d;
            next=p;
        }
        int data;
        node *next;
};

node *p=0,*q=0,*start=0;
node *temp=0,*temp1=0,*temp2=0,*temp3=0,*temp4=0,*temp5=0;
void print()
{
    for(;temp5!=0;temp5=temp5->next)
    {
            cout<<temp5->data<<" ";
    }
    temp5=start;
}
void max_heapify(int i)
{
    int l,r,largest,t,k=0,k1=0,k2=0,k3=0;
    temp=start;
    temp1=start;
    temp2=start;
    temp3=start;
    while(k2<i-1)
    {
        temp2=temp2->next;
        k2=k2+1;
    }
    //cout<<temp2->data<<endl;
    l=left(i);
    //cout<<l<<endl;
    if(l>tx)
    {
        return;
    }
    while(k<l-1)
    {
        temp=temp->next;
        k=k+1;
    }
    //cout<<temp->data<<endl;
    r=right(i);
    while(k1<r-1)
    {
        temp1=temp1->next;
        k1=k1+1;
    }
    //cout<<temp1->data<<endl;


    //cout<<l;
    //cout<<r;
    //cout<<a[l];
    if((l<=tx) &&((temp->data)>(temp2->data)))
        {
        largest=l;
       // cout<<largest<<" ";
        }

    if(l<=tx)
    {
        if((temp->data)<(temp2->data))
        {
        largest=i;
        //cout<<largest<<" ";
        }
    }
    while(k3<largest-1)
    {
        temp3=temp3->next;
        k3=k3+1;
    }

    if(r<=tx)
    {
        if((temp1->data)>(temp3->data))
        {
        largest=r;
        //cout<<largest<<" ";
        }
    }
    while(k3<largest-1)
    {
        temp3=temp3->next;
        k3=k3+1;
    }
    //cout<<temp3->data<<" ";
    if(largest!=i)
    {
        t=temp3->data;
        //cout<<t;
        temp3->data=temp2->data;
        temp2->data=t;
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

void heapsort()
{
    int m,i,j=0;
    build_maxheap();
    for(i=10;i>1;i--)
    {
        m=temp4->data;
        temp4->data=start->data;
        start->data=m;
        tx=tx-1;
        max_heapify(1);
        print();
        temp4=start;
        while(j<tx-1)
        {
            temp4=temp4->next;
            j=j+1;
        }
        j=0;
        cout<<"\n";
    }
    print();
}
int main()
{

    int i=0,n;
    while(i!=11)
    {
        if(i==0)
        {
            p=new node(22234,0);
            q=p;

        }
        else
        {
            cout<<"Enter your data: ";
            cin>>n;
            p=new node(n,0);
            q->next=p;
            q=p;
            if(i==1)
            {
                start=p;
                temp5=p;
            }
            if(i==10)
            {
                temp4=p;
            }
        }
        i=i+1;
    }
    heapsort();
    return 0;

}

