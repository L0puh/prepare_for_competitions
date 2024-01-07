#include <bits/stdc++.h>

typedef std::vector<int> vi;

// using meet in the middle on sorted array
void sub_sum(vi *array){
    array->push_back(0);
    int size = array->size();
    for(int i = 0; i != size;i++){
        if (i + 1 == size) break;
        array->push_back(array->at(i)+array->at(i+1));
    }
}

bool search(int x, vi array){
    vi A, B;
    int mid = array.size() / 2;   
    A.insert(A.end(), array.begin(), array.begin()+mid);
    B.insert(B.end(), array.begin()+mid, array.end());
    sub_sum(&A);
    sub_sum(&B);
    for (int i = 0; i != A.size(); i++){
        for (int j = B.size()-1; j >= 0; j--){
            if(A.at(i) + B.at(j) == x || A.at(i) == x || B.at(j) == x)
                return true;
        }
    }
    return false;
}
int main(){
    vi array = {2, 4, 9};
    int x = 10;
    std::cin >> x;
    printf("%d\n", search(x, array));

}
