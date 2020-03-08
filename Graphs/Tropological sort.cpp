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
    void dfshelper(T node,map<T,bool>&visited,list<T>&ordering){
        visited[node]=true;
        for(T neighbours:adjlist[node]){
            if(!visited[neighbours]){
                dfshelper(neighbours,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfstopological(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:adjlist){
            T node=i.first;
            if(!visited[node]){
                dfshelper(node,visited,ordering);
            }
        }
        for(T element:ordering){
            cout<<element<<"-->";
        }
    }
};
int main(){
   graph<string>g;
   g.addedge("English","Programming",false);
   g.addedge("Maths","Programming",false);
   g.addedge("Programming","HTML",false);
   g.addedge("Programming","Python",false);
   g.addedge("Programming","Java",false);
   g.addedge("Programming","Js",false);
   g.addedge("Python","Web dev",false);
   g.addedge("HTML","CSS",false);
   g.addedge("CSS","JS",false);
   g.addedge("JS","Web dev",false);
   g.addedge("Java","Web dev",false);
   g.addedge("Python","Web dev",false);
   g.dfstopological();
}