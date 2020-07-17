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

vector<int>bellman_ford(int n,int src,vector<vector<int>>edges){
    vector<int>dis(n+1,INT_MAX);
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto x:edges){
            int from=x[0],to=x[1],weight=x[2];
            if(dis[from]!=INT_MAX and dis[to]>dis[from]+weight){
                dis[to]=dis[from]+weight;
            }
        }
    }
     for(auto x:edges){
            int from=x[0],to=x[1],weight=x[2];
            if(dis[from]!=INT_MAX and dis[to]>dis[from]+weight){
                dis[to]=dis[from]+weight;
            }
        }
        return dis;
}
int main() 
{
OJ;
FIO;
int n,m;
cin>>n>>m;
vector<vector<int> >edges;
int a,b,w;
for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    edges.PB({a,b,w});
}
vector<int>dist=bellman_ford(n,1,edges);
for(int i=1;i<=n;i++){
    cout<<"Dist from src to "<<i<<" is "<<dist[i]<<"\n";
}
return 0;
   
}