// BISMILLAH

#include "bits/stdc++.h"

using pii = std::pair<int,int>;

const int mxN = 2003;
char g[mxN][mxN];
int N, M, ans, idx;

const int siz = mxN*mxN;
int h[siz], block[siz];  // row-major

class DSU {
public:
	DSU() {
		for (int i = 0; i < siz; i++) h[i] = i, block[i] = 1;
	}
	int fnd(int x) {
		if (x==h[x]) return x;
		return h[x] = fnd(h[x]);
	}
	void uni(int u, int v) {
		u = fnd(u);
		v = fnd(v);
		if (u != v) {
			h[v] = u;
			block[u] += block[v];
		}
	}
};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int didx[] = {-2,2,-1,1};
int new_x, new_y, new_idx;

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d %d",&N,&M); didx[0] = -M, didx[1] = M;
		for (int i = 0; i < N; i++) {
			scanf(" ");
			for (int j = 0; j < M; j++) scanf("%c",&g[i][j]);
		}
		
		DSU dsu;
		
		auto OK = [&] (int x, int y) {
			if (std::min(x,y) < 0 || x == N || y == M) return false;
			if (g[x][y] == '1') return false;
			return true;
		};
		
		idx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++, idx++) {
				if (g[i][j] == '0') {
					for (int d = 0; d < 4; d++) {
						new_x = dx[d] + i;
						new_y = dy[d] + j;
						if (OK(new_x,new_y)) {
							new_idx = idx + didx[d];
							dsu.uni(idx, new_idx);
						}
					}
				}
			}
		}
		
		ans = idx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++,idx++) {
				if (g[i][j] == '0') ans = std::max(ans, block[dsu.fnd(idx)]);
			}
		}
		
		printf("Floor #%d: %d\n", T, ans);
		
	}
	
	return 0;
}

/*



*/