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
int N,M;
bool vis[1001][1001];
bool isValid(int x,int y){
    if(x<1 || x>N || y<1 || y>M){
        return false;
    }
    if(vis[x][y]==true){
        return false;
    }
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y){
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    OJ;
    FIO;
    cin>>N>>M;
    dfs(1,1);
}