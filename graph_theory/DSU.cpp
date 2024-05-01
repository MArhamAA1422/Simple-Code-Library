// BISMILLAH

#include <bits/stdc++.h>

const int siz = 1000006;
int H[siz];

void ini() {
	for (int i = 0; i < siz; i++) {
		H[i] = i;
	}
}

int fnd(int x) {
	if (x==H[x]) return x;
	return H[x] = fnd(H[x]);
}

void uni(int ux, int vy) {
	int u = fnd(ux);
	int v = fnd(vy);
	H[v] = H[u];
}

signed main() {
	// do stuffs
	
	return 0;
}

/**

	Need to Improve the code (it's just the basic one)

*/