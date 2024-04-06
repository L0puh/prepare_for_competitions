#include <bits/stdc++.h>

std::vector<int> graph[] = {
   {1, 2},  // 1 -> 2 
   {2, 5},
   {2, 3},
   {5, 2},
   {1, 4},
   {1, 3},
};
const int N = sizeof(graph) / sizeof(graph[0]);
bool visited[N];

int main(){
   int target = 4;
   std::cin >> target;
   int i = 0;
   while ( i < N ){
      if (visited[i]) continue;
      for(auto& n: graph[i]){
         if (n == target && graph[i][0] != n){
            printf("%d -> %d\n", graph[i][0], n);
         }
      }
      visited[i] = true;
      i++;
   }
   return 0;
}
