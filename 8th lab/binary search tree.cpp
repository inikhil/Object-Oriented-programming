#include<iostream>
using namespace std;
class node
{
	public:
		node(int d,node *a=0,node *b=0,node *c=0)
		{
			key=d;
			left=a;
			right=b;
			p=c;
		}
		int key;
		node *left;
		node *right;
		node *p;
};
class tree
{

	public:
		node *root;
		tree(){root=0;}
		void insert(node* z);
		node* successor(int d);
		node* predecessor(int d);
		void delet(int d);
		node* minimum(node* x);
		node* maximum(node* x);
		void transplant(node* u, node* v);
		node* search(int k);
		void inorder(node* x);
};
//node *q=0,*root=0;
node* tree::search(int k)
{
	node* x=root;
	while((x!=0)&&(k!=x->key))
	{
		if(k<x->key)
		{
			x=x->left;
		}
		else
		{
			x=x->right;
		}
	}
	return x;
}
node* tree::minimum(node* x)
{
	while(x->left!=0)
	{
		x=x->left;
	}
	return x;
}
node* tree::maximum(node* x)
{
	while(x->right!=0)
	{
		x=x->right;
	}
	return x;
}
void tree::insert(node* z)
{
	node *y,*x;
	y=0;
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
node* tree::successor(int d)
{
	node* x=search(d);
	node *y;
	if(x==0)
		return 0;
	if(x->right!=0)
	{
		return minimum(x->right);
	}
	y=x->p;
	while((y!=0) &&(x=y->right))
	{
		x=y;
		y=y->p;
	}
	return y;
}
node* tree::predecessor(int d)
{
	node* x=search(d);
	node* y;
	if(x==0)
		return 0;
	if(x->left!=0)
	{
		return maximum(x->left);
	}
	y=x->p;
	while((y!=0) &&(x=y->left))
	{
		x=y;
		y=y->p;
	}
	return y;
}
void tree::transplant(node* u,node* v)
{
	if(u->p==0)
	{
		root=v;
	}
	else if(u==u->p->left)
	{
		u->p->left=v;
	}
	else
	{
		u->p->right=v;
	}
	if(v!=0)
	{
		v->p=u->p;
	}
}
void tree::delet(int d)
{
	node* z=search(d);
	node *y;
	if(z==0)
		return;
	if(z->left==0)
	{
		transplant(z,z->right);
	}
	else if(z->right==0)
	{
		transplant(z,z->left);
	}
	else
	{
		y=minimum(z->right);
		if(y->p!=z)
		{
			transplant(y,y->right);
			y->right=z->right;
			y->right->p=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->p=y;
	}
}
void tree::inorder(node* x)
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
	node *temp;
	tree bin;
	int n,m=0,*start;
	int e;
	while(m != 6)
	{
		cout<<"Enter 1 to insert: "<<endl;
		cout<<"Enter 2 for predecessor: " <<endl;
		cout<<"Enter 3 for successor: "<<endl;
		cout<<"Enter 4 for delete "<<endl;
		cout<<"Enter 5 for inorder output: "<<endl;
		cout<<"Enter 6 to exit: "<<endl;
		cin>>m;
		switch(m){
		  	case 1:
		  		cin>>e;
		  		temp=new node(e);
		  		bin.insert(temp);
		  		break;
		  	case 2:
		  		cin>>e;
		  		temp=bin.predecessor(e);
		  		if(temp!=0)
		  			cout<<temp->key<<endl;
		  		break;
		  	case 3:
		  		cin>>e;
		  		temp=bin.successor(e);
		  		if(temp!=0)
		  			cout<<temp->key<<endl;
		  		break;
		  	case 4:
		  		cin>>e;
		  		bin.delet(e);
		  		break;
		  	case 5:
		  		bin.inorder(bin.root);
		  		break;
		}
	}
	return 0;
}
