// I AM A MUSLIM

#include <bits/stdc++.h>

using lli = long long int;

using pii = std::pair<int,int>;
const int mxN = 5e5 + 9;
int node_val[mxN];
lli tree[4*mxN];
std::vector<int> g[mxN];
int tim = 0;
int ett[mxN][2];

void build(int at, int l, int r) {
    if (l+1 == r) {
        tree[at] = node_val[l];
        return;
    }
    int m = l+(r-l)/2;
    build(2*at+1, l, m);
    build(2*at+2, m, r);
    tree[at] = tree[2*at+1] + tree[2*at+2];
}

void update(int at, int l, int r, int idx, int v) {
    if (idx < l || idx >= r) return;
    if (l+1 == r) {
        tree[at] = v;
        return;
    }
    int m = l+(r-l)/2;
    update(2*at+1, l, m, idx, v);
    update(2*at+2, m, r, idx, v);
    tree[at] = tree[2*at+1] + tree[2*at+2];
}

lli query(int at, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) return 0;
    if (lx <= l && r <= rx) return tree[at];
    int m = l+(r-l)/2;
    return query(2*at+1, l, m, lx, rx) + query(2*at+2, m, r, lx, rx);
}

void clear(int n) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

void dfs(int u, int p=-1) {
    ett[u][0] = ++tim;
    for (auto &v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    ett[u][1] = ++tim;
}

signed main() {
    int n, q;
    scanf("%d%d",&n,&q);
    std::vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, u, v; i < n-1; i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        node_val[ett[i][0]] = a[i];
        node_val[ett[i][1]] = -a[i];
    }
    build(0, 0, 2*n+1);
    for (int i = 0, ty, s, x; i < q; i++) {
        scanf("%d%d",&ty,&s);
        if (ty == 1) {
            scanf("%d",&x);
            update(0, 0, 2*n+1, ett[s][0], x);
            update(0, 0, 2*n+1, ett[s][1], -x);
        } else {
            printf("%lld\n", query(0, 0, 2*n+1, 1, ett[s][0]+1));
        }
    }
    
    return 0;
}

/*
    TESTED on - Leetcode, CSES
    https://cses.fi/problemset/task/1138
*/