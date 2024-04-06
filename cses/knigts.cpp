#include <bits/stdc++.h>

int main() {
   uint n;
   unsigned long area, attack;
   scanf("%d", &n);
   for (size_t i = 1; i <= n; i++){
      area = (long) ((i*i) * (i*i - 1))/2;
      attack = 2*(i-1)*2*(i-2);
      printf("%lu\n", area-attack);
   }
}
