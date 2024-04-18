#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;
typedef vector<int> vi;

void solve
(vi col, vi diag1, vi diag2, long *ways, int row, vector<vi> board){
   if (row == 8){ 
      *ways+=1;
      return;
   }
   for (int i = 0; i != 8; i++){
      if (col[i] || diag1[row+i] || diag2[row-i+7] || board[row][i]) continue;
      col[i] = diag1[row+i] = diag2[row-i+7] = 1;
      solve(col, diag1, diag2, ways, row+1, board);
      col[i] = diag1[row+i] = diag2[row-i+7] = 0;
   }
}


int main() { 
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   vi col(16, 0), diag1(16, 0), diag2(16, 0);
   vector<vi> board(8, vi(8, 0));
   long ways=0;
   for (int i = 0; i != 8; i++){
      string n; cin >> n;
      for (int j = 0; j != 8; j++){
         if (n[j] == '*') board[i][j] = 1;
      }
   }
   solve(col, diag1, diag2, &ways, 0, board);
   printf("%ld\n", ways);
}
