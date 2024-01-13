#include <bits/stdc++.h>
#include <cstdint>

// g++ -std=c+11 -02 -Wall {name} - compile wich 

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first 
#define S second 
#define PB push_back
#define B begin 
#define E end 
#define MP make_pair
#define LOOP(i, a, b) for (i = a; i<=b; i++)
#define SQ(a) (a)*(a)


struct User {
    string name;
    int age;

    //custom operators 
    bool operator>(const User &u){
        return age > u.age;
    }
    bool operator<(const User &u){
        return age > u.age;
    }
};

bool comp(User u1, User u2){ // or use func instead
    return (u1.name.size() > u2.name.size());
}
int main() {
    int a, b;

    /***************************************************INPUT******************************************************/
    ios::sync_with_stdio(0); // makes efficient input/output
    cin.tie(0);
    
    cin >> a >> b;  
    scanf("%d %d", &a, &b); // faster

    cout << a <<  b;
    printf("%d, %d\n", a, b); // faster

    string x; 
    getline(cin, x); // reads the whole line
    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); // reads input file 
                                        // and put it to output file

    while (cin >> x) {}  // reads every input, forever!

    /***************************************************FLOAT******************************************************/

    // accuratly compare two floats 
    float f0, f1;
    if (abs(f0-f1) < 1e-9) {} //a == b
    printf("%.5f\n", f0);

    /***************************************************SORT******************************************************/
    vi v{2, 4, 1, 2, 5, 2, 4, 6};

    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend()); // reverse 
                                
    int n = 10; // size
    int array[] = {2, 4, 1, 2, 5, 2, 4, 6};
    sort(array, array+n);
    
    string s = "sdf3asd";
    sort(s.begin(), s.end());

    vector<User> u{{"Me", 16}, {"You", 2}};
    sort(u.B(), u.E());       // me, you (by age, using custom operators)
    sort(u.B(), u.E(), comp); // you, me (by name size, using custom function)
                              /* note: pair is sorted by the first element */ 
    

    /***************************************************SEARCH******************************************************/
    /* assumed that the array to be searched is sorted */

    vi::iterator k = lower_bound(v.B(), v.E(), 3); // at least 3
    vi::iterator r = upper_bound(v.B(), v.E(), 3); // larger than 3

    int  j = lower_bound(array, array+n, 3)-array;
    int* j2 = lower_bound(array, array+n, 3);

    //count the number elements with value = 2
    auto a1 = lower_bound(array, array+n, 2);
    auto b1 = upper_bound(array, array+n, 2);
    printf("%ld\n", b1-a1);

    // is there x=4 in the array?
    a = lower_bound(array, array+n, 4)-array;
    if (array[a] == 4) printf("yes\n");


    /***************************************************DATA STRUCTURES******************************************************/
    std::set<int> s1;               // more functions to use, but O(log n)
    std::unordered_set<int> s2;     // efficient O(1)

    std::set<int>::iterator it = s1.find(3);
    if (it == s1.end()) {}          // element was not found
    return 0;
    /***************************************************BITWISES******************************************************/

    int8_t z = 2; // 000 010 
    // counts the num of zeroes at the begining of the number 
    // **** **-> 6  (for 1 byte)
    // 0000 0010 
    cout << __builtin_clz(z) << "\n";
    // counts the num of zeroes at the end of the number 
    //         * -> 1
    // 0000 0010 
    cout << __builtin_ctz(z) << "\n";
    // counts the num of ones in the number
    //        *  -> 1
    // 0000 0010
    cout << __builtin_popcount(z) << "\n";
    // 0 when nums of ones is odd 
    // 1 when even (for 1 of ones is 1)
    cout << __builtin_parity(z) << "\n";

    /***************************************************GRAPHS******************************************************/
   
    // adjacency list 
    int N = 3;
    vector<int> adj[N]; // 
    adj[1].push_back(2); // 1 -> 2 
    adj[2].push_back(1); // 1 <-> 2
    vector<pair<int, int>> weights[N]; // graph wiht weights 
    for (auto& u: adj[1]){
       // process all paths from node 1
    }

    // adjacency matrix (n^2) 
    int M=3;
    int matrix[N][M];
    matrix[1][2] = 1; // 1 -> 2 
    matrix[1][2] = 3; // 1 -> 2 has a weigth 

    // edge list
    vector<pair<int, int>> edges;
    edges.push_back({1, 2}); // 1 -> 2
    vector<tuple<int, int, int>> edges_weighted;
}













