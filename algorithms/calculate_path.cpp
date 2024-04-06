// does not work correctly??
// TODO!!
// https://codegolf.stackexchange.com/questions/236480/find-the-number-of-paths-in-a-n×n-grid

#include <bits/stdc++.h>
#include <vector>

#define AT(n) at(n).at(n) 
typedef std::vector<std::vector<int>> vi;


void fill_grid(vi *grid, int n){
    for (int x = 0; x != n; x++){
        for (int y = 0; y != n; y++)
            grid->at(x).push_back(0);
    }
}

void copy_array(vi* arr, vi* arr2){
    for (int i = 0; i != arr->size(); i++){
        for (int j = 0; j != arr->size(); j++)
            arr2->at(i).push_back(arr->at(i).at(j));
    }
}


bool check_all_cells(vi *grid){
    int n = grid->size();
    for (int x = 0; x != n; x++){
        for (int y = 0; y != n; y++){
            if ((x == n-1 && y == n-1) ) {
                return true;
            }
            if (x == 0 && y == 0) continue;
            if (grid->at(x).at(y) != 1){
                return false;
            }
        }
    }
    return true;
}

//with optimizations
void calculate_paths_optim(vi *grid, int x, int y, int *count){
    if (x < 0 || y < 0 || x >= grid->size() || y >= grid->size()) return;
    if (x == grid->size()-1 && y == grid->size()-1) {
        if (check_all_cells(grid))
            *count = *count + 1;
        printf("COUNT: %d\n", *count);
        return;
    }
    if (grid->at(x).at(y) == 1) return;

    // # 1 optimization:
    if (x == 0 && y-1 > 0 && y+1 < grid->size()){
        if(grid->at(x).at(y-1) != 1 && grid->at(x).at(y+1) != 1){
            return;
        }
    }
    // # 2 optimization:
    // the first move is always down or right, so two paths are 
    // exactly symmetric, so we move just right(or down)
    // and the answer * by 2
    if (x == 0 && y == 0){
        calculate_paths_optim(grid, x, y+1, count);
        return;
    }
    if (y-1 > 0 && x+1 < grid->size() && x-1 > 0){
        if(grid->at(x).at(y-1) == 1 && grid->at(x+1).at(y) == 0 && grid->at(x-1).at(y) == 0){
            return;
        }
    }
    else if (y+1 > grid->size() && x+1 < grid->size() && x-1 > 0){
        if(grid->at(x).at(y+1) == 1 && grid->at(x+1).at(y) == 0 && grid->at(x-1).at(y) == 0){
            return;
        }
    }
    grid->at(x).at(y) = 1;
    calculate_paths_optim(grid, x,  y+1, count); //right
    calculate_paths_optim(grid, x, y-1, count); // left
    calculate_paths_optim(grid, x+1, y, count); // down
    calculate_paths_optim(grid, x-1, y, count); // up
    grid->at(x).at(y) = 0;
}
void calculate_paths_backtracking(vi *grid, int x, int y, int *count){
    if (x < 0 || y < 0 || x >= grid->size() || y >= grid->size()) return;
    if (x == grid->size()-1 && y == grid->size()-1 && check_all_cells(grid)) {
        *count = *count + 1;
        return;
    }
    if (grid->at(x).at(y) == 1) return;

    grid->at(x).at(y) = 1;
    calculate_paths_backtracking(grid, x,  y+1, count); // right
    calculate_paths_backtracking(grid, x, y-1, count); // left
    calculate_paths_backtracking(grid, x+1, y, count); // down
    calculate_paths_backtracking(grid, x-1, y, count); // up
    grid->at(x).at(y) = 0;

}

int calculate_paths_recursive(vi *grid, int x, int y){
    if (x < 0 || y < 0 || x >= grid->size() || y >= grid->size()) return 0;
    if (grid->at(x).at(y) == 1) return 0;
    if (x == grid->size()-1 && y == grid->size()-1) return 1;

    vi array(grid->size());
    copy_array(grid, &array);
    array.at(x).at(y) = 1;
    return calculate_paths_recursive(&array, x+1, y) + 
           calculate_paths_recursive(&array, x, y+1) + 
           calculate_paths_recursive(&array, x-1, y) + 
           calculate_paths_recursive(&array, x, y-1);
}

int main () {
    int n, res=0;
    std::cin >> n;

    vi grid(n);
    fill_grid(&grid, n);
    /* grid.at(0).at(0)=1; */
    calculate_paths_optim(&grid, 0, 0, &res);
    calculate_paths_backtracking(&grid, 0, 0, &res);
    std::cout << res << "\n";

    return 0;
}
