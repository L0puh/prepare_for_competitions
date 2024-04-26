#include <bits/stdc++.h>
#define FOR(n,i) for(ll i=0; i!=n; i++)

typedef long long ll;

int main(){
   ll n; scanf("%lld", &n);
   ll a[n], max = 0;
   FOR(n, i){
      scanf("%lld", &a[i]);
      if (a[i] > max) max = a[i];
   }
   ll t = 1, cnt=0;
   while (t < max){
      FOR(n, i){
         if (a[i] == t){
            //TODO: check if there is a number t ahead?
            cnt++;
            t++;
            break;
         }
      }
   }
   printf("%lld\n", cnt);
}
