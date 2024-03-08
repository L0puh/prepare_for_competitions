#include <cstdio>

int main(){
   int t;
   std::scanf("%d", &t);
   while(t--){
      int a, b, c;
      std::scanf("%d %d %d", &a, &b, &c);
      int ans[] = {0, 0, 0};
      if (b % 2 == c % 2){
         ans[0] = 1;
      } 
      if (a % 2 == c % 2){
         ans[1] = 1;
      } 
      if (a % 2 == b % 2){
         ans[2] = 1;
      }
      printf("%d %d %d\n", ans[0], ans[1], ans[2]);
   }
   return 0;
}
