// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/


#include <cstdio>
#include <vector>
#include <map>
#include <string>

#define INF 1000000
typedef std::vector<std::pair<std::string, int>> neighbor;

std::vector<std::string> processed;
bool is_processed(std::string node){
    for (auto& p: processed)
    {
        if (p == node) return true;
    }
    return false;
}
void update(std::map<std::string, int> costs, int new_cost) {
    for (const auto& c: costs) {
        printf("COST: %d NODE: %s\n", c.second, c.first.c_str());
    }
    printf("NEW COST: %d\n\n", new_cost);


}
std::string find_lowest_cost(std::map<std::string, int> cost){
    int min = INF-1;
    std::string node;
    for (const auto& c : cost){
        if (!is_processed(c.first) and c.second != INF)
            if (c.second < min){
                min = c.second; 
                node = c.first;
            }
    }
    return node;
}

int main(){
    std::map<std::string, neighbor> graph {
        {"0", {{"2", 6}, {"1", 2 }}},
        {"1", {{"3", 5}}}, 
        {"2", {{"3", 8}}},
        {"6", {}},
        {"5", {{"6", 6}}},
        {"3", {{"5", 15}, {"4", 10}}},
        {"4", {{"6", 2}}}
    };
    std::map<std::string, int> costs {
        {"2", 6}, 
        {"1", 2},
        {"3", INF},
        {"4", INF},
        {"5", INF}, 
        {"6", INF}
    };
    std::string node = find_lowest_cost(costs);
    int new_cost = 0;
    while (node != "") {
        int cost = costs[node];
        neighbor neighbors = graph[node];
        for (auto& n: neighbors){
            new_cost = cost + n.second;
            if (new_cost < costs[n.first]){
                costs[n.first] = new_cost;
                update(costs, new_cost);
            }
        }
        processed.push_back(node);
        node = find_lowest_cost(costs);
    }
    for (auto& p:costs){
        printf("0 -> %s: %d\n", p.first.c_str(), p.second); 
    }
    return 0;
}

