/************
 FENWICK TREE 
tree[k] = sum(k-p(k)+1, k)
where p(k) is the larget
power of two that divides k
//TODO
************/

#include <bits/stdc++.h>

int array[] = {1, 3, 4, 8, 6, 1, 4, 2};
int sz = sizeof(array) / sizeof(array[0]);
int start = 2, end = 5; // 3 + 4 + 8 + 6
int tree[8];

int sum(int k, int tree[])
{
   int s = 0;
   while(k >= 1) {
      s += tree[k];
      k -= k&-k;
   }
   return s;
}
void add(int k, int x)
{
   int i = 1;
   while (i <= sz ){
      tree[i] += array[i];
      i+= i&-i;
      printf("[%d] %d \n", i, tree[i]);
   }
}


int main()
{

   int tree[sz];  
   tree[0] = array[0];
   for (int i = 1; i != sz; i++){
      tree[i] = array[i];
      add(i, array[i]);
   }

   return 0;
}
