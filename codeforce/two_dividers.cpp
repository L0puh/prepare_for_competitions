#include <bits/stdc++.h>
#include <cstdio>

int main(){
   int t; 
   std::scanf("%d", &t);
   for (; t > 0; t--){
      long long a, b, res;
      std::scanf("%lld %lld", &a, &b);
      if (b % a == 0) res = b * b/a;
      else res = b * a/std::gcd(a, b);
      printf("%lld\n", res);
   }
}
