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

vector<pair<int,int> >adj[10001];
//int dist[10001];
int main(){
    OJ;
    FIO;
    int n,m;
    cin>>n>>m;
    int a,b,w;
    while(m--){
        cin>>a>>b>>w;
        adj[a].PB({b,w});
        adj[b].PB({a,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;//min heap
    vector<int>dist(n+1,INT_MAX);
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        int curr_N=pq.top().second;
        int curr_D=pq.top().first;
        pq.pop();
        for(pair<int,int> edge:adj[curr_N]){
            if(curr_D+edge.second<dist[edge.first]){
                dist[edge.first]=curr_D + edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}