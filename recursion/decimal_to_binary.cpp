#include <bits/stdc++.h>
#include <string>

std::string solve(int n){
   if (n == 0) return "";
   std::string r = std::to_string(n%2);
   return solve(n/2) + r;
}

int main() {
   int n;
   std::cin >> n;
   printf("%s\n", solve(n).c_str());
   std::cout << "check: " <<  std::bitset<8>(n) << '\n';
}
