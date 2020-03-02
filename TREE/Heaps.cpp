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
        return;
    }
    int largestidx=idx;
    if(leftidx<heap.size() and heap[leftidx]>=heap[largestidx]){
        largestidx=leftidx;
    }
    if(rightidx<heap.size() and heap[rightidx]> heap[largestidx]){
        largestidx=rightidx;
    }
    if(largestidx==idx) return ;
    swap(heap[idx],heap[largestidx]);
    downhepify(heap,largestidx);
}
void deletepeek(vector<int>&heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downhepify(heap,0);
}
void insert(vector<int>&heap,int key){
    heap.push_back(key);
    upheapify(heap,heap.size()-1);
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
        insert(heap,x);
    }
    display(heap);
    deletepeek(heap);
    display(heap);
    return 0;
}