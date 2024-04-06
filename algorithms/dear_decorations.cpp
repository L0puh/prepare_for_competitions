#include <bits/stdc++.h>


int solve(int n, int a, int b){

    // optimization 
    if (a == 0) return (b/n);
    if (b == 0) return (a/n);

    int ans = 0;
    for (int x = 0; x <= a; x++){
        for (int y = b; y >= 0; y--){
            if (x+y >= n && (x+y) % n == 0 && (x+y) > 0){
                /* printf("R: %d %d\n", x, y); */
                ans++;
            }
        }
    }
    return ans;
}


int main(){
    int t, n, a, b;
    std::cin >> t;
    for (int i = 0; i != t; i++){
        std::cin >> n >> a >> b;
        printf("%d ", solve(n, a, b));
        printf("%d\n", std::max(0, a+b-n+1));
    }
    return 0;
}
