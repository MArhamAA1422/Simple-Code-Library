// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)

using pii = std::pair<int,int>;
const int mxN = 1005, inf = 1000000005;

std::vector<int> g[mxN], transpose_g[mxN];
int finish_time[mxN], comp[mxN], cur_time, id;
bool vis[mxN];

std::vector<int> topo_order;
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	// cur_time++;  // discovery time
	for (auto v : g[u]) {
		dfs(v);
	}
	// finish_time[u] = ++cur_time;
	topo_order.push_back(u);
}

void dfs1(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	for (auto v : transpose_g[u]) {
		dfs1(v);
	}
	comp[u] = id;
}

void CLEAR(int N) {
	for (int i = 0; i < N; i++) {
		g[i].clear();
		transpose_g[i].clear();
		vis[i] = 0;
	}
	cur_time = 0;
	id = 0;
	topo_order.clear();
}

signed main() {
	// fastIO;
	int testCases=1;
	scanf("%lld",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		int N;
		scanf("%d", &N);
		int a[3][N];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		auto complement = [&](int u)
		{
			return u & 1 ? u - 1 : u + 1;
		};

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < 3; j++) {
				for (int k = 0; k < j; k++) {
					int u = a[j][i];
					int v = a[k][i];
					u = u > 0 ? 2 * (u - 1) : 2 * (abs(u)-1) + 1;
					v = v > 0 ? 2 * (v - 1) : 2 * (abs(v)-1) + 1;
					g[complement(u)].push_back(v);
					g[complement(v)].push_back(u);
					transpose_g[v].push_back(complement(u));
					transpose_g[u].push_back(complement(v));
					// printf("%d %d\n", u, v);
					assert(std::max(u, v) < 2 * N);
				}
			}
		}

		for (int i = 0; i < 2*N; i++) dfs(i);
		for (int i = 0; i < 2*N; i++) {
			vis[i] = 0;
		}
		// for (auto i : topo_order) {
		// 	printf("%d ", i);
		// }
		// printf("\n");
		for (int i = 0; i < 2*N; i++) {
			comp[i] = -1;
		}
		while ((int)topo_order.size()) {
			dfs1(topo_order.back());
			topo_order.pop_back();
			id += 1;
		}

		for (int i = 0; i < 2*N; i++) {
			printf("%d ", comp[i]);
		}
		printf("\n");

		CLEAR(2 * N);
	}
	
	return 0;
}

/*

TESTED on- https://codeforces.com/contest/1971/problem/H

*/