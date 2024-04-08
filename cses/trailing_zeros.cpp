#include <bits/stdc++.h>

typedef long long ll;

int main(){
   ll n;
   scanf("%lld", &n);
   ll ans = 0, a = 5;
   while ( a <= n ){
      ans += n/a;
      a *= 5;
   }
   printf("%lld\n", ans);
   return 0;
}
