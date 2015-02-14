
#include<iostream>
using namespace std;
int main()
{
    int i;
    //unsigned int seed;
    //cin>>seed;
    srand((unsigned int) time(0));
    for(i=0;i<10;i++)
    {
        cout<<rand()<<endl;

    }
}
