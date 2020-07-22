#include<bits/stdc++.h>
using namespace std;
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int N,M;
int vis[1001][1001];
int dist[1001][1001];
int ways[1001][1001];
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, +1, -1};

void bfs(int x, int y, int n, int m)
{
	queue<pair<int, int> > q;
	q.push({x, y});
	ways[x][y]=1;
	vis[x][y]=1;
	dist[x][y]=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int dir=0;dir<4;dir++)
		{
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(nx<1 || ny<1 || nx>n || ny>m)
				continue;
			if(!vis[nx][ny])
			{
				dist[nx][ny]=dist[x][y]+1;
				vis[nx][ny]=1;
				ways[nx][ny]+=ways[x][y];
				q.push({nx, ny});
			}
			else
			{
				if(dist[x][y] + 1 == dist[nx][ny])
					ways[nx][ny]+=ways[x][y];
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	OJ;
	FIO;
	cin>>N>>M;
	int x,y;
	cin>>x>>y;
	bfs(x,y,N,M);
}