#include <bits/stdc++.h>
#include <vector>


std::vector<int> nums = {1, 5, 7, 8, 2, 4, 9};

int main(){
    int x =  7;
    std::cin >> x;
    std::sort(nums.begin(), nums.end());
    int start=0, end = nums.size()-1;
    int sum = nums[start] + nums[end];
    if (nums[end]+nums[end-1] < x) {
        printf("invalid\n");
        return 1;
    }
    for (start=0; start <= nums.size(); start++){
        while(sum > x) {
            if (end-1 <= start) break;
            end--;
            sum = nums[start] + nums[end];
            printf("+ s: %d e: %d sum: %d\n", start, end, sum);
        }
        if (start < nums.size()){
            sum = nums[start] + nums[end];
        }
        if (sum == x) {
            printf("ANS: %d %d\n", nums[start], nums[end]);
            return 0;
        }
        printf("s: %d e: %d sum: %d\n", start, end, sum);
        
    }
    printf("NO SOLUTIONS\n");
    return 1;

}
