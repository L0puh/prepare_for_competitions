#include <bits/stdc++.h>
#include <string>

typedef std::vector<int> vi;  
typedef std::vector<vi>  vv;  // set of subsets 


void util(vi *sub, std::string str){
    printf("for %s\n", str.c_str());
    for (auto s: *sub){
        printf("%d ", s);
    }
    printf("\n");
}

void gen_subs(const vi given_set, vv *res, int index, vi *subset){
    res->push_back(*subset); 
    for (int i = index; i < given_set.size(); i++){
        subset->push_back(given_set.at(i)); 
        gen_subs(given_set, res, i+1, subset);
        subset->pop_back();
    }
}

vv subsets(const vi given_set){
    vv res;
    vi subset;
    gen_subs(given_set, &res, 0, &subset);
    return res;
}

int main(){
    vi set= {0, 1};
    vv s = subsets(set);

    for (int i = 0; i != s.size(); i++){
        for(int j=0; j!=s.at(i).size(); j++){
            printf("%d ", s[i][j]);
        }
        printf("\n");

    }
}

