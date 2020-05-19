#include<iostream>
#include<map>
#include<list>
#include<queue>
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
    void dfshelp(T node,map<T,bool>&visited){
  //whenever to come to a node,mark it visited
        visited[node]=true;
        cout<<node<<endl;
   //try to find out a node which is not visited and is 
   //neighbour
        for(T neighbour:adjlist[node]){
            if(!visited[neighbour]){
                dfshelp(neighbour,visited);
            }
        }           
    }
    void dfs(T src){
        map<T,bool>visited;
        dfshelp(src,visited);
    }
};
int main(){
    int v;
    cin>>v;
   graph<string>g;
   for(int i=0;i<v;i++){
       string x,y;
        cin>>x>>y;
        g.addedge(x,y);
   }
   string st;
   cin>>st;
   g.dfs(st);
//    g.addedge("Banglore","Hyderabad");
//    g.addedge("Banglore","Chennai");
//    g.addedge("Hyderabad","Mumbai");
//    g.addedge("Hyderabad","Delhi");
//    g.addedge("Chennai","Kerala");  
}