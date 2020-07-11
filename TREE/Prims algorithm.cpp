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
// #define OJ \
//     freopen("input.txt", "r", stdin); \
//     freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main(){
    //OJ;
    FIO;
    int n,m;
    cin>>n>>m;
    vector<pii>gr[n+1];
    int a,b,w;
    while(m--){
        cin>>a>>b>>w;
        gr[a].PB({b,w});
        gr[b].PB({a,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    int vis[n+1]={0};
    int mst=0;
    while(!pq.empty()){
        pii best=pq.top();
        pq.pop();
        int weight=best.first;
        int to=best.second;
        if(vis[to]) continue;

        mst+=weight;
        vis[to]=1;
        for(auto x:gr[to]){
            if(vis[x.first]==0){
                pq.push({x.second,x.first});
            }
        }
    }
    cout<<mst;
}