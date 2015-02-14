#include<iostream>

using namespace std;
class rectangle{
		double x,y,w,h,x1,y1,w1,h1;
	public:
		rectangle(double,double,double,double);
		void get_input();
		void report();
		
};
		
rectangle::rectangle(double a,double b,double c,double d)
{
	x=a; y=b; w=c,h=d;
}
void rectangle::get_input()
{
	cout<<"your inputs are:"<<endl;
	cin>>x1>>y1>>w1>>h1;
}
void rectangle::report()
{
if((x1-x>0)&&(y1-y>0))
{
	if((x1-x+w1<w) && (y1-y+h1<h))
	{
		cout<<"rectangle lies completely inside"<<endl;
	}
	else
	{
		cout<<"your rectangle lies outside"<<endl;
	}
}
else
{
	cout<<"rectangle lies outside"<<endl;
} 	
}	
int main()
{
	
	double a=2,b=3,c=4,d=5;
	cout<<"original values of given rectangle is 2,3,4,5"<<endl;
	rectangle given(a,b,c,d);
	given.get_input();
	given.report();
	return 0;
}