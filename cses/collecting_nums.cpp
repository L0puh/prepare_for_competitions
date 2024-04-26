#include <bits/stdc++.h>
#include <vector>
#define FOR(n,i) for(ll i=0; i!=n; i++)
#define num first 
#define index second

typedef long long ll;

int main(){
   ll n, b; scanf("%lld", &n);
   std::vector<std::pair<ll, ll>> a;
   FOR(n, i){
      scanf("%lld", &b);
      a.push_back({b, i});
   }
   std::sort(a.begin(), a.end());
   ll cnt=0, prev = 0;
   FOR(n, i){
      if (a[i].index > i+1) cnt++;
   }
   printf("%lld\n", cnt);
}
