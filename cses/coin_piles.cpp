#include <bits/stdc++.h>

typedef long long ll;

bool check(ll a, ll b){
   bool f = std::max(a,b) > 2*std::min(a,b);
   bool s = (a+b) % 3 != 0;
   return f || s;
}


int main() {
   uint t;
   scanf("%d", &t);
   while(t--){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      if (check(a, b)){
         printf("NO\n"); 
      } else printf("YES\n");
   }
}
