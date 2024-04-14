#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int main() {
   std::ios::sync_with_stdio(0);
   std::cin.tie(0);
   std::string n;
   std::cin >> n;
   std::sort(n.begin(), n.end());
   std::vector<std::string> ans;
   ans.push_back(n);
   while (std::next_permutation(n.begin(), n.end())){
      ans.push_back(n);
   }
   printf("%zu\n", ans.size());
   for (auto& i: ans) printf("%s\n", i.c_str());


}
