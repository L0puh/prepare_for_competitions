#include <bits/stdc++.h>

int main() {
   int t;
   scanf("%d", &t);
   while(t--){
      int n, a = 0, b = 0, pairs = 0;
      char prev = ' ';
      std::string str = "";
      scanf("%d", &n);
      std::cin >> str;
      for (int i = 0; i != n; i++){
         char c = str[i];
         if (c == 'A') a++;
         else b++;
         if (prev == 'A' && c == 'B') pairs++;
         prev = c;
      }
      //FIXME?
      if (pairs == 0) printf("%d\n", pairs);
      else printf("%d\n", std::min(a+1, b+1));
   }
}
