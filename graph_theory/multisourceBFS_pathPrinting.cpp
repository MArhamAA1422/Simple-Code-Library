// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0);

#define flush fflush(stdout)

using ll = long long int;
using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 1003;

int N, M;
int vis[mxN][mxN], sta;
char a[mxN][mxN];
int cost[mxN][mxN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
std::unordered_map<int,char> move;
std::unordered_map<char,int> back;

bool OK(int x, int y) {
	return std::min(x,y)>= 0 && x < N && y < M && a[x][y] != '#';
}

void bfs() {
	std::queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 'M') {
				q.push({i,j});
				vis[i][j] = sta;
				cost[i][j] = 0;
			}
		}
	}
	int x, y;
	// printf("%d %d\n",x,y);
	while ((int)q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		// printf("%d %d\n",x,y);
		for (int i = 0; i < 4; i++) {
			int new_x = x+dx[i];
			int new_y = y+dy[i];
			// printf("new: %d %d\n",new_x,new_y);
			if (OK(new_x, new_y) && vis[new_x][new_y] < sta) {
				// printf("then: %d %d\n",new_x,new_y);
				if (cost[new_x][new_y] > cost[x][y]+1) {
					cost[new_x][new_y] = cost[x][y]+1;
					vis[new_x][new_y] = sta;
					q.push({new_x,new_y});
				}
			}
		}
	}
}

void bfs1(int x, int y) {
	std::queue<pii> q;
	q.push({x,y});
	vis[x][y] = sta;
	std::vector<std::vector<char>> par_move(N, std::vector<char>(M));
	cost[x][y] = 0;
	int ini[2]; ini[0] = x, ini[1] = y;
	// printf("%d %d\n",x,y);
	while ((int)q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		// printf("%d %d\n",x,y);
		if (a[x][y] == 'M') {
			continue;
		}
		if (std::min(x,y) == 0 || x == N-1 || y == M-1) {
			std::string path;
			while (x != ini[0] || y != ini[1]) {
				// printf("%d %d %c\n",x,y,par_move[x][y]);
				char c = par_move[x][y];
				path += c;
				int temp = x;
				switch(c) {
				case 'U':
					x++;
					break;
				case 'D':
					x--;
					break;
				case 'L':
					y++;
					break;
				case 'R':
					y--;
				}
			}
			printf("YES\n%d\n",(int)path.size());
			reverse(path.begin(),path.end());
			printf("%s\n",path.c_str());
			return;;
		}
		for (int i = 0; i < 4; i++) {
			int new_x = x+dx[i];
			int new_y = y+dy[i];
			// printf("new: %d %d\n",new_x,new_y);
			if (OK(new_x, new_y) && vis[new_x][new_y] < sta) {
				if (cost[new_x][new_y] > cost[x][y]+1) {
					cost[new_x][new_y] = cost[x][y]+1;
					vis[new_x][new_y] = sta;
					q.push({new_x,new_y});
					par_move[new_x][new_y] = move[i];
				}
			}
		}
	}
	printf("NO");
}

signed main() {
	int testCases=1;
	// scanf("%d",&testCases);
	// std::cin >> testCases;
	
	move[0] = 'U';
	move[1] = 'D';
	move[2] = 'L';
	move[3] = 'R';
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d%d",&N,&M);
		for (int i = 0; i < N; i++) {
			scanf(" ");
			for (int j = 0; j < M; j++) {
				scanf("%c",&a[i][j]);
			}
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
			cost[i][j] = INT_MAX;
		}
		int r[2];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == 'A') {
					r[0] = i;
					r[1] = j;
				}
			}
		}
		
		++sta;
		bfs();
		
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < M; j++) {
		// 		printf("%d ",cost[i][j]);
		// 	} printf("\n");
		// }
		
		++sta;
		bfs1(r[0],r[1]);
		
	}
	
	return 0;
}

/*



*/