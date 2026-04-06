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

    bool isCycledetectionDFS(int src, int par, vector<bool>&vis){
        vis[src]=true;
        list<int>neigh=l[src];

        for(int v:neigh){
            if(!vis[v]){
                if(isCycledetectionDFS(v, src, vis)){
                    return true;
                }
            }
            else if(v!=par){
                return true;
            }
        }
        return false;
    }

    bool dfs(){
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycledetectionDFS(i, -1, vis)){
                    return true;;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(0, 2);
    g.addEdges(0, 3);
    g.addEdges(3, 4);
    //g.printEdges();
    if(g.dfs()){
        cout<<"Cycle is present in the graph"<<endl;
    }
    else{
        cout<<"Cycle is not present in the graph"<<endl;    
    }
    return 0;
}
