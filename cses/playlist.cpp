#include <bits/stdc++.h>
#define FOR(n, i) for (int i = 0; i != n; i++)

typedef long long ll;
int main(){
   ll n, index = 0, cur = 0, count = 1; scanf("%lld", &n);
   std::map<ll, ll> m;
   FOR(n, i){ 
      ll a;
      scanf("%lld", &a);
      if (m.find(a) != m.end()) {
         if (m[a] >= index){
            index = m[a] + 1;
         }
         m[a] = cur;
      } else {
         m.insert({a, cur});
      }
      count = std::max(count, cur-index+1);
      cur++;
   }
   printf("%lld\n", count);
}
