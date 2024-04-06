#include <bits/stdc++.h>
#include <utility>
#include <vector>

std::vector<int> array = {3, 2, 4};
int x = 9;
const size_t size = 9+1;

/*******************************/

/* can we find this sum after all? */

bool is_exists(int n){
   std::bitset<size> can;
   can[0] = 1; // we can sum 0 from empty array
   std::cout << can << '\n';
   for (int i = 0; i != array.size(); i++){
      can |= (can << array.at(i)); // 
      std::cout << can << "\n";
   }
   return can[n];
}

/*******************************/

void print_vec(std::vector<int>::iterator b, std::vector<int>::iterator e){
    printf("SUB: ");
    while(b != e){
        printf("%d ", *b);
        b++;
    }
    printf("\n");
}
std::pair<int, int> sub_sum(int x){
    std::pair<int, int> ans;
    int sum = array[0];
    for (int start = 0, j = 1; j <= array.size(); j++){
        while(sum > x && start < j-1){ // sum exceeded
            sum -= array[start];
            start++;
        }
        if (sum == x){
            return {start, j};
        }
        if (j < array.size())
            sum += array[j];

        print_vec(array.begin()+start, array.begin()+j+1);
        printf("SUM: %d\n\n", sum);
    }
    return {0,0};
}

int main(){
    std::pair<int, int> res = sub_sum(x);
    puts(is_exists(x) ? "we can!" : "we can't");
    printf("%d %d\n", res.first, res.second);

}
