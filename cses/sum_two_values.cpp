#include <bits/stdc++.h>
#include <vector>

#define S second
#define F first 


typedef long long ll;

void solve_fast(){
   ll n, x;
   scanf("%lld %lld", &n, &x);
   std::vector<std::pair<ll, ll>> a;
   for (ll i=0; i!=n;i++){
      ll b;
      scanf("%lld", &b);
      a.push_back({b, i});
   }
   std::sort(a.begin(), a.end());
   ll l = 0, r = n-1;
   for (ll i=0; i!=n;i++){
      ll sum = a[l].F + a[r].F;
      if (r == l) break;
      if (sum == x){
         printf("%lld %lld\n", a[l].S+1, a[r].S+1);
         return;
      }
      if (sum > x) r--;
      if (sum < x) l++;
   }

   printf("IMPOSSIBLE\n");
}

void solve_slow(){
   ll n, x;
   scanf("%lld %lld", &n, &x);
   ll a[n];
   for (ll i=0; i!=n;i++){
      scanf("%lld", &a[i]);
   }
   ll l = 0, r = n-1;
   while (l < r){
      if (a[l] + a[r] == x){
         printf("%lld %lld\n", l+1, r+1);
         return;
      }
      l++;
      if (l+1 > r) {
         l = 0;
         r--;
      }
   }
   printf("IMPOSSIBLE\n");
}

int main() {
   solve_fast();
   return 0;

}
