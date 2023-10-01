// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;

ll EEA(ll a, ll b, ll &x, ll &y) { // ax + by = gcd(a,b)
	if (b==0) {
		x = 1;
		y = 0;
		return a;
	}
	
	ll xx,yy;
	
	ll g = EEA(b,a%b,xx,yy);
	
	x = yy;
	y = xx-a/b*yy;
	
	// ax + by = g
	// (b)x + (a%b)y = g
	// bx + (a-a/b*b)y = g;
	
	return g;
	
}

signed main() {
	ll x,y,g;
	
	while (true) {
		ll a,b; scanf("%lld%lld",&a,&b);
		g = EEA(a,b,x,y);
		printf("%lld*%lld + %lld*%lld = %lld\n",a,x,b,y,g);
	}
	
	return 0;
}

/**

TESTED LOCALLY

*/