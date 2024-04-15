#include <bits/stdc++.h>

void move(int a, int b){
   printf("%d %d\n", a, b);
}

void print_moves(int disks, int from, int mid, int to){
   if (disks == 1) { 
      move(from, to);
      return;
   }
   print_moves(disks-1, from, to, mid); 
   move(from, to);
   print_moves(disks-1, mid, from, to);
}

int main(){
   int n;
   scanf("%d", &n);
   long min = (1<<n) - 1;

   printf("%ld\n", min);
   print_moves(n, 1, 2, 3);

   return 0;
}
