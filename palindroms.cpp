#include <cstdio>
#include <iostream>
#include <vector>



std::vector<int> sum(std::vector<int> p1, std::vector<int> p2){
    std::vector<int> s(p1.size());
    for (int i = 0; i != p2.size(); i++){
        s[i] = p1[i] + p2[i];
        printf("%d\t", s[i]);
    }
    
    return s; 
}


void change2(std::vector<int> *p1, std::vector<int> *p2){
    std::vector<int> temp;
    
    if (p1->size() < p2->size()) { // p2 is bigger
        for (int i = p1->size(); i != p2->size(); i++)
            temp.push_back(0);
        for (auto& c: *p1)
            temp.push_back(c);
        *p1 = temp;
    }
    else {
        for (int i = p2->size(); i != p1->size(); i++)
            temp.push_back(0);
        for (auto& c: *p2)
            temp.push_back(c);
        *p2 = temp;
    }

}

void change(std::vector<int> *p1, std::vector<int> *p2){

    if (p1->size() < p2->size()) {
        for (int i = p1->size(); i != p2->size(); i++){
            p1->push_back(0);
        }
    }
    else{
        for (int i = p2->size(); i != p1->size(); i++){
            p2->push_back(0);
        }
    }
}

int find_repeated(std::vector<int> s1){
    int cnt = 0;
    for (int j = 0; j != s1.size(); j++){
        int t=s1[j];
        for (int i = j+1; i != s1.size(); i++){
            if (t == s1[i]) cnt++;
        }
    }
    printf("cnt: %d\n", cnt+1);
    return cnt+1;
}

int main() {
    int n, m, t, ans1, ans2;
    std::cin >> n >> m;
    std::vector<int> p1(n), p2(m), t1(n), t2(m);
    for (int i=0; i != n; i++){
        std::cin >> p1[i];
    }
    
    for (int i=0; i != m; i++){
        std::cin >> p2[i];
    }
    t1 = p1, t2 = p2;
    change(&p1, &p2);
    std::vector<int> s1 = sum(p1, p2);
    change2(&t1, &t2);
    printf("\n");
    std::vector<int> s2 = sum(t1, t2);
    printf("\n");
    printf("ANS: %d\n", std::max(find_repeated(s1), find_repeated(s2)));


    return 0;
}
