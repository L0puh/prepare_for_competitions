#include <bits/stdc++.h>

// constants for DP recurisive
int done[10000]; // should be N size
int value[1000];
int result[1000];
int solution[100];
int sz = 8;
int list[8] = {1, 2, 5, 10, 20, 50, 100, 200};
float INF = 10000000;
std::vector<int> res;


// count the optimal solution
// for n = 3 => 2 + 1 => 2 coins
int DP_rec(int x){
    
    if (x < 0)    return INF;
    if (x == 0)   return 0;
    if (done[x]) return value[x];
    int best = INF; 
    for(int i = 0; i != sz; i++){
        best = std::min(best, DP_rec(x-list[i])+1);
    }
    done[x] = true;
    value[x] = best;

    return best;
}

int DP_iterative(int n){
    int val[n], res[n];
    val[0] = 0;
    for (int solution=1; solution <= n; solution++){
        val[solution] = INF;
        for (int coin=0; coin != sz; coin++){
            if (solution - list[coin] >= 0 && val[solution-list[coin]]+1 < val[solution]){
                val[solution] = std::min( val[solution], val[solution-list[coin]]+1);
                res[solution] = list[coin];
            }
        }

    }
    // construct the optimal solution
    for (int i = n; i > 0; ){
        printf("%d ", res[i]);
        i-=res[i];
    }
    printf("\n");
    return val[n];
}

int greedy(int n, int list[], int sz){
    int max = 0, count = 0;
    int i = sz-1;
    for (; i != 0; --i){
        if (n > list[i] || n == list[i] ) break; 
    }
    max = list[i];
    printf("%d ", max);
    while (max < n && i != 0) {
        for (int j = i; j >= 0; j--){
            if (list[j] + max <= n){
                max += list[j];
                printf("%d ", list[j]);
                count++;
                break;
            }
        }
    }
    printf("\n");
    return count; 
}


// count the amount of ways to get N
// such as for n = 3:
// 1 + 1 + 1
// 1 + 2 
// 2 + 1
int DP_count(int n){
    int val[n];
    std::fill(val, val+n, 0);
    val[0] = 1;
    val[1] = 2;
    for(int i = 2; i <= n; i++){
        for (int coin = 0; coin != sz; coin++){
            if (i - list[coin] >= 0){
                val[i] += val[i-list[coin]];
            }
        }
    }
    return val[n-1];
}
int main(){
    int n = 0;
    std::cin >> n;
    std::cout << DP_count(n);
}
