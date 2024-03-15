#include <bits/stdc++.h>

int main(){ 
   int t; 
   std::scanf("%d", &t);
   while(t--){
      long n;
      std::scanf("%ld", &n);
      long long a[n+1], cnt = 0;
      for (int i = 1; i != n+1; i++){
         std::scanf("%lld", &a[i]);
         if (a[i] == 0 && i-1 != 0 && a[i-1] != 0){
            a[i-1]--;
            a[i] = 1;
            cnt++;
         }
      }
      for (int i = 1; i != n; i++){
         if (a[i] != 0){
             cnt+=a[i];
          }
       }
     printf("%lld\n", cnt);
   }
}

