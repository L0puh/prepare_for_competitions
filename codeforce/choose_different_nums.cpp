/* 
k = 6 -> k/2 
 
1 2 3 4 5 6 
 
a = 2 3 8 5  6 5 -> 2 3 6 
b = 1 3 4 10 5  -> 1 4 5
*/
 
 
#include <bits/stdc++.h>
 
int main(){
   int t; 
   scanf("%d", &t);
   for (int j = 0; j != t; j++){
      int k, n, m ;
      scanf("%d %d %d", &n, &m, &k);
      int limit = k/2, a[n], b[m];

      for (int i = 0; i != n; i++) scanf("%d", &a[i]);
      for (int i = 0; i != m; i++) scanf("%d", &b[i]);

      int cnt_a = 0, cnt_b = 0, cnt = 0;
      int ans_a[k+1], ans_b[k+1];
      std::fill(ans_a, ans_a+k+1, 0);
      std::fill(ans_b, ans_b+k+1, 0);

      for (int i = 0; i != n; i++){
         if (a[i] <= k) ans_a[a[i]]++;
      }
      for (int i = 0; i != m; i++){
         if (b[i] <= k) ans_b[b[i]]++;
      }
      for(int i = 1; i != k+1; i++){
         if (ans_a[i] && !ans_b[i]) cnt_a++;
         else if (!ans_a[i] && ans_b[i]) cnt_b++;
         else if (ans_a[i] && ans_b[i]) cnt++;
      }
      for (int i = 0; i != cnt; i++){
         if (cnt_a < limit)
             cnt_a++;
         else if (cnt_b < limit)
             cnt_b++;
      }
      if (cnt_a == limit && cnt_b == limit) printf("YES\n");
      else printf("NO\n");
   }
}

