#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class node{
    public:
    node(int k,node *t=0,node *q=0,node *r=0,string s="BLACK")
    {
        key=k;
        p=t;
        left=q;
        right=r;
        color=s;
    }
    int key;
    node *p;
    node *left;
    node *right;
    string color;
};
class rbtree{
    public:
    node *root;
    rbtree(){root=0;};
    void insert(node *z);
    void insert1(node *z);
    void rbfixup(node *z);
    void leftrotate(node *x);
    void rightrotate(node *x);
    int print(node *x);

};
void rbtree::insert(node *z)
{
    node *y=0;
    node *x =root;
    while(x!=0)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==0)
        root=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->left=0;
    z->right=0;
    z->color="RED";
    //rbfixup(z);
}
void rbtree::insert1(node *z)
{
    node *y=0;
    node *x =root;
    while(x!=0)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==0)
        root=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->left=0;
    z->right=0;
    z->color="RED";
    rbfixup(z);
}
void rbtree::rbfixup(node *z)
{
    node *y;
    string coly;
    if(z->p == 0 || z->p->p == 0)
	{
		root->color="BLACK";
		return;
	}
    while((z!=root)&&((z->p->color)=="RED"))
    {
        if((z->p)==(z->p->p->left))
        {
            y=z->p->p->right;
            if(y==0)
            {
                coly="BLACK";
            }
            else
            {
                coly=y->color;
            }
            if(coly=="RED")
            {
                z->p->color="BLACK";
                y->color="BLACK";
                z->p->p->color="RED";
                z=z->p->p;
            }
            else {
            if(z==z->p->right)
            {
                z=z->p;
                leftrotate(z);
            }
            if(z->p!=0){
                z->p->color="BLACK";}
            if(z->p->p!=0){
                z->p->p->color="RED";
                rightrotate(z->p->p);
            }}
        }
        else
        {

            y=z->p->p->left;
            if(y==0)
            {
                coly="BLACK";
            }
            else
            {
                coly=y->color;
            }
            if(coly=="RED")
            {
                z->p->color="BLACK";
                y->color="BLACK";
                z->p->p->color="RED";
                z=z->p->p;
            }
            else{
            if(z==z->p->left)
            {
                z=z->p;
                rightrotate(z);
            }
            if(z->p!=0){
                z->p->color="BLACK";}
            if(z->p->p!=0){
                z->p->p->color="RED";
                leftrotate(z->p->p);
            }}
        }
    }
    root->color="BLACK";
}
void rbtree::leftrotate(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    if(y->left!=0)
        y->left->p=x;
    y->p=x->p;
    if(x->p==0)
        root=y;
    else {
    if(x==x->p->left)
        x->p->left=y;
    else
        x->p->right=y;}
    y->left=x;
    x->p=y;
}
void rbtree::rightrotate(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    if(y->right!=0)
        y->right->p=x;
    y->p=x->p;
    if(x->p==0)
        root=y;
    else{
    if(x==x->p->right)
        x->p->right=y;
    else
        x->p->left=y;}
    y->right=x;
    x->p=y;
}
int rbtree::print(node *x)
{
    if(x!=0)
    {
        print(x->left);
        cout<<x->key<<" "<<x->color<<endl;
        print(x->right);
    }
}
int main()
{
    int m=0,n;
    node *temp=0;
    rbtree ob;
    while(m!=5)
    {
        cout<<"press 1 to insert "<<endl;
        cout<<"press 2 to left rotate "<<endl;
        cout<<"press 3 to right rotate "<<endl;
        cout<<"press 4 to print"<<endl;
        cout<<"press 5 to exit "<<endl;
        cin>>m;
        switch(m){
        case 1:
            cout<<"Enter tour value to insert";
            cin>>n;
            temp = new node(n,0,0,0,"RED");
            ob.insert(temp);
            break;
        case 2:
            cout<<"Enter tour value to insert";
            cin>>n;
            temp = new node(n,0,0,0,"BLACK");
            ob.insert1(temp);
            break;
        case 4:
            ob.print(ob.root);
            break;
        }

    }
    return 0;

}
