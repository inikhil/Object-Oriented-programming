#include<iostream>
using namespace std;
class node{
    node(int k)
    {
        key=k;
    }
    int key;
    node *p;
    node *left;
    node *right;
}
class btree{
    btree():root(0){};
    void insert(node *z);
    int inorder(node *root);
}
void btree::insert(node *z)
{
    node *y=0;
    x=root;
    while(x!=0)
    {
        y=x;
        if(z->key<x->key)
        {
            x=x->left;
        }
        else
        {
            x=x->right;
        }
    }
    z->p=y;
    if(y==0)
    {
        root=z;
    }
    else if(z->key<y->key)
    {
        y->left=z;
    }
    else
    {
        y->right=z;
    }
}
void btree::inorder(node *x)
{
    if(x!=0)
    {
        inorder(x->left);
        cout<<x->key<<" ";
        inorder(x->right);
    }

}
int main()
{
    int m,x;
    node temp;
    btree ob;
    while(m!=3)
    {
        cout<<"1 to insert"<<endl;
        cout<<"2 to print"<<endl;
        cout<<"3 to exit"<<endl;
        cin>>m;
        switch(m){
        case 1:
           cout<<"enter value to insert "<<endl;
           cin>>x;
           ob.insert(x);
           break;
        case 2:
           ob.inorder(root);
        }
    }
    return 0;
}
