#include<iostream>
#include<cstdlib>
using namespace std;
class node{
    public:
        int data;
        float tim;
        int id;
        node *next;
        node(int d,float t, int m,node *p=0)
        {
            data=d;
            next=p;
            tim=t;
            id=m;
        }
};
int main()
{
    int n,i=0,t,x,z;
    float y;
    node *p,*start=0,*temp=0,*temp1=0;
    node *q=0;

    while(i<5)
    {
        cout<<"input your time and data for  " <<i<<"st job "<<endl;
        cin>>n;
        cin>>t;
        p=new node(n,t,i,q);
        //cout<<p->data<<endl;
        q=p;
        //cout<<q->data<<endl;
        if(i==4)
        {
            start=p;
            temp=p;
        }
        if(i==3)
        {
            temp1=p;
        }
        i++;
    }

    while(temp->next!=0)
    {
        while(temp1!=0)
        {
            if((temp->data)<(temp1->data))
            {
                x=temp->data;
                y=temp->tim;
                z=temp->id;
                cout<<temp->data;
                temp->data=temp1->data;

                temp->id=temp1->id;
                temp->tim=temp1->tim;
                temp1->data=x;
                temp1->tim=y;
                temp1->id=z;
                temp1=temp1->next;
            }
            else
            {
                temp1=temp1->next;
            }
        }
        temp=temp->next;
        temp1=temp->next;

    }
    while(start!=0)
    {
        cout<<start->data<<" "<<start->tim<<" "<<start->id<<" "<<endl;
        start=start->next;
    }


    return 0;

}
