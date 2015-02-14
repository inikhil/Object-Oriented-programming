#include<iostream>
#include<cstdlib>
using namespace std;
class matrix
{
	public:
		
		int a[100][100];
		//matrix()
		matrix(int c);
		int size;
		matrix operator* (matrix);
		void read();
		void print();
		
};
matrix::matrix(int a )
		{
			size=a;
		}
matrix matrix::operator* (matrix a2)
{
	matrix a3(size);
	int i,j=0,k;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
				a3.a[i][j]=0;
		}
	}
	j=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			for(k=0;k<size;k++)
			{
				a3.a[i][j] += (a[i][k])*(a2.a[k][j]);
			}
		}
	}
	
	return a3;
	
}
	
	
	
	
void matrix::read()
{
	int i,j,k;
	
	cout<<"Input your matrix:"<<endl;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
				cin>>a[i][j];
		}
	}
	
}
void matrix::print()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	
	int n,b;
	cout<<"input your dimension:";
	cin>>b;
	matrix a1(b),a2(b),a3(b);
	a1.read();
	a2.read();
	a3=a1*a2;
	cout<<"your output matrix is:"<<endl;
	a3.print();
	return 0;
}