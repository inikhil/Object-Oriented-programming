#include<iostream>
using namespace std;
class matrix
{
	public:
		int a[2][2];
		matrix() {};
		matrix operator* (matrix);
		void read();
		void print();
		
};
matrix matrix::operator* (matrix a2)
{
	matrix a3;
	int i,j=0,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			a3.a[i][j]=0;
		}
	}
	j=0;
	for (i=0;i<2;i++)
	{
		for(k=0;k<2;k++)
		{
			a3.a[i][k]=((a[i][j])*(a2.a[j][k])+(a[i][j+1])*(a2.a[j+1][k]));
		}
	}
	
	return a3;
	
}	
void matrix::read()
{
	int i,j;
	cout<<"Input your matrix:"<<endl;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>a[i][j];
		}
	}
	
}
void matrix::print()
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	
	int n;
	matrix a1,a2,a3;
	a1.read();
	a2.read();
	a3=a1*a2;
	cout<<"your output matrix is:"<<endl;
	a3.print();
	return 0;
}