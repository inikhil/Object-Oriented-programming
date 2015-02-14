#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
	public:
		node(int d,int m,float o,node *p=0,node *head=0,node *head1=0):data(d),id(m),tim(o),next(p),n1(head),n2(head1){}
		int id;
		float tim;
		int data;
		node *next;
		node *n1;
		node *n2;
};
node *remove_start(node *st) {
    node *tmp = st;
    if((st->next) == 0) {
        delete st;
        return 0;
    }
    st = st->next;
    delete tmp;
    return st;
}
node *exec_job(node *st, float t, int &n) {
    if(st->tim <= t) {
        cout << "job " << st->id << " completed.\n";
        node *tmp = remove_start(st);
        n--;
        return tmp;
    }
    else {
        st->tim = st->tim - t;
        node *tmp = st, *ret;
        cout << "job " << st->id << " partially completed.\n";
        if(n != 1)
            ret = st->next;
        else
            return ret;
        while(st) {
            st = st->next;
            if((st->next) == 0)
                break;
        }
        st->next = tmp;
        tmp->next = 0;
        return ret;
    }
}

int main()
{
	int n,i=0,a,t,g,f;
	float b,e, time_ser;
	node *r=0;
	node *head;
	node *head1;
	node *head2;
	cout<<"input your value of n, time_ser : ";
	cin>>n>>time_ser;
	node *p, *s;
	node *q=0;
	node *head3;
	srand((unsigned int)time(0));

	while(i<n)
	{

		a=rand()%9+1;
		b=(float)(rand()%9+1)/10;
		p=new node(a,i,b,q);
		if(i==0)
		{
			head=p;
		}
		if(i==1)
		{
			head1=p;
		}
		q=p;
		i++;
	}
	node *tmp = p;
	node *tmp1 = p;
	node *tmp2 = p;
	for(;tmp;tmp=tmp->next)
	{
		cout<<tmp->data<<endl;
	}
	cout<<"new line :"<<endl;
	while(p!=0)
	{
		s=p->next;
		while(s!=0)
		{
			if((p->tim)>(s->tim))
			{
				e=p->tim;
				//cout<<e<<endl;
				p->tim=s->tim;
				s->tim=e;
				f=p->data;
				p->data=s->data;
				s->data=f;
				g=p->id;
				p->id=s->id;
				s->id=g;
				s=s->next;
			}
			else
				s=s->next;
		}
		p=p->next;
	}

	for(;tmp1;tmp1=tmp1->next)
	{
		cout<<tmp1->tim<<endl;
	}
	while(tmp2) {
		tmp2 = exec_job(tmp2, time_ser, n);
	}
return 0;
}

