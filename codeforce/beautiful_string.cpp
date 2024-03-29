#include <bits/stdc++.h>

int main() {
   int t;
   scanf("%d", &t);
   while(t--){
      int n;
      scanf("%d", &n);
      std::string str;
      int count = 0;
      std::cin >> str;
      
      for (int i = 0; i != n; i++){
         if (str[i] == 'p' && i+2 < n){
            if (str[i+1] == 'i' && str[i+2] == 'e') {
               count++;
               i+=2;
            }
         } else if (str[i] == 'm' && i+2 < n){
            if (str[i+1] == 'a' && str[i+2] == 'p'){
               count++;
               i+=2;
            }
         }
      }
      printf("%d\n", count);


   }
}
