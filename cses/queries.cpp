#include <bits/stdc++.h>

int main() {
   int t;
   scanf("%d", &t);
   while(t--){
      long n; 
      scanf("%ld", &n);
      if (n % 2 == 0 && n > 10){
         n /= 10;
      } else if ( n < 10) printf("%ld\n", n);
      else {
      }
   }
}
