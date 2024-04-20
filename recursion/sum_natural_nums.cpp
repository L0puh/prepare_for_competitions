#include <bits/stdc++.h>

int solve(int n, int i){
   if (i == n) return n;
   return i + solve(n, i+1);
}

int main() {
   int n;
   std::cin >> n;
   printf("%d\n", solve(n, 0));
} 
