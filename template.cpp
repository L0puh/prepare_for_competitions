#include <bits/stdc++.h>

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
}
