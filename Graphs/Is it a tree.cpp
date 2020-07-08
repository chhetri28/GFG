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
// #define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vi ar[10001];
int vis[10001];
void dfs(int node){
    vis[node]=1;
    for(int child:ar[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main() 
{
    //OJ;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        ar[a].PB(b);
        ar[b].PB(a);
    }
    int cc=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cc++;
        }
    }
    if(cc==1 and m==n-1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}