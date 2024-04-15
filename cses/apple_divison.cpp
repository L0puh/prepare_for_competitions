#include <bits/stdc++.h>
#include <vector>


typedef long long ll;
long solve(std::vector<long long> a, int index, ll g1, ll g2){
   if (index == a.size())
      return std::abs(g1 - g2);
   ll to_g1 = solve(a, index+1, g1+a[index], g2);
   ll to_g2 = solve(a, index+1, g1, g2+a[index]);
   return std::min(to_g1, to_g2);
}

int main() {
   int n, index = 0;
   scanf("%d", &n);
   std::vector<long long> apples(n, 0);
   long long g1, g2, sum = 0;
   for (int i = 0; i != n; i++)
      scanf("%lld", &apples[i]);
   long ans = solve(apples, 0, 0, 0);
   printf("%ld\n", ans);
}
