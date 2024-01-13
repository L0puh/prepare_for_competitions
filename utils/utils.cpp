#include "utils.h"

void print_array(int array[], int sz){
   for (int i = 0; i != sz; i++)
         printf("%d ", array[i]);
   putchar('\n');
}

void print_stack(std::stack<int> temp){
   int size = temp.size();
   printf("STACK: ");
   for (int i =0; i!= size; i++){
      printf("%d ", temp.top());
      temp.pop();
   }
   putchar('\n');
}

void print_vector(std::vector<int>::iterator st,
                  std::vector<int>::iterator end)
{
   for(; st != end; st++){
      printf("%d ", *st);
   }
   putchar('\n');
}
