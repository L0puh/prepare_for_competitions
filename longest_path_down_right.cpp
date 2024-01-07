#include <algorithm>
#include <bits/stdc++.h>

int n = 3;
int grid[3][3] = {
    {3, 2, 1},
    {5, 6, 2},
    {1, 3, 8},
};

int main(){
    // fill the first col and row
    for (int x=1; x != n; x++){
        grid[x][0] = grid[x-1][0] + grid[x][0];
    }
    for (int y=1; y != n; y++){
        grid[0][y] = grid[0][y] + grid[0][y-1];
    }
    for (int x=1; x != n; x++){
        for (int y=1; y != n; y++)
            grid[x][y]+= std::max(grid[x-1][y], grid[x][y-1]);
    }
    printf("%d\n", grid[n-1][n-1]);

}
