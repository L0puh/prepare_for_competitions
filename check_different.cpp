#include <bitset>
#include <iostream>

int main(){
   // how many different values appear in the sequence?
   int nums[7] = {3, 5, 6, 3, 3, 9, 5};
   
   std::bitset<8> visited;
   for (int i = 0; i != 7; i++){
      visited[nums[i]] = 1;
   }
   std::cout << visited.count() << "\n";
   std::cout << visited << "\n";
}
