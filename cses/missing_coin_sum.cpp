#include <bits/stdc++.h>
#define FOR(n, i) for(ll i=0; i!=n;i++)
typedef long long ll;

int main() {
   ll n;
   scanf("%lld", &n);
   ll a[n];
   FOR(n, i)
      scanf("%lld", &a[i]);
   std::sort(a, a+n);
   ll min = 1;
   FOR(n, i){
      if (a[i] > min) break;
      min+=a[i];
   }
   printf("%lld\n", min);
}
