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
    }

    bool isCycledecDirDFS(int curr, vector<bool> &vis, vector<bool> & recPath){
        vis[curr]=true;
        recPath[curr]=true;
        for(int v:l[curr]){
            if(!vis[v]){
                if(isCycledecDirDFS(v, vis, recPath)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }
        recPath[curr]=false;
        return false;
    }

    void isCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycledecDirDFS(i, vis, recPath)){
                    cout<<"Cycle is present in the graph"<<endl;
                    return;
                }
            }
        }
        cout<<"Cycle is not present in the graph"<<endl;    
    }
};

int main(){
    Graph g(5);
    g.addEdges(1, 0);
    g.addEdges(0, 2);
    g.addEdges(2, 3);
    g.addEdges(3, 0);
    g.isCycle();
    return 0;
}
