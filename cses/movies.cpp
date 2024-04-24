#include <bits/stdc++.h>
#define F first 
#define S second

typedef long long ll;
typedef std::pair<ll, ll> pair;

int main(){
   ll n, a, b;
   scanf("%lld\n", &n);
   std::vector<pair> t;
   for(ll i=0; i!=n; i++) {
      scanf("%lld %lld", &a, &b);
      t.push_back({b, a});
   }
   std::sort(t.begin(), t.end());
   ll ans = 0, i=0, cur_end=-1;
   for(ll i=0; i!=n; i++){
      if (cur_end <= t[i].second){
         cur_end = t[i].first;
         ans++;
      }
   }
   printf("%lld\n", ans);
}
