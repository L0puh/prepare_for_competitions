/*********************

     SEGMENT TREE 
     (binary tree)

         used 
    for every query 
    (sum, min, max)

          36 
      10      26
    3   7   11  15 
  1  2 3 4 5  6 7  8   <- array

************************/

#include <bits/stdc++.h>

//                   0  1  2  3  4  5  6  7  8  9  10 
const int array[] = {5, 8, 6, 3, 2, 7, 2, 6, 3, 4, 1};
const int n = sizeof(array) / sizeof(array[0]);
int tree[2*n];


int sum(int x, int y)
{
   x+=n; y+=n; 
   int res = 0;
   while ( x <= y) {
      if (x % 2 == 1) {    // odd. means there is no parent for x
                           //          9
                           //       6    3
                           //            * -> 
         res += tree[x++];
      }
      if (y % 2 == 0){     // even. means there no parent for y
                           //          9
                           //       2    7
                           //    <- *
         res += tree[y--];
      }
      x/=2; y/=2; 
      /* printf("x: %d y:%d res:%d\n", x, y, res); */
   }
   return res;
}


void fill(int i, int n){
   for (; i < n; i++ )
      tree[i] = tree[i*2] + tree[i*2+1];
}


int main()
{
   for(int i = n; i != 2*n; i++){
      tree[i] = array[i-n];
   }

   // fill the binarary tree
   fill(n/2, n);;
   fill(n/4, n/2);
   tree[1] = tree[n/4] + tree[n/4+1];

   for(int i = 1; i != 2*n; i++){
      printf("%d ", tree[i]);
   }
   putchar('\n');

   int x, y;
   std::cin >> x >> y;
   printf("\nsum:%d\n", sum(x-1, y-1));

}


