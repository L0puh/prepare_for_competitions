#include <bits/c++io.h>
#include <iostream>



int solution2(int n){
    int ans[n+1];
    
    for (int i = 0; i != n+1; i++)
        ans[i]=0;

    ans[0] = 1;

    for (int i = 0; i < n; i++){
        if (i + 1 <= n ) ans [i+1] += ans[i];
        if (i + 2 <= n) ans[i+2] += ans[i];
    }
    return ans[n];
}

int solution1(int n){
    //mine
    int jumps[n];

    jumps[0] = 1;
    jumps[1] = 2;

    for (int i = 2; i != n; i++){
        jumps[i] = jumps[i-1] + jumps[i-2];
    }
    return jumps[n-1];
}


int main() {
    int n;
    std::cin >> n;

    printf("%d %d\n", solution1(n), solution2(n));

}
