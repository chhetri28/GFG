#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
/*

O(n^3)
bool triplets1(vector<int>a,int n,int x){
     for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==x){
                    return true;
                }
            }
        }
    }
    return false;
}
*/
/*
O(n^2)
bool triplets2(vector<int>a,int n,int x){
    int l,r;
    for(int i=0;i<n-2;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==x){
            return true;
            }
            else if(a[i]+a[l]+a[r]<x){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return false;
}
*/
/*
// O(n^2)+ extra space
bool triplets3(vector<int>a,int n,int x){
    for(int i=0;i<a.size()-2;i++){
        unordered_set<int>s;
        int curr_sum=x-a[i];
        for(int j=i+1;j<n;j++){
            if(s.find(curr_sum-a[j])!=s.end()){
                return true;
            }
            s.insert(a[j]);
        }
    }
    return false;
}
*/
int main(){
    OJ;
    FIO;
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    sort(a.begin(),a.end());
    int f=1;
    if(triplets3(a,n,x)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}