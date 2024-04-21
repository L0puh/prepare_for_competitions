#include <bits/stdc++.h>

typedef long long ll;

// INPUT:   5 7 8 8 8 9 9 10 10 
// 5 + 7, 8, 8, 8, 9, 9, 10, 10 => 8

void solve_fast(ll w[], ll n, ll x){
   std::sort(w, w+n); 
   ll cnt = 0; 
   ll j = 0;
   for (ll i = n-1; j <= i; i--){
      if (w[i] + w[j] <= x){
         cnt++;
         j++;
      } else {
         cnt++;
      }
   }
   printf("%lld\n", cnt);
}

/*             FIRST TRY         */
void solve_slow(ll w[], ll n, ll x){
   std::sort(w, w+n); 
   ll cnt = 0, left = n, cur = w[n-1];
   ll vis[n]; bool target = true;
   std::fill(vis, vis+n, 0);
   vis[n-1] = 1;
   while (left > -1){
      target = true;
      for (ll i=0; i != left ; ++i){
         if (cur + w[i] <= x && !vis[i]) {
            printf("%lld + %lld\n", cur, w[i]);
            cnt++;
            vis[i] = 1;
            do {
               left--;
               cur = w[left];
            } while (vis[left]);
            target = false;
            vis[left] = 1;
            break;
         } 
         if (cur + w[i] > x) break;
      }
      if (target){
         printf("%lld\n", cur);
         cnt++;
         do {
            left--;
            cur = w[left];
         } while (vis[left]);
         vis[left] = 1;
      }
   }
   printf("%lld\n", cnt);
}

int main() {
   ll n, x;
   scanf("%lld %lld", &n, &x);
   ll w[n];
   for (ll i=0; i!=n; i++) scanf("%lld", &w[i]);
   solve_fast(w, n, x);
      
}
