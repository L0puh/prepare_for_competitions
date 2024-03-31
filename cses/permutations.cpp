#include <bits/stdc++.h>

int main() {
   int n;
   scanf("%d", &n);
   int a[n];
   for (int i = 1; i != n+1; i++){
      a[i-1] = i;
   }
   //FIXME
   for (int i = 0; i != n; i++){
      if (std::abs(a[i+1] - a[i]) == 1 && i+2 < n){
         //swap
         int b = a[i+1];
         a[i+1] = a[i+2];
         a[i+2] = b;
      }
   }
   for (int i = 0; i != n; i++){
      printf("%d ", a[i]);
   }
   putchar('\n');

}
