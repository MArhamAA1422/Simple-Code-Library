// BISMILLAH

#include <bits/stdc++.h>

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		int n,m; scanf("%d%d",&n,&m);
		std::vector<int> g[n+1];
		std::vector<int> inD(n+1,0);
		
		for (int i = 0,u,v; i < m; i++) {
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			inD[v]++;
		}
		
		std::vector<int> topo;
		
		auto topoSort = [&] () {
			std::queue<int> q;
			for (int i = 1; i <= n; i++) {
				if (inD[i]==0) {
					q.push(i);
				}
			}
			
			while ((int)q.size()) {
				int x = q.front();
				topo.push_back(x);
				q.pop();
				for (auto y : g[x]) {
					inD[y]--;
					if (inD[y]==0) {
						q.push(y);
					}
				}
			}
		};
		
		topoSort();
		
		if ((int)topo.size()!=n) {
			puts("NO Topology");
		} else {
			for (int i = 0; i < n; i++) {
				printf("%d%c",topo[i],"-\n"[i==n-1]);
			}
		} puts("");
		
	}
	
	return 0;
}

/**

TESTED LOCALLY

*/