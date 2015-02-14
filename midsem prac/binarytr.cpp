#include<iostream>
using namespace std;
class tree
{
    public:
       tree(int d,tree *p,tree *q)
       {
           data=d;
           left=p;
           right=q;
       }
       int data;
       tree *left;
       tree *right;
};
tree *root,*temp;
int tp=0;
void insert()
{

    int val;
    tree *temp1=0;
    while(tp<5)
    {
        tp=tp+1;
        cout<<" Enter value to be inserted : ";
        cin>>val;
        if(val<(root->data))
        {
            if(root->left==0)
            {
                temp1=new tree(val,0,0);
                root->left=temp1;
            }
            else
            {
                root=root->left;
                insert();
            }
        }
        else
        {
            if(root->right==0)
            {
                temp1=new tree(val,0,0);
                root->right=temp1;
            }
            else
            {
                root=root->right;
                insert();
            }
        }
    }
}
int main()
{
  tree *p=0,*q=0;
  int x;


  cout<<"value to be inserted :";
  cin>>x;
  root = new tree(x,0,0);
  cout<<root->data<<endl;
  temp=root;
  cout<<temp->data<<endl;
  insert();
//  print();
}
