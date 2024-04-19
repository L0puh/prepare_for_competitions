#include <bits/stdc++.h>
#include <cstdio>

long solve_fast(long n){
   long past = -1, cnt = 0;
   long a[n];
   for (long i = 0; i != n; i++)
      scanf("%ld", &a[i]);

   std::sort(a, a+n);
   for (long i = 0; i != n; i++){
      if (past != a[i]) {
         past = a[i];
         cnt++;
      }
   }
   return cnt;
}


long solve_slow(long n){
   std::map<long, long> m;
   long cnt = 0;
   for (long i = 0; i != n; i++){
      long j; scanf("%ld", &j);
      if (m.count(j) == 0) {
         m[j]++;
         cnt++;
      }
   }
   return cnt;
}


int main() {
   long n;
   scanf("%ld", &n);
   printf("%ld\n", solve_fast(n));
}
