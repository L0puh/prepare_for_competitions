#include <bits/stdc++.h>

typedef long long ll;

struct t {
   ll s;
   ll e;
};

int main(){
   ll n, a, b;
   scanf("%lld\n", &n);
   std::vector<t> times;
   for(ll i=0; i!=n; i++) {
      scanf("%lld %lld", &a, &b);
      times.push_back({a, b});
   }
   std::sort(times.begin(), times.end());
   ll ans = 0, cur = 0;
   for(auto& a: times) printf("%lld -> %lld\n", a.s, a.e);
   printf("%lld\n", ans);
}
