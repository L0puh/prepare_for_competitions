#include <bits/stdc++.h>

typedef long long ll;

int main(){
   ll n;
   scanf("%lld", &n);
   ll a[n];
   for (ll i=0; i!=n;i++) 
      scanf("%lld", &a[i]);
   std::sort(a, a+n);
   ll mid = a[n/2], ans = 0;
   for (ll i=0; i!=n;i++) 
      ans += std::abs(mid - a[i]);
   printf("%lld\n", ans);
}
