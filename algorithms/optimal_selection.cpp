/*******************
    THE OPTIMAL
    solution for 
    n days and 
    k products. 
 ******************/

#include <bits/stdc++.h>

std::vector<std::vector<int>> grid = {
   //0  1  2  3  4  5  6  7    // days
   { 6, 9, 5, 2, 8, 9, 1, 6 }, // products
   { 8, 2, 6, 2, 7, 5, 7, 2 },
   { 5, 3, 9, 7, 3, 5, 1, 4 }
};

int k = grid.size();
int n = grid.at(0).size();

void print_bits(int x)
{
   for (int i = 9; i >= 0; i--){
      if (x&(1<<i)) putchar('1');
      else putchar('0');
   }
   putchar('\n');
}


int get_bits(int col){
   int x = 0;
   for (int i = 0; i != grid.at(col).size(); i++) {
       x |= (1 << grid.at(col).at(i));
   }
   return x;      
}

int set_bit(int pos, int x) {
   return x |= (1 << pos);
}

int total(int s, int day){
   //TODO
   return 0;
}

int main() {
   for (int col = 0; col != grid.size(); col++){
         print_bits(get_bits(col));
   }
   return 0;
}
