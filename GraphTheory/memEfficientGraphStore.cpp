// BISMILLAH

#include <bits/stdc++.h>

const int mxN = 200005; // 2*(#edges) for bidirectional graph

int nextFree, link[mxN];

struct EDGE {
	int u;
	int v;
	int w;
	int l; // last position (link)
	// l=-1 means the edge is list traversing of u is done
	
	EDGE() {} // default constructor
	
	EDGE (int _u, int _v, int _w, int _l) {
		u = _u;
		v = _v;
		w = _w;
		l = _l;
	}
};

EDGE edge[mxN];
int used[mxN];

void addEdge(int u, int v, int w) {
	edge[nextFree] = EDGE(u,v,w,link[u]);
	link[u] = nextFree; // this is the position in edge array of last edge from u
	nextFree++;
}

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		
		// clear
		nextFree=0;
		memset(link,-1,sizeof(link)); // no need to clear the edge array!
		memset(used,0,sizeof(used));
		
		int n,m; // #nodes, #edges
		scanf("%d%d",&n,&m);
		
		for (int i = 0,u,v,w; i < m; i++) {
			scanf("%d%d%d",&u,&v,&w);
			addEdge(u,v,w);
			addEdge(v,u,w);
		}
		
		// for (int i = 1; i <= n; i++) printf("%d ",link[i]); printf("\n");
		// for (int i = 0; i < nextFree; i++) {
		// 	printf("%d %d %d %d\n",edge[i].u,edge[i].v,edge[i].w,edge[i].l);
		// }
		
		// TEST with BFS
		auto bfs = [&] (int x) {
			std::queue<int> q;
			q.push(x);
			used[x] = 1;
			
			while ((int)q.size()) {
				x = q.front();
				q.pop();
				printf("%d -> ",x);
				int y, lnk = link[x];
				while (lnk!=-1) {
					assert(edge[lnk].u==x);
					y = edge[lnk].v;
					lnk = edge[lnk].l;
					if (used[y]) continue;
					q.push(y);
					used[y] = 1;
				}
			}
			
		};
		
		// TEST with DFS
		std::function<void(int)> dfs = [&] (int x) {
			if (used[x]) return;
			used[x] = 1;
			
			printf("%d -> ",x);
			
			int y, lnk = link[x];
			while (lnk != -1) {
				assert(edge[lnk].u==x);
				y = edge[lnk].v;
				dfs(y);
				lnk = edge[lnk].l;
			}
			
		};
		
		// bfs(1);
		dfs(1);
		printf("\n");
		
	}
	
	return 0;
}

/**

IDEA FROM BACS_CAMP-2017

HELPFUL in FLOW PROBLEM

TESTED LOCALLY

*/