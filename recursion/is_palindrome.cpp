#include <bits/stdc++.h>

bool is_palindrome(std::string n){
   if (n.length() <= 1) return true;
   if(n.at(0) == n.at(n.length()-1)) 
      return is_palindrome(n.substr(1, n.length()-2));
   return false;
}

int main() {
   std::string n = "kauakk";
   std::cin >> n;
   if(is_palindrome(n)) printf("YES\n");
   else printf("NO\n");
}
