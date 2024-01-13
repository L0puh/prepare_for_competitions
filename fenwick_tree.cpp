//FIXME
#include <bits/stdc++.h>


/* int array[] = {5, -3, 6, 1, 0, -4, 11, 6, 2}; */
int array[] = {1, 3, 4, 8, 6, 1, 4, 2};
const int sz = sizeof(array) / sizeof(array[0]);
int tree[sz];

int LSB(int x){
   for (int i = 0; i != 32; i++){
      if (x&(1<<i)) return (1 << i);
   }
   return 0;
}

int prefix_sum(int i) {
   int s = 0;
   while (i != 0){
      std::cout << std::bitset<6>(i) << std::endl;
      printf("%d i:%d s:%d\n\n", LSB(i), i, s);
      s += tree[i];
      i -= LSB(i);
   }
   return s;
}

int range(int i, int j){
   return prefix_sum(j) - prefix_sum(i-1);
}
int largest_power(int x){
   return x&-x;
}
void sum(int k, int i){
   while(k <= i){
      tree[k] += i;
      k += largest_power(k);
   }
}

int main() {

   //precomute tree
   tree[1] = array[0];
   for (int i = 1; i != sz; i++){
      sum(i, array[i-1]);
      printf("%d\n", tree[i]);
   }
   putchar('\n');

   int i = 1, j = 7;
   printf("%d\n", range(i, j));

   return 0;
}

