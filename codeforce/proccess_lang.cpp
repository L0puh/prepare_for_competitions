#include <bits/stdc++.h>

bool is_c(char c){ return c == 'b' || c == 'c' || c == 'd';}
bool is_v(char c){ return c == 'a' || c == 'e';}

int main(){
   int t;
   std::scanf("%d", &t);
   while(t--){
      int n;
      std::scanf("%d ", &n);
      std::string str="", ans="";
      for (int i=0; i != n+1; i++){
         char c; 
         std::scanf("%c", &c);
         str+=c;
      }
      str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
      if (n % 3 == 0){
         for (int i = 0; i != n; i++){
            if (i != 0 && i % 3 == 0)
               putchar('.');
            printf("%c", str[i]);
         }
      } else {
         for (int i = 0; i < n; ){
            if (i+2 >= n){
               ans+=str.substr(i, i+2);
               break;
            }
            if (is_c(str[i]) && is_v(str[i+1]) && is_c(str[i+2])){
               if (is_v(str[i+3])){  //CV
                  ans+=str.substr(i, 2);
                  if (i+2 >= n) break;
                  i+=2;
               } else { //CVC
                  ans+=str.substr(i, 3);
                  if (i+3 >= n) break;
                  i+=3;
               }
               ans += '.';
            }
         }
      }
      printf("%s\n", ans.c_str());
   }
}
