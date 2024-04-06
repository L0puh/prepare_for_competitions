/*******************
  counts the number 
      of subgrids
  whose all corners
      are black 
        (1s)

 ******************/

#include <bits/stdc++.h>

std::vector<std::vector<int>> grid= {
   { 1, 1, 0, 0, 1 },
   { 0, 1, 1, 0, 0 },
   { 1, 1, 0, 0, 0 },
   { 0, 1, 1, 0, 1 },
   { 0, 0, 0, 0, 0 }
};
const int n = grid.size(),
          m = grid.at(0).size();

void print_bits(int x);
int get_bits(int col);
int calculate();

int calculate()
{
   int cnt=0, r;
   for (int col = 0; col != n-1; col++){
      r=col+1;
      while (r < n) {
         int x = get_bits(col);
         int y = get_bits(r);
         if (__builtin_popcount(x&y) > 1){
            print_bits(x);
            print_bits(y);
            putchar('\n');
            cnt++;
         }
         r++;
      }
   }
   return cnt;
}

int get_bits(int col)
{
   int x = 0;
   for(int i = 0; i != m; i++){
      if (grid.at(col).at(i)) {
         x |= (1 << i);
      }
   }
   return x;
}


int main()
{  
   printf("%d\n", calculate());
   return 0;
}


void print_bits(int x)
{
   for (int i = m; i >= 0; i--){
      if (x&(1<<i)) putchar('1');
      else putchar('0');
   }
   putchar('\n');
}
