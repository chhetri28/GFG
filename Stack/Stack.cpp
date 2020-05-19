#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack{
    private:
    vector<T> v;
    vector<T>min;
    public:
    void push(T data){
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
    T top(){
        return v[v.size()-1];
    }
    T mini(){
        if(!min.empty()){
            return min.back();
        }
        return -1;
    }
};
int main(){
    Stack<int> s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    cout<<s.top();
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    return 0;   
}