#include<ctime>
#include<cstdlib>
#include<iostream>

using namespace std;

enum colour {white=0, grey=1, black=2};

class Vertex {
    public:
        int index;
        colour col;
        Vertex() : index(0), col(white) {};
};

struct AdjList {
    int index;
    AdjList* next;
};

struct G {
    AdjList** adj;
    Vertex* v;
    int N;
};

void printAdjList(int** mat, int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << i << ": ";
        for(int j = 0 ; j < n ; j++) {
            if(mat[i][j])
                cout << j << "->";
        }
        cout << endl;
    }
}

void printAdjListGraph(G graph) {
    for(int i = 0 ; i < graph.N ; i++) {
        cout << i << ": ";
        AdjList* tmp = graph.adj[i];
        while(tmp) {
            cout << tmp->index << "->";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

G createGraph(int** mat, int n) {
    Vertex* v1 = new Vertex[n];
    AdjList** adj1 = new AdjList*[n];
    for(int i = 0 ; i < n ; i++)
        v1[i].index = i;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(mat[i][j]) {
                if(!adj1[i]) {
                    adj1[i] = new AdjList();
                    adj1[i]->index = j;
                    adj1[i]->next = 0;
                }
                else {
                    AdjList* w = new AdjList();
                    w->index = j;
                    w->next = adj1[i];
                    adj1[i] = w;
                }
            }
        }
    }
    G ret;
    ret.adj = adj1;
    ret.v = v1;
    ret.N = n;
    return ret;
}

void recolour(G& graph) {
    for(int i = 0 ; i < graph.N ; i++) {
        graph.v[i].col = white;
    }
}

void dfsVisit(G graph, int u, int& conn) {
    graph.v[u].col = grey;
    AdjList* tmp = graph.adj[u];
    while(tmp) {
        if(graph.v[tmp->index].col == white)
            dfsVisit(graph, tmp->index, ++conn);
        tmp = tmp->next;
    }
    graph.v[u].col = black;
}

bool dfs(G graph) {
    int count1 = 0;
    for(int i = 0 ; i < graph.N ; i++) {
        recolour(graph);
        dfsVisit(graph, i, count1);
        if(count1 != (graph.N - 1))
            return false;
        count1 = 0;
    }
    return true;
}

int main() {
    int n;
    bool comp;
    G graph;
    cout << "Enter number of vertices:- ";
    cin >> n;
    srand((unsigned int)time(0));
    int** adj_list = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        adj_list[i] = new int[n];
    }
    do {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                double u = (double)rand() / RAND_MAX;
                if((u <= 0.5) || (i == j))
                    adj_list[i][j] = 0;
                else
                    adj_list[i][j] = 1;
            }
        }
        graph = createGraph(adj_list, n);
        comp = dfs(graph);
        if(comp)
            break;
    }while(!comp);

    cout << "FINAL ADJACENCY LIST:- " << endl << endl;
    printAdjListGraph(graph);
    return 0;
}