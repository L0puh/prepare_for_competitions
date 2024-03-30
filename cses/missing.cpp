#include <bits/stdc++.h>

int main(){
   int n;
   scanf("%d", &n);
   int a[n+1];
   for (int i = 0; i != n-1; i++){
      int j;
      scanf("%d", &j);
      a[j] = j;
   }
   for (int i = 1; i != n+1; i++){
      if (a[i] != i){
         printf("%d\n", i);
         return 0;
      }
   }
}
