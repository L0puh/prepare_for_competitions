#include <bits/stdc++.h>

std::vector<int> graph[] = { 
   {1, 2}, // 0 -> 1, 2
   {0},    // 1 -> 0
   {3},    // 2 -> 3
   {4, 2}  // 3 -> 4, 2
};
const int N = (sizeof(graph) / sizeof(graph[0])) * 2;

void print_queue(std::queue<int> q){
   int sz = q.size();
   for (int i=0; i!=sz; i++){
      printf("%d ", q.front());
      q.pop();
   }
   putchar('\n');
}
int main(){
   bool visited[N];
   std::fill(visited, visited+N, 0);
   std::queue<int> q; 
   q.push(0);
   while (!q.empty()){
      int node = q.front(); q.pop();
      if (visited[node]) continue;
      for(auto& n: graph[node]){
         printf("%d -> %d\n", node, n);
         q.push(n);
      }
      visited[node] = true;

   }
   return 0;
}

