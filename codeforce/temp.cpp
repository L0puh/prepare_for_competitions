#include <bits/stdc++.h>


//TODO:
int main() {
   int t;
   std::scanf("%d", &t);
   while(t--){
      int n, d, temp;
      std::scanf("%d %d %d", &n, &d, &temp);
      int q[n], a[n];
      int ans = 0, strike = 0;
      for (int i=0; i != n; i++){
         std::scanf("%d", &q[i]);
         if (q[i] <= temp) {
            strike++;
            a[i] = q[i];
         }
         if (strike == d) {
            ans++;
            strike = 0;
         }
      }
      printf("%d\n", ans);
   }

   return 0;
}
