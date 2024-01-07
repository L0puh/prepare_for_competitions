/***************************** 
    
    sequance  6, 2, 5, 1, 7, 9 
    has length 4 -> 2, 5, 7, 9
    this algorithm using DP and
    recursive finds this length

 ****************************/

#include <bits/stdc++.h>
#include <vector>

#define OPTIMIZE std::ios::sync_with_stdio(0); std::cin.tie(0)

/* int sz = 7; */
/* int list[6] = {6, 2, 5, 1, 7, 9}; */
/* int done[6]; */

int sz = 4;
int list[4] = {0, 2, 1, 5};
int done[4];
int first = 0;
std::vector<int> solution;

void longest_recurisive(int index, int *res){
    // DOESNT NOT PROPERLY. fix?
    if (index+1 >= sz) return;
    if (done[index]) return;
    if (list[index] < list[index+1]){
        if (first == 0) {
           first = list[index];
           solution.push_back(list[index]);
        }        
        done[index] = 1;
        *res = *res + 1;
        solution.push_back(list[index+1]);
        return;
    }  
    for (int i = index; i != sz; i++){
        longest_recurisive(i+1, res);
    }
}
void recursive(){
    int res=1;
    longest_recurisive(0, &res);
    for (int i = 0; i != res; i++){
        printf("%d ", solution[i]);
    }
    std::cout << "\n" << res << "\n";
    printf("\n");
}
int longest_dp(){
    int ans = 1, max = 0, index;
    for (int i = 0; i != sz; i++ ){
        ans = 1;
        index = i;
        for (int j = i+1; j != sz; j++){
            if (list[index] < list[j]){
                ans++; 
                index = j;
            } 

        } if (max < ans ) max = ans; 
    }
    return max;
}
void DP(){
    std::cout << longest_dp();
    printf("\n");
}
int main(){
    OPTIMIZE;
    DP();
    recursive();
}
