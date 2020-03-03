#include<bits/stdc++.h>
using namespace std;
//max heap
void upheapify(vector<int>&heap,int idx){
    if(idx==0){
        return;
    }
    int parentidx=(idx-1)/2;// reterive the parent index
    if(heap[parentidx]<heap[idx]){// check for the condition
        //swap
        int temp=heap[parentidx];
        heap[parentidx]=heap[idx];
        heap[idx]=temp;
        upheapify(heap,parentidx);
    }
    else{
        return;
    }
}
void downhepify(vector<int>&heap,int idx){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;
    if(leftidx>=heap.size() and rightidx>=heap.size()){
        return;// for leaf nodes
    }  
    //checking the value of root ,left and right  and highest value is
    //put in the idx  and swap it  
    int largestidx=idx;
    if(leftidx<heap.size() and heap[leftidx]>=heap[largestidx]){
        largestidx=leftidx;
    }
    if(rightidx<heap.size() and heap[rightidx]> heap[largestidx]){
        largestidx=rightidx;
    }
    if(largestidx==idx) return;
    swap(heap[idx],heap[largestidx]);
    downhepify(heap,largestidx);
}
void deletepeek(vector<int>&heap){
    swap(heap[0],heap[heap.size()-1]);//first swap first and last element 
    heap.pop_back();// pop back last element
    downhepify(heap,0);//now complete the binary tree
}
void insert(vector<int>&heap,int key){
    heap.push_back(key);
    upheapify(heap,heap.size()-1);
}
void buildheap(vector<int>&heap){
    for(int i=0;i<heap.size();i++){
        upheapify(heap,i);
    }
}
void buildheapOptimised(vector<int>&heap){
    for(int i=heap.size()-1;i>=0;i--){
        downhepify(heap,i);
    }
}
void display(vector<int>&heap){
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heap.push_back(x);
    }
    //buildheap(heap);
    buildheapOptimised(heap);
    display(heap);
    return 0;
}