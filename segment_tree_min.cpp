/*************************
finds the minimum in the 
range query using segment
tree.
************************/


#include <bits/stdc++.h>
#include "utils.h"

int array[] = {5, 8, 6, 3, 1, 7, 2, 6};
const int n = sizeof(array) / sizeof(array[0]);
int tree[2*n];


int min(int x, int y)
{
   x+=n; y+=n;
   int m = INT_MAX;
   if (x > y) return -1;
   while (x <= y) {
      if (x % 2 == 1) m = std::min(tree[x++], m);
      if (y % 2 == 0) m = std::min(tree[y--], m);
      y/=2; x/=2;
   }
   return m;
}

void fill(int i, int n)
{
   for ( ; i != n; i++){
      tree[i] = std::min(tree[i*2], tree[i*2+1]);
   }
}
int main() {
   int x, y;   
   std::cin >> x >> y;
   
   //1. fill the tree
   for (int i = n; i != 2*n; i++){ // copy array
      tree[i] = array[i-n];
   }
   fill(n/2, n);
   fill(n/4, n/2);
   tree[1] = std::min(tree[2], tree[3]);

   print_array(tree, 2*n);

   //2. find min for the scope
   printf("%d\n", min(x-1, y-1));
}



