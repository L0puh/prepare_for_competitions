#include <bits/stdc++.h>


int main() {
   int t;
   std::scanf("%d", &t);
   for (int j=0; j != t; j++){
      int n;
      std::scanf("%d", &n);
      int ans[n];
      int seq[n];
      for (int i=0; i != n; i++){
         std::scanf("%d", &seq[i]);
      }
      for (int i = 0; i != n; i++){
         int times, res = seq[i];
         std::scanf("%d", &times);
         char str[times];
         std::scanf("%s", str);
         for (int l = 0; l != times; l++){ 
            if (str[l] == 'U'){
               res-=1;
               if (res < 0) res = 9;
            } else {
               res += 1;
               if (res > 9) res = 0;
            }
         }
         ans[i] = res;
      }
      for (int i=0; i!=n; i++){
         printf("%d ", ans[i]);
      }
      putchar('\n');
   }
}



