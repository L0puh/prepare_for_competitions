#include <bits/stdc++.h>

typedef long long ll;

int main() {
   ll n, prev = 0, ans = -1e18;
   scanf("%lld", &n);
   ll a[n];

   for (ll i=0; i!=n; i++) 
      scanf("%lld", &a[i]);
  
   for (ll i=0; i!=n; i++) {
      if (prev+a[i] >= a[i]){
         prev += a[i]; 
      } else prev=a[i];
      if (prev > ans) ans = prev;
   }
   printf("%lld\n", ans);
}
