#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>

#define B begin() 
#define E end() 

std::vector<int> quick_sort(std::vector<int> v){
    if (v.size() < 2) return v;
    std::vector<int> greater, lower, s, n;

    int pivot = v.at(0);
    for (auto& i: v){
        if (i == pivot) continue;
        if(i > pivot) greater.push_back(i);
        else lower.push_back(i);
    }
    if (!lower.empty()){
        s = quick_sort(lower);
    }
    s.push_back(pivot);
    if (!greater.empty()){
        n = quick_sort(greater);
        s.insert(s.E, n.B, n.E);
    }
    return s;
}

int solution1(std::set<int> a, std::set<int> b){
    std::vector<int> z;
    std::set_intersection(a.B, a.E, b.B, b.E, std::back_inserter(z));
    return z.size();
}

int solution2(std::vector<int> a, std::vector<int> b){
    a = quick_sort(a);
    b = quick_sort(b);
    int x = a.size(), y = b.size();
    int cnt=0;
    for (int i = 0; i != x; i++){
        for (int j = 0; j != y; j++)
            if(a.at(i) == b.at(j)) cnt++;
    }
    return cnt;
}

int main(){
    int x, y, n;
    std::cin >> x >> y;
    std::set<int> a, b;
    std::vector<int> c, d;
    for (int i = 0; i != x; i++){
        std::cin >> n;
        a.insert(n);
        c.push_back(n);
    }
    for (int i = 0; i != y; i++){
        std::cin >> n;
        b.insert(n);
        d.push_back(n);
    }

    printf("SOLUTIONS: %d /", solution2(c, d)); 
    printf("%d\n", solution1(a, b));
}
