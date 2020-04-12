#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    vector<int> v;
    vector<int>min;
    public:
    void push(int data){
        v.push_back(data);
        if(min.empty()||min.back()>=data){
            min.push_back(data);
        }
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(v.back()==min.back()){
            min.pop_back();
        }
        v.pop_back();
    }
    int top(){
        return v[v.size()-1];
    }
    int mini(){
        if(!min.empty()){
            return min.back();
        }
        return -1;
    }
};
int main(){
    Stack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    cout<<s.top();
    return 0;   
}