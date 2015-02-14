#include<iostream>
#include<cstdlib>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d,node *p=0)
        {
            data=d;
            next=p;
        }
};
int main()
{
    node *p
    node *q=0;
    cout<<"input your value of n"<<endl
    cin>>n
    while(cin>>n)
    {
        q=new node(n,p);
        p->next=q;

    }
    return 0;

}
