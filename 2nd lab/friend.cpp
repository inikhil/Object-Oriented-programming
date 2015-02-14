#include<iostream>
using namespace std;
class frin{
    private:
        int x;
    public:
        frin(){x=0;}

    friend void func(frin/*name of the class*/ &star/*object of teh class*/);//declaring friend of teh class which has access to all the variable sof the class

};

void func(frin &star){
    cin>>star.x;
    cout<<star.x<<endl;
}
int main(){
    frin star;
    func(star);

    return 0;


}
