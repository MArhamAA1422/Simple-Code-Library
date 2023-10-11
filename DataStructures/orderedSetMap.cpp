// BISMILLAH

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using oMap = tree<T, R, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	oSet<int> a;
	// std::set<int> b;
	
	int digCount[10]={0};
	
	for (int i = 0,x; i < n; i++) {
		scanf("%d",&x);
		a.insert(-x);
		// b.insert(-x);
		while (x) {
			int d = x%10;
			digCount[d]++;
			x /= 10;
		}
	}
	
	char c;
	
	for (int q = 0,k,dig_sum; q < Q; q++) {
		scanf(" %c",&c);
		scanf("%d",&k);
		
		if (c=='+') {
			// if exists remove, otherwise add
			if (a.find(-k)==a.end()) {
				a.insert(-k);
				// b.insert(k);
				while (k) {
					int d = k%10;
					digCount[d]++;
					k /= 10;
				}
			} else {
				a.erase(-k);
				while (k) {
					int d = k%10;
					digCount[d]--;
					k /= 10;
				}
			}
		} else if (c=='-') {
			// remove k-th largest
			if ((int)a.size()<k) continue;
			k = *a.find_by_order(k-1);
			a.erase(k);
			k *= -1;
			while (k) {
				int d = k%10;
				digCount[d]--;
				k /= 10;
			}
		} else if (c=='?') {
			// cur digit sum
			if (a.find(-k)==a.end()) {
				puts("-1");
				continue;
			}
			dig_sum = 0;
			while (k) {
				int d = k%10;
				dig_sum += digCount[d];
				k /= 10;
			}
			
			printf("%d\n",dig_sum);
		}
	}
	
	return 0;
}

/**

	C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\ext\pb_ds\detail\resize_policy
	hash_standard_resize_policy_imp.hpp0000644 -> hash_standard_resize_policy_imp.hpp
	
	From YouKn0wWho's template
	
	oSet<int>se;
  	se.insert(1);
  	se.insert(2);
	
	cout << *se.find_by_order(0) << endl; ///k th element
  	cout << se.order_of_key(2) << endl; ///number of elements less than k
  	
  	oMap<int, int>mp;
  	mp.insert({1, 10});
  	mp.insert({2, 20});
  	
  	cout << mp.find_by_order(0)->second << endl; ///k th element
  	cout << mp.order_of_key(2) << endl; ///number of first elements less than k
  	
  	TESTED ON KUET INTRA CONTEST-2023

*/