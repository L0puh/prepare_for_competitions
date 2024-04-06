#include <bits/stdc++.h>
#include <vector>

typedef long long ll;

void find_equal_sum(ll n, ll sum){
   sum/=2;
   std::vector<ll> a, vis(n+1, 0);
   ll res = 0, rem = 0, max = n;
   while ( res < sum) {
      rem = sum - res;
      if (rem > max) {
         a.push_back(max);
         vis[max] = 1;
         res+=max;
         max--;
      } else {
         a.push_back(rem);
         vis[rem] = 1;
         break;
      }
   }
   printf("%zu\n", a.size());
   for(auto& i: a)
      printf("%lld ", i);
   putchar('\n');

   printf("%llu\n", n-a.size());
   for (ll i=1; i != n+1; i++){
      if (!vis[i]) printf("%lld ", i);
   }
   putchar('\n');
}

int main() {
   ll n;
   scanf("%lld", &n);
   ll sum = n*(n+1)/2;
   if (sum % 2 == 0){
      printf("YES\n");
      find_equal_sum(n, sum);
   } else 
      printf("NO\n");
   
}
