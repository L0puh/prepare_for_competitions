#include <bits/stdc++.h>
#include <queue>
#include <vector>

int main(){

   std::vector<int> graph[] = {
      {1, 2}, // 0 -> 1, 2
      {},
      {1, 3},
      {0},
      {6},  // <- aren't connected;
      {7}
   };
   int N = sizeof(graph) / sizeof(graph[0]);
   std::queue<int> q;
   int visited[N];
   std::fill(visited, visited+(N*2), -1);
   q.push(0);
   int cnt = 1;
   while(!q.empty()){
      int node = q.front(); 
      q.pop();
      if (visited[node] != -1 || graph[node].empty()) 
         continue;
      visited[node] = node;
      cnt++;
      for (auto& neigs: graph[node]){
         q.push(neigs);
      }
   }
   printf("NODES WITHOUT CONNECTION: %d\n", N-cnt);
   for (int i = 0; i != N; i++){
      if (visited[i] == -1){
         for (auto& neigs: graph[i]){
            printf("%d -> %d\n", i, neigs);
         }
      }
   }

}
