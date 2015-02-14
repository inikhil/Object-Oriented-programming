#include<iostream>
#include<vector>
using namespace std;
void postfix(string s)
{
    vector<char> s1;
    int t,i,j,m;
    for(i=0;i<s.size();i++){
        t=s[i];
        if((t==40)||((t>=42)&&(t<=47))){
            if(s1.size()==0)
                s1.push_back(s[i]);
            else{
                m=s1[s1.size()-1];
                if((t<m)&&(m!=47))
                    s1.push_back(s[i]);
                else{
                    if((t>m)&&(t==47))
                        s1.push_back(s[i]);
                    else{
                        if(m!=40){
                            cout<<s1[s1.size()-1];
                            s1.pop_back();
                            i=i-1;
                        }
                        else{
                            s1.push_back(s[i]);
                        }
                    }
                }
            }
        }
        else{
           if(t==41){
                m=41;
                for(j=s1.size()-1;(m!=40&&j>0);j--){
                    cout<<s1[j];
                    m=s1[j-1];
                    s1.pop_back();
                }
                s1.pop_back();
            }
            else{
                cout<<s[i];
                if(i==s.size()-1){
                    for(j=s1.size()-1;j>=0;j--){
                        cout<<s1[j];
                        s1.pop_back();
                    }
                }
            }
        }
    }

}
int main()
{
    string s;
    int t=0;
    while(t!=2){
         cout<<"Press 1 to enter your prefix expression: "<<endl;
         cout<<"Press 2 to exit: "<<endl;
         cin>>t;
         switch(t){
            case 1:
                cout<<"Enter your prefix expression: "<<endl;
                cin>>s;
                postfix(s);
                break;
            case 2:
                return 0;
         }
    }

}
