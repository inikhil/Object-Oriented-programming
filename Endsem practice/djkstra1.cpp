#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class node{
    public:
        node(int i,int d,node *p=0,node *q=0){
            index=i;
            dist=d;
            next=p;
            prev=q;
        }
        int index;
        int dist;
        node *next;
        node *prev;
};
node **start,*start1;
int cunt=5;
vector<int> sty;
void printlist(){
    node* p;
    int i;
    for(p=start1;p!=0;p=(p->next)){
        cout<<p->index<<" ";
    }
    cout<<"\n";
    for(i=0;i<5;i++){
        cout<<start[i]->dist<<" ";
    }
    cout<<"\n";
     for(i=0;i<sty.size();i++){
        cout<<sty[i]<<" ";
    }
}
int b[5][5],a[5][5];
void buildnode(){
    int i;
    node *p,*q;
    start1=new node(0,0,0);
    p=start1;
    for(i=0;i<5;i++){
        start[i]=new node(i,10000,0,0);
    }
    for(i=0;i<4;i++){
        q=new node(i+1,10000,0,0);
        p->next=q;
        p=q;
    }
    start[0]->dist=0;
    //printlist();
}
node* extractmin(){
    int i,t=10000;
    node *p,*q,*r=0,*s;
    for(p=start1;p!=0;p=(p->next)){
        if(p->dist<t){
            t=p->dist;
            q=p;
            s=r;
            r=p;
        }
        else{
            r=p;
        }
    }
    if(s!=0){
        s->next=q->next;
    }
    else{
        start1=q->next;
    }
    //printlist();
    return q;
}
void relax(int i,int j){
    node *p;
    if(start[j]->dist>start[i]->dist+b[i][j]){
        start[j]->dist=start[i]->dist+b[i][j];
    }
    //printlist();
    //cout<<"\n";
}
void buildstart1(){
    node *p;
    int i;
    for(p=start1;p!=0;p=(p->next)){
        for(i=0;i<5;i++){
            if(p->index==start[i]->index){
                p->dist=start[i]->dist;
            }
        }
    }
}
void dijskstra(){
    node *u;
    int i,j;
    while(start1!=0){
        u=extractmin();
        i=u->index;
        sty.push_back(i);
        for(j=0;j<5;j++){
            if(a[i][j]!=0){
                relax(i,j);
            }
        }
        buildstart1();
        cunt--;
    }
    printlist();
}
int main(){
    ifstream myfile,myfile1;
    int i,j;
    node *start1;
    myfile.open("dijkstra.txt");
    myfile1.open("weights.txt");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            myfile>>a[i][j];
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            b[i][j]=0;
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(a[i][j]!=0){
                myfile1>>b[i][j];
            }
        }
    }
    start=new node*[5];
    for(i=0;i<5;i++){
        start[i]=0;
    }
    buildnode();
    dijskstra();

}

