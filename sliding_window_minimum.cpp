/***********************
  report the smallest
  element in the window
 ***********************/

#include <bits/stdc++.h>

const int slide = 4;
std::vector<int> array = {2, 1, 4, 5, 3, 4, 1, 2};

/* for slide = 4
   2 1 4 5 -> 1
   1 4 5 3 -> 1
   4 5 3 4 -> 3
   5 3 4 1 -> 1
   3 4 1 2 -> 1
*/




int main()
{
   std::stack<int> st;
   int win = slide-1, j=0;
   st.push(array[0]);
   for (int i=1; i != array.size(); i++){
      while(!st.empty() && i < win && array[i] < st.top())
         st.pop();

      if (st.empty() || array[i] < st.top())
         st.push(array[i]);

      if (i == win && !st.empty()){
         printf("%d ", st.top());
         j++;
         win++;
         i=j;
         if (array[i-1] == st.top())
            st.pop();
      }
   }
   putchar('\n');
   return 0;
}
