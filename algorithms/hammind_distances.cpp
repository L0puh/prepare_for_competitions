/********************
       finds 
    the minimun
  distance between
      strings 
********************/


#include <bits/stdc++.h>
#define MAX 1<<30
int min(int a, int b){
   return a < b ? a: b;
}
int main(){
   std::vector<uint> n = {
      0b00111, // 2
      0b01101,
      0b11110, // 3
   };
   int k = n.size();
   unsigned int m = MAX;
   for (int i=1; i < k; i++){
      m = min(__builtin_popcount(n.at(i)^n.at(i-1)), m);
   }
   printf("%d\n", m);
   
}

