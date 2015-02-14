#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int i;
    string s[3];
    for(i=0;i<3;i++)
    {
        getline(cin,s[i]);
    }
    for(i=0;i<3;i++)
    {
        cout<<s[i]<<endl;
    }
}
