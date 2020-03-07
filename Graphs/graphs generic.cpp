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
    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(auto entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph<string> g;
    g.addedge("Putin","trump",false);
    g.addedge("Putin","Modi",false);
    g.addedge("Putin","Pope",false);
    g.addedge("Modi","trump",true);
    g.addedge("Modi","yogi",true);
    g.addedge("yogi","prabhu",false);
    g.addedge("Prabhu","modi",false);
    g.print();
    graph<int>g2;
    g2.addedge(1,2);
    g2.addedge(100,2);
    g2.addedge(100,3);
    g2.print();   
}