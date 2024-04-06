#include <bits/stdc++.h>
#define MOD 1000000007 // 10^9 + 7

typedef long long ll;

int main() {
   ll n;
   scanf("%lld", &n);
   ll res = 2;
   while (n > 1){
      res *= 2;
      res %= MOD;
      n--;
   }
   printf("%lld\n", res);
}

