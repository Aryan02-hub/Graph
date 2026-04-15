// it is aloso known as Kahn's Algorithm

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

    void bfs_topo(){
        vector<int> ans;
        //step- 1: find indegree of all the nodes
        vector<int>indeg(V,0);
        for(int i=0; i<V; i++){
            for(int v:l[i]){
                indeg[v]++;
            }
        }

        //step-2: find all the nodes with indegree 0
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        //step-3: bfs
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);

            for(int u:l[curr]){
                indeg[u]--;
                if(indeg[u]==0){
                    q.push(u);
                }
            }
        }
        //print ans
        for(int i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Graph g(6);
    g.addEdges(5, 0);
    g.addEdges(4, 0);
    g.addEdges(5, 2);
    g.addEdges(2, 3);
    g.addEdges(1, 3);
    g.addEdges(4, 1);
    g.bfs_topo();
    return 0;
}
