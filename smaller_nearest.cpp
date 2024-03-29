#include <bits/stdc++.h>

#include "utils.h"
std::vector<int> array = {1, 6, 4, 10, 2, 5, 3};

int main() {
   int start = 0;
   std::vector<int> res;
   std::stack<int> st;
   for (int i = 0; i != array.size(); i++){
      while(!st.empty() && st.top() >= array[i])
         st.pop();
      if (st.empty()) 
         res.push_back(0); // there is no smallest element 
      else {
         printf("[%d]ADD:  %d\n",i, st.top());
         print_stack(st);
         res.push_back(st.top());
      }
      st.push(array[i]);
   }
   putchar('\n');
   for (auto& c: array)
      printf("%d ", c);
   putchar('\n');

   for (auto& c: res)
      printf("%d ", c);

   putchar('\n');
   return 0;
}
