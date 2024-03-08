#include <bits/stdc++.h>

std::string ALP = "abcdefghijklmnopqrstuvwxyz";

int main() {
   int t; 
   std::scanf("%d", &t);
   while(t--){
      int n, ans[3];
      std::scanf("%d", &n);
      if (n > 26 && n-1 == 26){
         ans[0] = n-26;
         ans[1] = n-26;
         ans[2] = n-ans[0]-ans[1];
      }
      else if (n > 26){ 
         ans[2] = 26;
         if (n-26 > 26){
            ans[1] = 26;
            ans[0] = (n-26)-26;
         } else {
            ans[1] = (n-26)-1;
            ans[0] = n - ans[1] - ans[2];
         }
      }
      else {
         ans[2] = n - 2;
         ans[1] = n-(n-2)-1;
         ans[0] = n-(n-2)-1;

      }
      for (int i=0; i!=3; i++){
         printf("%c", ALP[ans[i]-1]);
      }
      putchar('\n');
   }
}
