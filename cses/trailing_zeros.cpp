#include <bits/stdc++.h>

typedef long long ll;

int main(){
   ll n;
   scanf("%lld", &n);
   ll ans = 0;
   for (ll i = 5; n/i >= 1; i*=5) //count the number of 5's powers 
      ans += n/i;
   printf("%lld\n", ans);
   return 0;
}
