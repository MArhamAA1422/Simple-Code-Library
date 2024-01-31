// BISMILLAH

#include "bits/stdc++.h"

const int mxN = 100005;

int N, a[mxN];
int NGR[mxN], NGL[mxN];
int NSR[mxN], NSL[mxN];

signed main() {
	int testCases=1;
	// scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d",&N);
		for (int i = 0; i < N; i++) {
			scanf("%d",&a[i]);
		}
		
		std::vector<int> st, ts;
		for (int i = 0; i < N; i++) {
			while ((int)st.size() && a[st.back()] <= a[i]) {
				st.pop_back();
			}
			if ((int)st.size()) {
				NGL[i] = st.back();
			} else {
				NGL[i] = -1;
			}
			st.push_back(i);
			
			while ((int)ts.size() && a[ts.back()] >= a[i]) {
				ts.pop_back();
			}
			if ((int)ts.size()) {
				NSL[i] = ts.back();
			} else {
				NSL[i] = -1;
			}
			ts.push_back(i);
			
		}
		
		st.clear();
		ts.clear();
		
		for (int i = N-1; i >= 0; i--) {
			while ((int)st.size() && a[st.back()] <= a[i]) {
				st.pop_back();
			}
			if ((int)st.size()) {
				NGR[i] = st.back();
			} else {
				NGR[i] = -1;
			}
			st.push_back(i);
			
			while ((int)ts.size() && a[ts.back()] >= a[i]) {
				ts.pop_back();
			}
			if ((int)ts.size()) {
				NSR[i] = ts.back();
			} else {
				NSR[i] = -1;
			}
			ts.push_back(i);
		}
		
		for (int i = 0; i < N; i++) {
			printf("%d: NGL %d, NGR %d\n",i,NGL[i], NGR[i]);
		}
		puts("-----");
		for (int i = 0; i < N; i++) {
			printf("%d: NSL %d, NSR %d\n",i,NSL[i], NSR[i]);
		}
		
	}
	
	return 0;
}

/*

	TESTED locally

*/