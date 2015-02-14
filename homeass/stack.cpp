#include<iostream>
using namespace std;
class stck{
    public:
    stck(int x){m=x;t=-1;};
    int t;
    int push(int n,int *a);
    int pop(int *a);
    void print(int *a);
    int m;
};

int stck::push(int n,int *a){
    t++;
    if(t==m){
        cout<<"Stack overflow"<<endl;
        return 0;
    }
    a[t]=n;
}
int stck::pop(int *a){
    if(t==-1){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    cout<<a[t]<<endl;
    t--;
}
void stck::print(int *a)
{
    int i;
    for(i=0;i<=t;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int n,x,k=0;
    cout<<"Enter your size of array :"<<endl;
    cin>>x;
    stck ob(x);
    int* a=new int[x];
    while(k!=4){
        cout<<"Press 1 to push: "<<endl;
        cout<<"Press 2 to pop: "<<endl;
        cout<<"Press 3 to print: "<<endl;
        cout<<"Press 4 to exit: "<<endl;
        cin>>k;
        switch(k){
            case 1:
                cout<<"Enter your value to push: "<<endl;
                cin>>n;
                ob.push(n,a);
                break;
            case 2:
                ob.pop(a);
                break;
            case 3:
                ob.print(a);
                break;
            case 4:
                return 0;
                break;
        }
    }
}
