#include<iostream>
using namespace std;
class node{
	public:
		node(): k(0), p(0){};
		node(int key,node *q)
		{
			k=key;
			p=q;
		}
		int k;
		node *p;
};
class hashtable{
	public:
		node **head;
		int n, m;
		hashtable() : n(0), head(0) {};
		hashtable(int n_p, int m_p) : n(n_p), m(m_p) {head=new node*[m];};
		int hash_insert(int k,int a);
		node* hash_search(int k);
		int hf(int j);
		int print();
		
};

int hashtable::hash_insert(int k,int a)
{
	int i=0,j;
	node *u,*d=0,*q=0, *v;
	v=hash_search(k);
	if(v!=0)
	{
		cout<<"Element already present "<<endl;
	}
	else
	{
		j=hf(k);
		node* ins = head[j];
		if(ins == 0) {
			u=new node(k,0);
			head[j] = u;
			return 0;
		}
		else {
			while(ins!=0)
			{
				ins=ins->p;
				i++;
				cout<<"No of comparisions is equal to "<< i<<endl;
				cout<<"Average no of comparisions : "<<(float)i/a<<endl;
			}
			u=new node(k,0);
			u->p = head[j];
			head[j] = u;
			return 0;
		}
	}
}
node* hashtable::hash_search(int k)
{
	int i=0,j;
	j=hf(k);
	node* ins = head[j];
	while(ins) {
		if(ins->k==k)
		{
			return ins;
		}
		ins = ins->p;
	}
	return 0;
}

int hashtable::hf(int k)
{
	return k%m;
}
int hashtable::print()
{
	int i;
	for(i=0;i<m;i++)
	{
		node* tmp = head[i];
		while(tmp) {
			cout<<tmp->k<<"->";
			tmp = tmp->p;	
		}
		cout << endl;
	}
	cout<<"\n";
}

int main()
{
	int i=0,n,t,m=0,a=1;
	cout<<"Input yout size of n : ";
	cin>>n;
	for(m=1;m<=n;m++)
	{
		m=2*m;
	}
	//cout << m << endl;
	hashtable ob(n,m);
	while(i<n)
	{
		cout<<"Enter your value to insert : ";
		cin>>t;
		ob.hash_insert(t,a);
		i++;
		a++;
	}
	i=0;
	while(i!=5)
	{
		cout<<"Press 1 to insert : "<<endl;
		cout<<"press 2 to search : "<<endl;
		cout<<"press 3 to print : "<<endl;
		cout<<"press 4 to exit : "<<endl;
		cout<<"press 5 to delete : "<<endl;
		cin>>i;
		switch(i){
			case 1:
				cout<<"Enter your value to insert : ";
				cin>>t;
				ob.hash_insert(t,a);
				a++;
				break;
			case 2:
				cout<<"Enter your value to search : ";
				cin>>t;
				ob.hash_search(t);
				break;
			case 3:
				ob.print();
				break;
		}
	}
	return 0;
}
			









