#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class graph{
    map<T,list<T> >adjlist;
    public:
    graph(){

    }
    void addedge(T u,T v,bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }
    void bfs(T src){
        queue<T>q;
        map<T,int>dist;
        map<T,T>parent;
        for(auto i:adjlist){
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop(); 
            for(int neigbour:adjlist[node]){
                if(dist[neigbour]==INT_MAX) {
                    q.push(neigbour);
                    dist[neigbour]=dist[node] + 1;
                    parent[neigbour]=node;
                }
            }
        }
        for(auto i:adjlist){
            T node=i.first;
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }
};
int main(){
   graph<int>g;
   g.addedge(0,1);
   g.addedge(1,2);
   g.addedge(0,4);
   g.addedge(2,4);
   g.addedge(2,3);
   g.addedge(3,5);
   g.addedge(3,4);
   g.bfs(0);
}