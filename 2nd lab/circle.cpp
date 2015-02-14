#include<iostream>

using namespace std;
class circle{
		int xcor,ycor,radius,x1cord,y1cord,radius1;
	public:
		circle(int,int,int);
		void get_input();
		void report();
		
};
		
circle::circle(int a,int b,int c)
{
	xcor=a; ycor=b; radius=c;
}
void circle::get_input()
{
	cout<<"your inputs are:"<<endl;
	cin>>x1cord>>y1cord>>radius1;
}
void circle::report()
{
if(radius-radius1>=0)
{
	if((xcor-x1cord)*(xcor-x1cord)+(ycor-y1cord)*(ycor-y1cord)-(radius-radius1)*(radius-radius1)<0)
	{
		cout<<"circle lies completely inside"<<endl;
	}
	else
	{
		cout<<"your circle lies outside"<<endl;
	}
}
else
{
	cout<<"circle lies outside"<<endl;
} 	
}	
int main()
{
	
	double a=2,b=3,c=4;
	cout<<"original values of the given circle is 2,3,4"<<endl;
	circle given(a,b,c);	
	given.get_input();
	given.report();
	return 0;
}