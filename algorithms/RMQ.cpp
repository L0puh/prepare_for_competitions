#include <bits/stdc++.h>

const int MAX_N = 100'005;
const int LOG = 17;
int array[] = {2, 3, 4, 5, 3, 1, 1, 3};
int minima[MAX_N][LOG];
const int sz = sizeof(array) / sizeof(array[0]);

int power(int x){ //power of two
   return (1 << x);
}

int query(int L, int R){
   int len, j = 0;
   len = R-L+1;
   while(power(j+1) <= len){ //find log 
      j++;
   }
   return std::min(minima[L][j], minima[R-power(j)+1][j]);
   
}
int main() {
   // for interval of 1
   // it's only one min value
   for (int i = 0; i != sz; i++){ 
      minima[i][0] = array[i];
   }

   //preproccessing others 
   for (int j = 1; j < LOG; j++){ 
      for(int i = 0; i + power(j)-1 < sz; i++){
         minima[i][j] = std::min(
               minima[i][j-1], 
               minima[i+power(j-1)][j-1]);
      }
   }
   int R=3, L=1;
   printf("for [%d, %d]: %d\n", L, R, query(L-1, R-1)); 

}
