#include <bits/stdc++.h>
#include <climits>
#include <map>
#include <vector>

/* using namespace std; */

#define BN begin 
#define EN end 
#define F first 
#define S second 

struct City {
    int number;
    int cost;
};

typedef std::multimap<int, City> map;
typedef std::pair<int, int> pair;

void print_map(map m){
    for (auto& i: m){
        printf("%d->%d(%d)\n", i.F, i.S.number, i.S.cost);
    }
}
int max_angel(map m, int n, int *max){
    int j=2, max_j;
    for(; j != n; j++){
        if (m.count(j) > *max){
            *max = m.count(j);
            max_j = j;
        }
    }
    return max_j;
}
bool is_exists(std::vector<int> p, int i){
    for(auto v: p) {
        if( v == i) return true;
    }
    return false;
}
int min_cost( map::iterator b, int end, std::vector<int> *done, int m){
    int min = INT_MAX; 
    int a = b->F;
    for(int i = 1; i <= end; i++){
        if (is_exists(*done, b->S.cost)) continue;
        printf("process... n: %d cost: %d from %d\n", b->S.number, b->S.cost, a);
        if (b->S.cost < min){
            min = b->S.cost;
        }
        b++;
    }  
    done->push_back(min);
    return min;
}
int main(){
    int n, k, x, y;
    std::cin >> n >> k;
    map cities;
    for (int i = 2; i <= n; i++){
        std::cin >> x >> y;
        cities.insert({x, {i, y}});
    }
    int max = 0; 
    int m = max_angel(cities, n, &max);
    City city = cities.find(m-1)->second;
    auto cnt = cities.find(m);
    int ans = max + 1, cost=city.cost;
    for(; cnt != cities.end() ; cnt++){
        printf("n: %d cost %d \n", cnt->S.number, cnt->S.cost);
        cost += cnt->S.cost;
    }
    printf("MAX CITY: %d cost %d\n", m, cnt->S.cost);
    if (y == 0) {
        printf("%d %d\n", ans+1, 0);
        return 0;    
    } 
    std::vector<int> done = {cnt->F};
    int c = 1, prev = -1;
    while (c < k){
        for(int i = 1; i != n-1; i++){
            auto node = cities.find(i);
            if (node->F == m) continue;
            if (cities.count(i) > 0){
                prev = min_cost(node, cities.count(i), &done, prev);
                cost+=prev;
            }
        }
        c++;
    }

    printf("%d %d\n", ans+c-1, cost);
}

