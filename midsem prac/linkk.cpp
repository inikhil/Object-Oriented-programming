#include<iostream>
#include<cstring>
using namespace std;

class master
{
	public:
		string name,dob,doj;
		master(){};


};

class account:public virtual master
{
	public:
		int pay;
		account(){};
};

class admin:public virtual master
{
	public:
		int experience;
		admin(){};

};

class person:public account,public admin
{
	public:
		person(){};
		person(string a,string b,string c,int d,int e,person*p=0)
		{
			name=a;
			dob=b;
			doj=c;
			pay=d;
			experience=e;
			next=p;
		}
		person *next;
		void create();
		void  print();
		void  update();
};
person *p;
person *q=0;
person *start=0,*temp=0;
string a,b,c,f;
int d,e,i=0,m;
void person::create()
{
    while(i!=m)
		{
			cout<<"Enter name : ";
			cin>>a;
			cout<<"Enter date of birth : ";
			cin>>b;
			cout<<"Enter date of joining : ";
			cin>>c;
			cout<<"Enter payment : ";
			cin>>d;
			cout<<"Enter experience : ";
			cin>>e;

			p=new person(a,b,c,d,e,q);
			q=p;
			if(i==(m-1))
			{
				start=p;
				temp=p;
			}
			i=i+1;
		}
}
void person::print()
{

    for(;temp!=0;temp=temp->next)
		{
			cout<< "The person name is : "<<temp->name<<endl;
			cout<< "The person date of birth is : "<<temp->dob<<endl;
			cout<< "The person date of joining is : "<<temp->doj<<endl;
			cout<< "The person payment is : "<<temp->pay<<endl;
			cout<< "The person experience is : "<<temp->experience<<endl;
        }
}
void person::update()
{
    cout<<"Enter name of person whose data is to update:";
		cin>>f;
		while(start!=0)
		{
			if(start->name==f)
			{
				cout<<"Enter payment : ";
				cin>>start->pay;
				cout<<"Enter experience : ";
				cin>>start->experience;
			}
			start=start->next;
		}
		start=temp;

}

int main()
{
	int n;
	person od;
	cout<<"You want to store data for how many persons:  ";
	cin>>m;
	lab:cout<<"Enter your choice 1 to create,2 to update , 3 to display  "<<endl;
	cin>>n;
	if(n==1)
	{
		od.create();
		goto lab;
	}

	if(n==2)
	{
		od.update();
		goto lab;

	}
	if(n==3)
	{
        od.print();
	}
    return 0;
}
