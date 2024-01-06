// BISMILLAH

#include <bits/stdc++.h>

#define flush fflush(stdout)

using ll = long long int;
using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 100;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int val;

int g[mxN][mxN];
bool vis[mxN][mxN];

void dfs(int x, int y, int N, int M, int T) {
	// printf("%d %d T: %d, N/2: %d\n",x,y,T,N/2);
	if (T==1) { if (y==-1 || y==N || x==N/2) return; }
	else if (T==2) { if (y==-1 || y==N/2 || x==N) return; }
	else if (T==5) { if (y==N/2 || x==N) return; }
	else if (T==4) { if (y==-1) return; }
		
	if (vis[x][y]) return;
	// printf("Then, %d %d\n",x,y);
	
	vis[x][y] = true;
	switch (M) {
		case 0:
			g[x-dx[0]][y-dy[0]] = ++val;  // T==3 ? 'U':'R';
			break;
		case 1:
			g[x-dx[1]][y-dy[1]] = ++val;
			break;
		case 2:
			g[x-dx[2]][y-dy[2]] = ++val;
			break;
		case 3:
			g[x-dx[3]][y-dy[3]] = ++val;
	}
	
	for (int i = 0; i < 3; i++) {
		dfs(x+dx[i],y+dy[i],N,i,T);
	}
}

signed main() {
	int testCases=1;
	// scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		int N; scanf("%d",&N);
		vis[N/2][N/2] = true; g[N/2][N/2] = -1;
		dfs(0,0,N,-1,1);
		
		// puts("OK");
		
		if (((N+1)/2)&1) {
			dfs(N/2,0,N,2,2);
			for (int i = N/2-1; i < N-1; i++) {
				vis[N-1][i] = true;
				g[N-1][i] = ++val;
			} vis[N-1][N-1] = true;
			std::swap(dx[0],dx[3]);
			std::swap(dy[0],dy[3]);
			std::swap(dx[1],dx[2]);
			std::swap(dy[1],dy[2]);
			dfs(N-2,N-1,N,0,3);  // up-down
			g[N/2+1][N/2] = ++val;
			
		} else {
			std::swap(dx[0],dx[3]);
			std::swap(dy[0],dy[3]);
			std::swap(dx[1],dx[2]);
			std::swap(dy[1],dy[2]);
			dfs(N/2,N-1,N,1,5);  // down-up
			// puts("OK");
			for (int i = N/2+1; i; i--) {
				vis[N-1][i] = true;
				g[N-1][i] = ++val;
			} vis[N-1][0] = true;
			std::swap(dx[0],dx[3]);
			std::swap(dy[0],dy[3]);
			std::swap(dx[1],dx[2]);
			std::swap(dy[1],dy[2]);
			std::swap(dx[2],dx[3]);
			std::swap(dy[2],dy[3]);
			dfs(N-2,0,N,2,4);
			g[N/2][N/2-1] = ++val;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (g[i][j]==-1) printf("T ");
				else printf("%d ",g[i][j]);
			}
			printf("\n");
		}
		
	}
	
	return 0;
}

/*

Initial Problem - https://atcoder.jp/contests/abc335/tasks/abc335_d

Type 1:
-------

Row Lim
->->v
v<-<-
...

Type 2:
-------

Col Lim
->->v...
v<-<-...

Type 3:
-------

Col Lim
  0
v<v
v^v
<^<
...

Type 4:
-------

Same as type 2 but upward now

Type 5:
-------

Col Lim
^v<
^v^
^<^
  0

*/