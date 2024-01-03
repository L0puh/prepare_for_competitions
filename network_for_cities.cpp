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
pair max_angel(map m, int n){
    int j=2, max=0, max_j;
    for(; j != n; j++){
        if (m.count(j) > max){
            max = m.count(j);
            max_j = j;
        }
    }
    return {max_j, max};
}
bool is_exists(std::vector<int> p, int i){
    for(auto v: p) if( v == i) return true;
    return false;
}
int min_cost(std::vector<int> p, map::iterator m, map::iterator end){
    int min = INT_MAX; 
    if(!is_exists(p, m->F)){
        for(; m != end; m++){
            if (m->S.cost > min) 
                min = m->S.cost;
        }
    }
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
      
    pair m = max_angel(cities, n);
    City city = cities.find(m.F)->second;
    auto cnt = cities.find(m.F);
    int ans = m.S, cost=city.cost;

    for(; cnt != cities.end(); cnt++){
        cost += cnt->S.cost;
    }
    std::vector<int> processed = {m.F};

    // Djkstra algorithm??
    /* while(ans <= k){ */
        for (int i = 1; i!= n; i++){
            if (i == m.F) continue;
            cost += min_cost(processed, cities.find(i), cities.find(i+1));
            processed.push_back(i);
            ans++;
        }
    /* } */

    printf("%d %d\n", ans, cost);
    /* print_map(cities); */
}

