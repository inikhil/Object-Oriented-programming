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
		node *head;
		int n, m;
		hashtable() : n(0), head(0) {};
		hashtable(int n_p, int m_p) : n(n_p), m(m_p) {head=new node[m];};
		int hash_insert(int k,int a);
		int hash_search(int k);
		int hf(int j,int k);
		int print();
};

int hashtable::hash_insert(int k,int a)
{
	int i=0,j;
	while(i!=m)
	{
		j=hf(k,i);
		if (head[j].k==0)
		{
			head[j].k=k;
			cout<<"No of collisions is equal to "<< i<<endl;
			cout<<"Average no of collisions : "<<(float)i/a<<endl;
			return j;
		}
		else
		{
			i=i+1;
		}
	}
	cout<<"Hash table overflow"<<endl;
}

int hashtable::hash_search(int k)
{
	int i=0,j;
	do{
	j=hf(k,i);
	if(head[j].k==k)
	{
		return j;
	}
	i=i+1;
	}while((head[j].k==0)||(i==m));
	return 0;
}

int hashtable::hf(int j,int k)
{
		int a,b;
		a=k%m;
		b=1+k%(m-1);
		return (a+j*b)%m;
}
int hashtable::print()
{
	int i;
	for(i=0;i<m;i++)
	{
		cout<<head[i].k<<" ";
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
	while(i!=4)
	{
		cout<<"Press 1 to insert : "<<endl;
		cout<<"press 2 to search : "<<endl;
		cout<<"press 3 to print : "<<endl;
		cout<<"press 4 to exit : "<<endl;
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
			









