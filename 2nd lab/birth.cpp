#include<iostream>
#include<string>
using namespace std;

class birthday{
    private:
        int day,month,year;
    public:
        birthday(int ,int ,int );
        void printbirth();
};
class people{
    private:
        char name;
        birthday dob;
    public:
        people(string x,birthday bth);
        void printname();
};
birthday::birthday(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}
people::people(char x,birthday bth):name(x),dob(bth)
{
}
void people::printname()
{
    cout<<name<<"birthday is on "<< dob.printbirth()<<endl;

}
void birthday::printbirth()
{
    cout<<day<<"/"<<month<<"/"<<year<<endl;

}
int main()
{
    int d,m,y;
    char x;
    cin>>d>>m>>y;
    cin>>x;
    birthday bth(d,m,y);
    bth.printbirth();
    people bth1(x,birthday);
    bth1.printname();
    return 0;

}
