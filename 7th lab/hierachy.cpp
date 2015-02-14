#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class shape{
	public:
		shape(){};
		double r,l,b,h,a,c;
		virtual double area()=0;
};
class twodimensional:public shape
{
	public:
		twodimensional(){};
		virtual double perimeter()=0;
};
class threedimensional:public shape
{
	public:
		threedimensional(){};
		virtual double volume()=0;
};
class triangle:public twodimensional
{
	public:
		double s;
		void setvalues(double a1,double b1,double c1)
		{
			a=a1;
			b=b1;
			c=c1;
		}
		double area()
		{
			s=(a+b+c)/2;
			return sqrt(s*(s-a)*(s-b)*(s-c));
		}
		double perimeter()
		{
			return a+b+c;
		}
};
class circle:public twodimensional
{
	public:
		void setvalues(double r1)
		{
			r=r1;
		}
		double area()
		{
			return 3.14*r*r;
		}
		double perimeter()
		{
			return 2*3.14*r;
		}
};
class rectangle:public twodimensional
{
	public:
		void setvalues(double l1,double b1)
		{
			l=l1;
			b=b1;
		}
		double area()
		{
			return l*b;
		}
		double perimeter()
		{
			return 2*(l+b);
		}
};
class box:public threedimensional
{
	public:
		void setvalues(double l1,double b1,double h1)
		{
			l=l1;
			b=b1;
			h=h1;
		}
		double area()
		{
			return 2*(l*b+b*h+l*h);
		}
		double volume()
		{
			return l*b*h;
		}
};
class cone:public threedimensional
{
	public:
		void setvalues(double l1,double b1)
		{
			r=l1;
			h=b1;
		}
		double volume()
		{
			return 0.33*3.14*r*r*h;
		}
		double area()
		{
			return 3.14*r*(sqrt(r*r+h*h)+r);
		}
};
class cyllinder:public threedimensional
{
	public:
		void setvalues(double l1,double b1)
		{
			r=l1;
			h=b1;
		}
		double area()
		{
			return 2*3.14*r*h;
		}
		double volume()
		{
			return 3.14*r*r*h;
		}
};
class sphere:public threedimensional
{
	public:
		void setvalues(double r1)
		{
			r=r1;
		}
		double area()
		{
			return 4*3.14*r*r;
		}
		double volume()
		{
			return 4/3*3.14*r*r*r;
		}
};


int main()
{
	double a1,b1,c1,l,b,r,h;
	int i=10;
	shape *p1,*p4;
	twodimensional *p2;
	threedimensional *p3;	
	triangle ob1;
	rectangle ob2;
	circle ob3;
	box ob4;
	cone ob5;
	cyllinder ob6;
	sphere ob7;
	int n;
	
while(1)
{	
	cout<<"press 1 for triangle"<<endl;
	cout<<"press 2 for rectangle"<<endl;
	cout<<"press 3 for circle"<<endl;
	cout<<"press 4 for box"<<endl;
	cout<<"press 5 for cone"<<endl;
	cout<<"press 6 for cyllinder"<<endl;
	cout<<"press 7 for sphere"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			p1=&ob1;
			p2=&ob1;
			cout<<"enter values of a,b and c: "<<endl;
			cin>>a1>>b1>>c1;
			ob1.setvalues(a1,b1,c1);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"perimeter is "<<p2->perimeter()<<endl;
			break;
		case 2:
			p1=&ob2;
			p2=&ob2;
			cout<<"enter values of l and b: "<<endl;
			cin>>l>>b;
			ob2.setvalues(l,b);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"perimeter is "<<p2->perimeter()<<endl;
			break;
		case 3:
			p1=&ob3;
			p2=&ob3;
			cout<<"enter values of r "<<endl;
			cin>>r;
			ob3.setvalues(r);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"perimeter is "<<p2->perimeter()<<endl;
			break;
		case 4:
			p1=&ob4;
			p3=&ob4;
			cout<<"enter values of l and b and h: "<<endl;
			cin>>l>>b>>h;
			ob4.setvalues(l,b,h);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"volume is "<<p3->volume()<<endl;
			break;
		case 5:
			p1=&ob5;
			p3=&ob5;
			cout<<"enter values of r and h: "<<endl;
			cin>>r>>h;
			ob5.setvalues(l,b);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"volume is "<<p3->volume()<<endl;
			break;
		case 6:
			p1=&ob6;
			p3=&ob6;
			cout<<"enter values of r and h: "<<endl;
			cin>>r>>h;
			ob6.setvalues(r,h);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"volume is "<<p3->volume()<<endl;
			break;
		case 7:
			p1=&ob7;
			p3=&ob7;
			cout<<"enter values of r: "<<endl;
			cin>>r;
			ob7.setvalues(r);
			cout<<"area is : "<<p1->area()<<endl;
			cout<<"volume is "<<p3->volume()<<endl;
			break;
	}
	cout<<"do you want to enter numbers : if yes press 1 if no press 0"<<endl;
	cin>>i;
	if(i==0)
	{
		return 0;
	}
}
return 0;
}
		
		
		
	
	
	
	


