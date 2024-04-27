#include <bits/stdc++.h>

#define FOR(n,i) for(; i < n; i++)
#define num first
#define index second

typedef long long ll;

int main(){
   ll n, b, i=0; scanf("%lld", &n);
   std::vector<std::pair<ll, ll>> a;
   FOR(n, i){
      scanf("%lld", &b);
      a.push_back({b, i});
   }
   std::sort(a.begin(), a.end());
   ll cnt=1, prev=a[0].index; i=1;
   while (i < n){ 
      if (a[i].index < prev) cnt++;
      prev = a[i].index;
      i++;
   }
   printf("%lld\n", cnt);
}

