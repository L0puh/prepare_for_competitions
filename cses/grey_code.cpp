#include <bits/stdc++.h>

void print_bin(long num, int p) {
   int index = 0;;
   int bin[p];
   //get binary 
   for (long i = 0; i < p; i++) {
      if (index == p) break;
      int bit = (num >> i) & 1;
      bin[index++] = bit;
    }

   //convert to grey code and reverse
   printf("%d", bin[p-1]);
   for (int i = p-1; i > 0; i--){
      if (bin[i] != bin[i-1]) putchar('1');
      else putchar('0');
   }
   putchar('\n');
}



int main() {
   int n;
   scanf("%d", &n);
   long sz = 1<<n;
   for (long i = 0; i <= sz-1; i++)
      print_bin(i, n);
}
