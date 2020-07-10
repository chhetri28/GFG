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

vector<pair<int,pii> >adj;
int n,m,a,b,w;
void addedge(int u,int v,int w)
{
    adj.PB({w,{u,v}});
}
class DisjointsSets{
    public:
    int *parent,*rnk;
    int n;
    DisjointsSets(int n){
        this->n=n;
        parent=new int[n+1];
        rnk=new int[n+1];
        for(int i=0;i<=n;i++){
            rnk[i]=0;
            parent[i]=i;
        }
    }
    int find(int u){
        if(u!=parent[u]){
            parent[u]=find(parent[u]);
        }
        return parent[u];
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(rnk[x]>rnk[y]){
            parent[y]=x;
        }
        else{
            parent[x]=y;
        }
        if(rnk[x]==rnk[y]){
            rnk[y]++;
        }
    }
};
int kruskal(){
    int mst_wt=0;
    sort(adj.begin(),adj.end());
    DisjointsSets ds(n);
    vector<pair<int,pii> >::iterator it;
    for(it=adj.begin();it!=adj.end();it++){
        int u=it->second.first;
        int v=it->second.second;
        int set_u=ds.find(u);
        int set_v=ds.find(v);
        if(set_u!=set_v){
            //cout<<u<<" - "<<v<<endl;
            mst_wt+=it->first;
            ds.merge(set_u,set_v);
        }
    }
    return mst_wt;
}
int main(){
    OJ;
    FIO;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        addedge(a,b,w);
    }
    int mst_wt=kruskal();
    cout<<mst_wt;
}