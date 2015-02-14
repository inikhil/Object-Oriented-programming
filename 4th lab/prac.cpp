#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
int main()
{
    int d,i=0,n;
    struct node *p=0,*q=0,*start;
    p=new node;
    p->next=0;
    while(i<5)
    {
        cin>>n;

        q=new node;
        q->data=n;
        p->next=q;
        p=q;
        q->next=0;//////////////remember this mistake
        //cout<<p->data;
       // cout<<p->data;
        if(i==0)
        {
            start=q;
            //cout<<start->data<<endl;
        }
        i++;

    }
    for(;start;start=start->next)
    {
        cout<<start->data<<" ";
    }
    return 0;
}
