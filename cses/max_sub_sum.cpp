#include <bits/stdc++.h>

typedef long long ll:

int main() {
   ll n;
   scanf("%lld", &n);
   ll a[n], res[n];
   for (ll i=0; i!=n; i++) 
      scanf("%lld", &a[i]);

   res[0] = a[0];
   ll max = 0;
   for (ll i=1; i!=n; i++) {
      res[i] = a[i] + res[i-1];
      if (res[i] > max) max = res[i];
   }
   printf("%lld\n", max);
}
