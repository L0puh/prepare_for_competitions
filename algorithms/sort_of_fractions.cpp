#include <bits/stdc++.h>
#include <utility>
#include <vector>

typedef std::vector<std::pair<int, int>> pair_v;
typedef std::pair<int, int> pair;


float devise(pair i){
    float res = (float)i.first/i.second;
    return res; 
}

pair_v sort(pair_v v){
    if (v.size() < 2) return v;

    pair pivot = v.at(0);
    pair_v greater, lower;

    for (int i=1; i!=v.size(); i++){
        float res = devise(v.at(i));
        if (devise(v.at(i)) > devise(pivot)) 
            greater.push_back(v.at(i));
        else 
            lower.push_back(v.at(i));
    }
    pair_v s; 
    if (!lower.empty()){
        s = sort(lower);
    }
    s.push_back(pivot);
    if (!greater.empty()){
        pair_v s2 = sort(greater);
        s.insert(s.end(), s2.begin(), s2.end());
    }
    return s;

}

pair shorten(pair i){
    if (i.second % i.first == 0 && i.second >= i.first)
        return {ceil((float)i.first/i.second), i.second/i.first};
    else if (i.first > i.second && i.first% i.second== 0)
        return {i.first/i.second, ceil((float)i.second/i.first)};
    return i;
}

int main(){
    int n, q;
    std::scanf("%d %d", &n, &q);

    int n1[n], n2[n], c[q];
    for (int i=0; i!=n; i++)
        std::cin >> n1[i];
    
    for (int i=0; i!= n; i++)
        std::cin >> n2[i];

    for (int i=0; i!= q; i++)
        std::cin >> c[i];

    pair_v frac; 
    for (int i = 0; i != n; i++){
        for (int j = 0; j != n; j++)
            frac.push_back(shorten({n1[i], n2[j]})); // really slow...
    }

    //TODO: 
    /* if (q == 1 and c[q] < 100){ sort_only_lower(100) }; */

    frac = sort(frac);
    for (int i = 0; i != q; i++){
        printf("%d %d\n", frac.at(c[i]-1).first, frac.at(c[i]-1).second);
    }
    return 0;


}
