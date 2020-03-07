#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int>adj[],int V){
    for(int v=0;v<V;v++){
        cout<<v;
        for(int i:adj[v]){
            cout<<"->"<<i;
        }
        cout<<endl;
    }
}
int main(){
    int V;
    cin>>V;
    vector<int>adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    print(adj,V);
}