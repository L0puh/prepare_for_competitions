#include <bits/stdc++.h>

int main() {
   long long n, ans = 0;
   scanf("%lld", &n);
   long long a[n];
   scanf("%lld", &a[0]);
   for (long long i = 1; i != n; i++){
      scanf("%lld", &a[i]);
      if (a[i-1] > a[i]) {
         ans += std::abs(a[i] - a[i-1]);
         a[i] = a[i-1];
      }
   }
   printf("%lld\n", ans);
   return 0;
}
