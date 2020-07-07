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

vi ar[1001];
int vis[1001];
int dist[1001];
void dfs(int node,int d){
    vis[node]=1;
    dist[node]=d;
    for(int child:ar[node]){
        if(!vis[child]){
            dfs(child,dist[node]+1);
        }
    }
}
int main() 
{
    OJ;
 int n;
 cin>>n;
 for(int i=1;i<=n-1;i++){
    int a,b;
    cin>>a>>b;
    ar[a].PB(b);
    ar[b].PB(a);
 }
 dfs(1,0);
 int q;
 cin>>q;
 int ans=-1;
 int min_dist=INT_MAX;
 while(q--){
    int girl_city;
    cin>>girl_city;
    if(dist[girl_city]<min_dist){
        min_dist=dist[girl_city];
        ans=girl_city;
    }
    else if(dist[girl_city]==min_dist and girl_city<ans){
        ans=girl_city;
    }
 }

cout<<ans;
return 0;  
}