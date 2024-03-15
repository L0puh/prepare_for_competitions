#include <bits/stdc++.h>



int main() {
   long long nums[10]; 
   int t;
   for (int i = 0; i < 10; i++){
      nums[i] = std::pow(10, i);
   }
   scanf("%d", &t);
   while(t--){
      long long m, res = nums[9], ptr = 9;
      scanf("%lld", &m);
      while (m < res){
         res = nums[ptr--];;
      }
      printf("%lld\n", m - res);
   }
}
