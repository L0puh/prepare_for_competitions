#include <bits/stdc++.h>
#include <vector>

#define b begin()

enum directions{
   W=1,
   S=2,
   N=3,
   E=4,
};

bool path_W(int j, std::vector<int> g, int m){
   for (j--; j >= 0; j--){
      if (g[j] == W) continue;
      if (g[j])
         return false;
   }
   return true;
}
bool path_E(int j, std::vector<int> g, int m){
   for (j++; j < m; j++){
      if (g[j] == E) continue;
      if (g[j]) return false;
   }
   return true;
}
bool path_N(int i, int j, std::vector<std::vector<int>> g, int n){
   for (i--; i >= 0; i--){
      if (g[i][j]) return false;
   }
   return true;
}
bool path_S(int i, int j, std::vector<std::vector<int>> g, int n){
   for (i++; i < n; i++){
      if (g[i][j]) return false;
   }
   return true;
}

int solve(std::vector<std::vector<int>> *grid, int n, int m){
   int cnt = 0; 
   for(int i = 0; i != n; i++){
      for (int j =0; j!= m; j++){
         if(grid->at(i).at(j) == W){
            if (path_W(j, grid->at(i), m)){
               cnt++;
               grid->at(i)[j]=0;
               break;
            }
         } else if(grid->at(i).at(j) == N){
            if (path_N(i, j, *grid, n)){
               cnt++;
               grid->at(i).at(j)=0;
            }
         } else if (grid->at(i)[j] == S){
            if(path_S(i, j, *grid, n)){
               cnt++;
               grid->at(i)[j] = 0;
            }
         } else if (grid->at(i)[j] == E){
            if(path_E(j, grid->at(i), m)){
               cnt++;
               grid->at(i)[j]=0;
            }
         }
      }
   }
   return cnt;
}

int main(){
   int n, m;
   FILE* fp =  freopen("alligator.in", "r", stdin);
   scanf("%d %d", &n, &m);

   std::string str;
   int cnt = 0;
   std::vector<std::vector<int>> grid(n, std::vector<int>(m));
   for(int i = 0; i != n; i++){
      std::cin >> str;
      for (int j=0; j !=  str.size(); j++){
         if (str[j] == 'W'){
            if (j == 0) cnt++;
            else grid[i][j] = W;
         }
         else if (str[j] == 'S'){
            if (i == n-1) cnt++;
            else grid[i][j] = S;
         }
         else if (str[j] == 'E'){
            if (j == m-1) cnt++;
            else  grid[i][j] = E;
         }
         else if (str[j] == 'N'){
            if (i == 0) cnt++;
            else grid[i][j] = N;
         }
         else grid[i][j] = 0;
      }
   }
   int res = 1;
   while (res != 0){
      res = solve(&grid, n, m);
      cnt+= res;
   }

   freopen("alligator.out", "w", stdout);
   printf("%d\n", cnt);
   return 0;
}

