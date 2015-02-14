#include<iostream>
using namespace std;
class node
{
    public:
    node(int d,node *p)
    {
        data=d;
        next=p;
        prev=p;
    }
    int data;
    node *next;
    node *prev;

};
int main()
{
  int i=0;
  node *p=0,*q=0,*r=0,*s=0;
  int a;
  node *head,*start,*temp;
  while(i!=3)
  {

      if(i==0)
      {
        cin>>a;
        p=new node(a,0);
        q=p;

      }
      if(i>0)
      {
          cin>>a;
          p=new node(a,0);
          q->next=p;
          p->prev=q;
          q=p;
      }
      if(i==2)
      {
          head=p;
      }
      if(i==0)
      {
          temp=p;
      }
      i=i+1;
  }
  /*cin>>a;
  start=new node(a,0);
  start->next=temp;
  temp=start;

  /* for(;head!=0;head=head->next)
  {
      r=new node(head->data,s);
      s=r;
  }*/
  for(;head!=0;head=head->prev)
{
        cout<<head->data<<endl;
}




/*for(;head!=0;head=head->prev)
{
        cout<<head->prev<<endl;
}

  /*for(;r!=0;r=r->next)
  {
      cout<<r->data<<endl;
  }*/
  return 0;
}
