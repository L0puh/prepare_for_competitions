#include <bits/stdc++.h>
#include <queue>
#define weight second 

std::vector<std::pair<int, int>> graph[] = { //FIXME
   {1, {2, 2}},
   {1, {3, 4}},
   {2, {3, 3}},
   {3, {4, 7}},
};
const int N = sizeof(graph) / sizeof(graph[0]);
bool visited[N];
int  distance[N];

void print_distances(){
   for (int i = 0; i != N; i++){
      printf("%d ", distance[i]);
   }
   putchar('\n');
}
void print_queue(std::queue<int> q){
   int sz = q.size();
   for (int i=0; i!=sz; i++){
      printf("%d ", q.front());
      q.pop();
   }
   putchar('\n');
}
int main(){
   std::queue<int> q; 
   q.push(0);
   while (!q.empty()){
      int p = q.front();
      q.pop();
      if (visited[p]) continue;
      distance[p] = graph[p][0].second;
      for(const auto& n: graph[p]){
         if (n.first == p) continue;
         printf("%d -> %d\n", p, n.first);
         q.push(n.first);
      }
      visited[p] = true;
   }
   print_distances();   
   return 0;
}

