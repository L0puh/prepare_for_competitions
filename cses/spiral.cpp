#include <bits/stdc++.h>

typedef long long ll;

ll solve(){
   ll x, y;
   scanf("%lld %lld", &x, &y);
   ll max = std::max(x, y);
   ll mid = (max * max) - (max - 1);
   if (max % 2 == 0){
      if (x > y) 
         return mid + (x-y);
      return mid - (y-x);
   }
   if (x > y) 
      return mid - (x-y);
   return mid + (y-x);
}

int main() {
   ll t;
   scanf("%lld", &t);
   while(t--) printf("%lld\n", solve());
   
   return 0;
}
