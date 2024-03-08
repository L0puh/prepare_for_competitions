#include <bits/stdc++.h>

typedef unsigned long long ull;


int main (){
   ull a, b;
   FILE* fp =  freopen("sumsqr.in", "r", stdin);
   scanf("%lld %lld", &a, &b);
   freopen("sumsqr.out", "w", stdout);
   printf("%lld\n", (ull)(std::pow(a, 2) + std::pow(b, 2)));

   return 0;
}

