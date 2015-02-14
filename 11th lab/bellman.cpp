#include<iostream>
#include<cstdlib>
using namespace std;
int n;
int **a;
int c;
class node{
	public:
	node(int key,int as,string col,node *p=0,int di){
		weight=key;
		next=p;
		index=as;
		colo="white";
		dist=di;
	}
	int weight;
	node *next;
	int index;
	string colo;
	int dist;
};
node **start;
int relax(int i,int j,int w){
    if((start[j]->dist)>(start[i]->dist+w)){
        (start[j]->dist)=start[i]->dist+w;
    }
}
bool bellman(node **temp){
    int i,j;
    node *r;
    start[0]->dist=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            r=temp[j];
            while(r!=0){
                relax(j,r->index,r->weight);
                r=r->next;
            }
        }
    }
    for(j=0;j<n;j++){
        r=temp[j];
        while(r!=0){
            if(start[r->index]->dist>(start[j]->dist+r->weight)){
                return false;
            }
            r=r->next;
        }
    }
    for(i=0;i<n;i++){
        cout<<start[i]->dist<<" ";
    }
    return true;
}
void createnode(node **temp){
	int i,j,m=0,y;
	node *r,*q,*start;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1){
				if(m==0){
                    y=rand()%9;
                    if(y<3){
                        y=(-1)*y;
                    }
					temp[i]=new node(y,j,"white",0,100000);
					r=temp[i];
					m=1;
				}
				else{
				    y=rand()%9;
                    if(y<5){
                        y=(-1)*y;
                    }
					q=new node(y,j,"white",0,100000);
					r->next=q;
					r=q;
				}
			}
		}
		m=0;
	}
}

void printlist(node **temp){
    int i,j;
    node *r;
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
    for(i=0;i<n;i++){
		r=temp[i];
		while(r!=0){
			cout<<r->weight<<" , "<<r->index<<"-->"<<" ";
			r=r->next;
		}
		cout<<"\n";
	}
}

node** buildnewnode(){
	int i;
	start=new node*[n];
	for(i=0;i<n;i++){
		start[i]=new node(0,i,"white",0,1000);
	}
}

void randomnum(){
	int i,j;
	double t;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
            if(i==j){
                a[i][j]=0;
            }
            else{
                t=(double)rand()/RAND_MAX;
                if(t<0.5){
                    a[i][j]=0;
                }
                else
                {
                    a[i][j]=1;
                }
            }
		}
	}
}
void dfsvisit(node **temp,int i){
	int j;
	node *r;
	r=temp[i];
	if(r==0){
        return;
	}
	start[i]->colo="black";
	while(r!=0){
		j=r->index;
		if(start[j]->colo=="white"){
			dfsvisit(temp,j);
		}
		r=r->next;
	}
}
int dfs(node **temp){
	int m,i;
	for(i=0;i<n;i++){
        buildnewnode();
		//start[i]->colo="black";
		c=0;
        dfsvisit(temp,i);
		for(i=0;i<n;i++){
			if(start[i]->colo!="black"){
				c=1;
				if(c==1){
                    return c;
				}
			}
		}
	}
	return c;
}
int main(){
	int i,j,t=1;
	node **temp;
	cout<<"Enter your value of n ";
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++){
		a[i]=new int[n];
	}
	srand(time(NULL));
	while(t!=0){
        temp=new node*[n];
        for(i=0;i<n;i++){
            temp[i]=0;
        }
		randomnum();
		createnode(temp);
        printlist(temp);
		t=dfs(temp);
		cout<<"\n";
	}
	if(bellman(temp)==false){
        cout<<"Negative cycle is present";
	}
	return 0;
	/*node1 **grap;

	grap=new node1*[n];
    for(i=0;i<n;i++){
        grap[i]=0;
    }
    creategraph(temp,grap);
	//printlist(temp);*/
}

