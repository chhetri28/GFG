#include<bits/stdc++.h>
using namespace std;
void addedge(list<int>l[],int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}
void print(list<int>l[],int Ver){
    for(int v=0;v<Ver;v++){
        cout<<v;
        for(int i:l[v]){
            cout<<"->"<<i;
        }
        cout<<endl;
    }
}

int main(){
    int Ver;
    cin>>Ver;
    list<int>l[Ver];
    for(int i=0;i<Ver;i++){
    int x,y;
    cin>>x>>y;
    addedge(l,x,y);
    }
    print(l,Ver);
}