#include <bits/stdc++.h>

int main() {
   std::string n;
   std::cin >> n;

   long long len = n.length(), ans=0, cur = 0;
   char prev = n[0];
   for (long long i = 1; i != len; i++){
      if (prev == n[i]) {
         cur++;
         ans = std::max(ans, cur); 
      } else cur = 0;
      prev = n[i];
   }
   printf("%lld\n", ans+1);

}
