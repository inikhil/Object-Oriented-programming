#include<iostream>
using namespace std;
class node{
        public:
        node(int k,node *p=0){
                key=k;
                next=p;
        }
        node *next;
        int key;
};
node *start,*x,*d=0;
void printlist(node *d,node *start)
{
        node *z;
        cout<<"Reversed list is : ";
        for(z=d;z!=0;z=(z->next)){
                cout<<z->key<<"->";
        }
        cout<<"\n";
        cout<<"Unreversed list is: ";
        for(z=start;z!=0;z=(z->next)){
                cout<<z->key<<"->";
        }
        cout<<"\n";
}

node* search(int k,node *start,node *start1)
{
        node *r,*s,*t;
        r=start;
        cout<<r->key<<endl;
        while(r!=0){
                if(r->key!=k){
                        if(d!=0){
                                s=r->next;
                                r->next=d;
                                d=r;
                                r=s;
                        }
                        if(d==0){
                                d=r;
                                r=r->next;
                                d->next=0;
                        }
                }
                else
                {
                        s=r->next;
                        r->next=d;
                        d=r;
                        start=s;
                        printlist(d,start);
                        return start;
                }
        }
        t=d;
        d=0;
        while(t!=0){
                if(t->key!=k){
                        if(d!=0){
                                s=t->next;
                                t->next=d;
                                d=t;
                                t=s;
                        }
                        if(d==0){
                                d=t;
                                t=t->next;
                                d->next=0;
                        }
                }
                else
                {
                        s=t->next;
                        t->next=d;
                        d=t;
                        start=s;
                        printlist(d,start);
                        x=d;
                        return start;
                }
        }
        /*if(start==start1){
                cout<<"No matches found "<<endl;
                printlist(d,start);
                return 0;
        }*/
}

int main()
{
        node *p,*q,*start1;
        int n,i,k,ch=0;
        cout<<"how many numbers you want to enter : ";
        cin>>n;
        cout<<"Enter your value to insert : ";
        cin>>k;
        p=new node(k,0);
        start=p;
        start1=p;
        for(i=1;i<n;i++){
                cout<<"Enter your value to insert : ";
                cin>>k;
                q=new node(k,0);
                p->next=q;
                p=q;
        }
        /*for(q=start;q!=0;q=(q->next)){
                cout<<q->key<<" ";
        }*/
        while(ch!=2){
                cout<<"Enter 1 to search "<<endl;
                cout<<"Enter 2 to exit "<<endl;
                cin>>ch;
                switch(ch){
                        case 1:
                                cout<<"Enter your value to search : ";
                                cin>>k;
                                start=search(k,start,start);
                                break;
                        case 2:
                                return 0;
                                break;
                }
        }
        return 0;
}
