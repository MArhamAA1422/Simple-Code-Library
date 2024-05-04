// BISMILLAH

#include "bits/stdc++.h"

#define ll long long int
const int mxN = 2000005, inf = 1000000005;

int N;
int a[mxN];

int left[4 * mxN], right[4 * mxN];

void upd_left(int at, int l, int r, int idx) {
	if (idx < l || idx >= r) return;
	if (l+1 == r) {
		left[at] += 1;
		return;
	}
	int m = l + (r - l) / 2;
	upd_left(2 * at + 1, l, m, idx);
	upd_left(2 * at + 2, m, r, idx);
	left[at] = left[2 * at + 1] + left[2 * at + 2];
}

void upd_right(int at, int l, int r, int idx) {
	if (idx < l || idx >= r) return;
	if (l+1 == r) {
		right[at] += 1;
		return;
	}
	int m = l + (r - l) / 2;
	upd_right(2 * at + 1, l, m, idx);
	upd_right(2 * at + 2, m, r, idx);
	right[at] = right[2 * at + 1] + right[2 * at + 2];
}

int que_left(int at, int l, int r, int L, int R) {
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return left[at];
	if (l + 1 == r) return 0;
	int m = l + (r - l) / 2;
	return que_left(2 * at + 1, l, m, L, R) + que_left(2 * at + 2, m, r, L, R);
}

int que_right(int at, int l, int r, int L, int R) {
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return right[at];
	if (l + 1 == r) return 0;
	int m = l + (r - l) / 2;
	return que_right(2 * at + 1, l, m, L, R) + que_right(2 * at + 2, m, r, L, R);
}

signed main() {
	int testCases=1;
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d", &N);
		std::set<int> al;
		std::unordered_map<int, int> val;
		int value = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d",&a[i]);
			al.insert(a[i]);
		}
		for (auto i : al) {
			val[i] = value++;
		}
		ll ans = 0;
		for (int i = 0, x; i < N; i++) {
			x = val[a[i]];
			int tot = que_left(0, 0, 3*N, 0, x);
			// printf("%d : %d\n", i, tot);
			ans += (ll)a[i] * tot;
			upd_left(0, 0, 3*N, x);
		}
		for (int i = N - 1, x; i >= 0; i--) {
			x = val[a[i]];
			int tot = que_right(0, 0, 3*N, x+1, value);
			// printf("%d : %d\n", i, tot);
			ans -= (ll)a[i] * tot;
			upd_right(0, 0, 3*N, x);
		}
		printf("%lld", ans);
	}
	
	return 0;
}

/*

TESTED on: https://atcoder.jp/contests/abc351/tasks/abc351_f

*/