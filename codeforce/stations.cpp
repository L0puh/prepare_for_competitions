#include <bits/stdc++.h>

int main() {
   int t;
   scanf("%d", &t);
   while(t--){
      int st_count, req_count;
      scanf("%d %d", &st_count, &req_count);
      std::map<int, std::pair<int, int>> stations;
      for (int i = 0; i != st_count; i++){
         int st;
         scanf("%d", &st);
         if (!stations.count(st))
            stations[st].first = i;
         stations[st].second = i;
      }
      while(req_count--){
         int a, b;
         scanf("%d %d", &a, &b);
         if (stations.count(a) && stations.count(b)){
            if (stations[a].first < stations[b].second){
               printf("YES\n");
               continue;
            }
         }
         printf("NO\n");
      }
   }
}
