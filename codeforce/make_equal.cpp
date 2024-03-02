#include <bits/stdc++.h>

int main() {
   int t;
   std::scanf("%d", &t);
   int ans[t];
   for (int i = 0; i != t; i++){
      int n;
      std::scanf("%d", &n);
      int seq[n];
      for (int j = 0; j != n; j++){
         std::scanf("%d", &seq[j]);
      }
      int start = 0, stop = 0;
      while (start < n && seq[start] == seq[0]) start++;
      while (stop < n && seq[n - stop - 1] == seq[n-1]) stop++;
      int res = n;
      if (seq[0] == seq[n-1]){
         res -= start;
         res -= stop;
      } else res -= std::max(start, stop);
      printf("%d\n", std::max(0, res));
   }
}
