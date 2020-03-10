#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<T,list<T> > ajdlist;
    public:
    graph(){

    }
    void addedge(T u,T v,bool bidir=true){
        ajdlist[u].push_back(v);
        if(bidir){
            ajdlist[v].push_back(u);
        }
    }
    bool iscyclicbfs(T src){
        map<T, bool>visited;
        map<T, int>parent;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(T neighbour:ajdlist[node]){
                if(visited[neighbour]==true and parent[node]!=neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};
int main(){
    graph<int> g;
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(4,3);
    g.addedge(2,3);
    if(g.iscyclicbfs(1)){
        cout<<"Cyclic";
    }
    else{
        cout<<"NO";
    }
    return 0;
}