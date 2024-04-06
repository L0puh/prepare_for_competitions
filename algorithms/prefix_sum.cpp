#include <bits/stdc++.h>

int main(){
   int sz = 5;
   int array[] = {1, 4, 6, 16, 22};

   int sums[sz];
   sums[0] = array[0];
   printf("%d ", sums[0]);
   for(int i = 1; i != sz; i++){
      sums[i]=sums[i-1]+array[i];
      printf("%d ", sums[i]);
   }
   putchar('\n');
   int k = 2, j = 4; // 4 + 6 + 16 = 26
   printf("ans: %d(%d - %d)\n", sums[j-1] - sums[k-2], sums[j-1], sums[k-2]);

   return 0;
}

