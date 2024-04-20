#include <bits/stdc++.h>

std::string solve(std::string n){
   if (n == "") return "";
   char a = n[0];
   n.erase(n.begin(), n.begin()+1);
   return solve(n) + a;
}

int main() {
   std::string h = "hello";
   printf("%s\n", solve(h).c_str());
}
