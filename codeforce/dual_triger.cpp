#include <bits/stdc++.h>

typedef long long ll;

int main() {
   ll t; scanf("%lld", &t);
   while(t--){
      ll n; scanf("%lld", &n);
      std::string s;
      std::cin >> s;
      ll cnt=0, last=1;
      for(int i=0; i!=n; i++){
         if (s[i] == '1'){ 
            cnt++;
            last = i;
         }
      }
      if (cnt % 2 == 0 || cnt==0 ){
         if (cnt == 2 && s[last] == s[last-1]){
            printf("NO\n");
         } else
            printf("YES\n");
      } else printf("NO\n");

   }
}
