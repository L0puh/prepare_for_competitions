#include <bits/stdc++.h>
#include <set>
 
typedef long long ll;
 
 
int main() {
   ll n, m, j;
   scanf("%lld %lld", &n, &m);
   std::multiset<ll> s;
   for (ll i=0; i!=n; i++){
      scanf("%lld", &j);
      s.insert(j);
   }
   for (ll i=0; i!=m; i++){
      scanf("%lld", &j);
      auto t = s.upper_bound(j);
      if (t == s.begin()) printf("-1\n");
      else { 
         t--;
         printf("%lld\n", *t);
         s.erase(t);
      }
   }
}

