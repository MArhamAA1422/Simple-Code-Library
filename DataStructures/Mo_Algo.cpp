// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int,int>;

const int K = 350, mxN = 1e6+5;
int a[mxN], l=0, r=0, res=0;
std::unordered_map<int,int> cnt;

void add(int x) {
   x = a[x];
   if (cnt[x]==x&&x) res--;
   cnt[x]++;
   if (cnt[x]==x&&x) res++;
}

void rem(int x) {
   x = a[x];
   if (cnt[x]==x&&x) res--;
   cnt[x]--;
   if (cnt[x]==x&&x) res++;
}

void que(int L, int R) {
   while (l>L) add(--l);
   while (l<L) rem(l++);
   while (r>R) rem(r--);
   while (r<R) add(++r);
}

struct Q{
   int id, l, r;
};

signed main() {
   int testCases=1;
   // scanf("%d",&testCases);
   
   for (int T = 1; T <= testCases; T++) {
      int n; scanf("%d",&n);
      int m; scanf("%d",&m);
      
      for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
         
      std::vector<Q> q(m);
      for (int i = 0,l,r; i < m; i++) {
         scanf("%d%d",&q[i].l,&q[i].r);
         q[i].id = i;
      }
      
      sort(q.begin(),q.end(),[](Q fi, Q se){
         int fi_block_id = fi.l/K;
         int se_block_id = se.l/K;
         if (fi_block_id==se_block_id) return fi.r<se.r;
         return fi_block_id < se_block_id;
      });
      
      int ans[m];
      for (int i = 0; i < m; i++) {
         que(q[i].l,q[i].r);
         ans[q[i].id] = res;
      }
      
      for (int i = 0; i < m; i++) printf("%d\n",ans[i]);

   }
   
   return 0;
}

/**

Mo's Algo...
coordinate compression?

https://codeforces.com/contest/220/problem/B

*/