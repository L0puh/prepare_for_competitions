#include <iostream>
#include <vector>



bool is_palyndrom(std::vector<int> p){
    if (p.size() % 2 != 0){
        for (int i = 0, j = p.size()-1; i != j; i++, j-- ){
            if (p[i] != p[j]) 
                return 0;
            
        }
    } else{
        int mid = p.size() / 2;
        for (int i = 0, j = p.size()-1; i != mid; i++, j-- ){
            if (p[i] != p[j]) return 0;
        }
    }

    return 1;
}

int main(){
    std::vector<int> p =  {3, 2, 5, 2, 3};
    std::vector<int> p2 = {2, 2, 5, 2, 3};
    /* std::vector<int> p3 = {3, 2, 5, 5, 2, 3}; */
    std::vector<int> p3 = {1, 2, 3, 2, 5, 5, 2, 3, 2, 1, 2};
    printf("%d %d %d\n", is_palyndrom(p), is_palyndrom(p2), is_palyndrom(p3) );
    

    return 0;
}
