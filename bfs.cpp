#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        this->V=v;
        l=new list<int>[v];
    }

    void addEdges(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){
        queue<int>Q;
        vector<bool>vis(V, false);

        Q.push(0);
        vis[0]=true;

        while(Q.size()>0){
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";
            for(int v : l[u]){
                if(!vis[v]){
                    Q.push(v);
                    vis[v]=true;
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(2, 3);
    g.addEdges(2, 4);
    g.bfs();
    return 0;
}
