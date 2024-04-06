/*FIXME*/


#include <iostream>
#include <vector>
#include "utils.h"

struct pos{
    int b;
    int e;
};



bool is_palyndrom
(std::vector<int>::iterator b, std::vector<int>::iterator e, int sz){
    if (sz < 2) return 0;
    if (sz == 2) if (*b != *e ) return 0;
    if (sz % 2 != 0){
        /* print_vector(b, e); */
        for (; b < e; b++, e--){
            if (*b != *(e-1)) {
                /* print_vector(b, e); */
                /* printf("%d %d\n\n", *b, *(e-1)); */
                return 0;
            }

            /* printf("%d %d\n", *(b+i), *(e-j)); */
        }
    } else {
        int mid = sz / 2;
        for (int i = 0, j = sz-1; i != mid; i++, j--){
            if (*(b+i) != *(e-j)){
                /* printf("%d %d\n\n", *(b+i), *(e-j)); */
                return 0;
            }
        }
    }

    return 1;
}

void print_vector(std::vector<int> p);

void move(std::vector<int> *p, int step, int stop){
    std::vector<int> temp;
    for (int i = 0; i != step; i++){
        temp.push_back(0);
    }
    for (int i = 0; i != stop-step; i++)
    {
        temp.push_back(p->at(i));
    }
    *p = temp;
}

void print_vector(std::vector<int> p){
    for (auto& i: p){
        printf("%d ", i);
    }
    printf("\n");
}

void print_vector(std::vector<int>::iterator b,
                  std::vector<int>::iterator e){
    for(auto i = b; i < e; i++){
        printf("%d", *i);
    }
    printf("\n");
}
void print_vector(std::vector<pos> p){
    for (auto& i: p){
        printf("{%d %d}\n", i.b, i.e);
    }
    printf("\n");
}
std::vector<int> sum(std::vector<int> p1, std::vector<int> p2){
    std::vector<int> s(p1.size());
    for (int i = 0; i != p2.size(); i++){
        s[i] = p1[i] + p2[i];
    }
    return s;
}
void fill(std::vector<int> *p, int size){
    for (int i=p->size(); i < size; i++){
        p->push_back(0);
    }
}


void solve(int n, int m, std::vector<int> *p2, std::vector<int> *p1)
{
    std::vector<pos> ans;
    fill(p2, n);
    for (int k = 0; k != n; k++){
        move(p2, k, n);
        std::vector<int> s(n);
        s = sum(*p1, *p2);
        for (int i = 0; i != n; i++){
            for (int e = i+1; e <= n; e++){
                if (is_palyndrom(s.begin()+i, s.begin()+e, e-i )){
                    ans.push_back({i, e});
                }
            }
        }
    }
    printf("%zu\n", ans.size());
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
    std::vector<pos> ans;
    if (n > m){
        solve(n, m, &p1, &p2);
    }
    else {
        solve(m, n, &p2, &p1);
    }

    return 0;
}
