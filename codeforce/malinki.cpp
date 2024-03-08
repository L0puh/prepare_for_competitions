#include <bits/stdc++.h>

int mul(int a[], int n){
   int res = 1;
   for (int i = 0; i != n; i++)
      res *= a[i];
   return res;
}

int find_max(int n, int k, int a[]){
   int cnt=0;
   while(1){ 
      for (int i=0; i!=n; i++) {
         a[i] += 1;
         if (a[i] % k == 0) 
            return ++cnt;
       }
      cnt++;
   }
}

int main() {
   int t;
   std::scanf("%d", &t);
   while(t--){
      int n=0, k=0;
      int cnt = 0, even = 0;
      std::scanf("%d %d", &n, &k);
      int a[n];
      bool target=false;
      for (int i=0; i < n; i++) {
         std::scanf("%d", &a[i]);
         if (a[i] % 2 == 0) even++;
         if (a[i] % k == 0 && k != 4) 
            target=true;
      }
      if (target) goto ans;
      if (k != 4){
         while(1){ 
            for (int i=0; i!=n; i++) {
               a[i] += 1;
               if (a[i] % k == 0) {
                  cnt++;
                  goto ans;
               }
            }
            cnt++;
         }
         ans:
         printf("%d\n", cnt);
      } else {
         if (mul(a, n) % k == 0) printf("0\n");
         else {
            int f = std::max(0, 2-even);
            printf("%d\n", std::min(find_max(n, k, a), f));
         }
      }
   }
}
