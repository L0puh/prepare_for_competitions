#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

typedef long long ll;


ll solve_fast(ll n, ll m, ll k, std::vector<ll> ppl, std::vector<ll> ap){
   ll cnt = 0, i= 0, j=0;
   std::sort(ppl.begin(), ppl.end());
   std::sort(ap.begin(), ap.end());
   while (i < n && j < m){
      if (std::abs(ppl[i] - ap[j]) <= k){ i++; j++; cnt++; }
      else { 
         if (ppl[i] - ap[j] > k) j++;
         else i++;
      }
   }
   return cnt;
}

ll search(ll p, std::vector<ll> a, ll dif, ll n){
   ll s = 0, e = n-1, mid;
   while (s <= e){
      mid = (s + e)/2;
      if (a[mid] == p || (p >= a[mid] - dif && p <= a[mid] + dif))
         return mid;
      if (p < a[mid]) e = mid-1;
      else s = mid+1;
   }
   return -1; 
}
ll solve_slow(ll n, ll m, ll k, std::vector<ll> ppl, std::vector<ll> ap){
   ll cnt = 0;
   std::sort(ap.begin(), ap.end());
   for (ll i=0; i!=n; i++){
      if (m == 0) break;
      ll p = ppl[i];
      ll index = 0;
      if ((index = search(p, ap, k, m)) != -1){
         cnt++;
         m--;
         ap.erase(ap.begin()+index);
      }
   }
   return cnt;
}

int main() {
   ll n, m, k;
   scanf("%lld %lld %lld", &n, &m, &k);
   std::vector<ll> ppl(n), ap(m);
   for (ll i=0; i!=n; i++) scanf("%lld", &ppl[i]);
   for (ll i=0; i!=m; i++) scanf("%lld", &ap[i]);

   printf("%lld\n", solve_fast(n,m,k,ppl,ap));
}
