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

char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int N;
bool isValid(int x,int y){
	if(x>N || x<1 || y>N || y<1) return false;

	if(vis[x][y]||ar[x][y]=='T') return false;

	return true;
}
void bfs(int scrX,int srcY){
	queue<pii>q;
	q.push({scrX,srcY});
	dist[scrX][srcY]=0;
	vis[scrX][srcY]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		int d=dist[x][y];
		q.pop();
		for(int i=0;i<4;i++){
			int newX=x+dx[i];
			int newY=y+dy[i];
			if(isValid(newX,newY)){
				dist[newX][newY]=d+1;
				vis[newX][newY]=1;
				q.push({newX,newY});
			}
		}
	}
}
int main(){
	// OJ;
	// FIO;
	int srcX,srcY,endX,endY;
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>ar[i][j];
			if(ar[i][j]=='S')srcX=i,srcY=j;
			if(ar[i][j]=='E')endX=i,endY=j;
		}
	}
	bfs(srcX,srcY);
	cout<<dist[endX][endY]<<"\n";
}