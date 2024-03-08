#include <bits/stdc++.h>
#include <cstdio>

int main (){
   int a, b;
   FILE* fp =  freopen("sum.in", "r", stdin);
   scanf("%d %d", &a, &b);
   freopen("sum.out", "w", stdout);
   printf("%d\n", a+b);

   return 0;
}
