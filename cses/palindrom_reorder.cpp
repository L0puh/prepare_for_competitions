// 0.37s of python over 0.06s of cpp

#include <bits/stdc++.h>

typedef long long ll;

int main() {
   std::string s;
   std::cin >> s;
   std::map<char, ll> map;
   
   for (auto& c: s)
      map[c]++;

   std::string pal = "", rest = "";
   int target = 0;
   char key = ' ';
   ll val = 0;
   for (auto& i: map){
      key = i.first;
      val = i.second;
      if (val % 2 != 0 || val == 1) target++;
      if (target > 1){
         printf("NO SOLUTION\n");
         return 0;
      } 
      if (val % 2 == 0){
         val/=2;
         while(val--)
            pal+=key;
      } else {
         while(val--)
            rest+=key;
      }
   }
   std::string rev_pal = pal;
   std::reverse(rev_pal.begin(), rev_pal.end());
   std::cout << pal << rest << rev_pal << '\n';

}
