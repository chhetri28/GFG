#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);   
}
int fast_power(int a,int b){
    if(b==0){
        return 1;
    }
    int small_ans=fast_power(a,b/2);
    small_ans*=small_ans;
    if(b&1){
        return small_ans*a;
    }
    return small_ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<fast_power(a,b);
}