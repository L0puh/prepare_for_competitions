#include <bits/stdc++.h>
#include <vector>

typedef long long ll;

int main(){
   ll n, a, b;
   scanf("%lld\n", &n);
   std::vector<std::pair<ll, ll>> t;
   for(ll i=0; i!=n; i++) {
      scanf("%lld %lld", &a, &b);
      t.push_back({a,  1});
      t.push_back({b, -1});
   }
   std::sort(t.begin(), t.end());
   ll ans = 0, cur = 0;
   for (ll i=0; i!=2*n;i++){
      cur += t[i].second;
      if (cur > ans) ans = cur;
   }
   printf("%lld\n", ans);
}
