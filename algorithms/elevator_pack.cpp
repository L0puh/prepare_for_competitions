/******************

finds the minimum
number of rides
in elevator with x weigth
for n persons

algorithm: 
decreasing best fit
****************/

#include <bits/stdc++.h>
#include <vector>

std::vector<int> weights = {2, 3, 3, 5, 6, 5, 3, 3};
const int persons = weights.size();
const int elevator = 10; // maximum weight of elevator

int get_optimal(){
   //gets the lower bound
   int s = 0;
   for (int i=0; i != persons; i++)
      s+=weights[i];
   return (s / elevator)+1;
}
void print_rides(std::vector<int> rides[]){
   int opt = get_optimal();
   for (int i = 0; i != opt; i++){
      printf("%d: ", i+1);
      for (auto& r: rides[i]){
         printf("%d ", r);
      }
      putchar('\n');
   }
}
int calculate_rides(){
   int remaning[persons]; //remaning space
   int j, rides, i, min, best;
   rides = 0;
   std::vector<int> solution[get_optimal()];
   for (i = 0; i < persons; i++){
      best = 0;
      min = elevator + 1; //minimum space left

      //find if there is a space to enter
      for (j = 0; j < rides; j++){

         // if there is a space for i-th weigth and
         // this space less than left space:
         if (remaning[j] >= weights[i] && remaning[j] - weights[i] < min){
            best = j; // index there you can put a person
            min = remaning[j] - weights[i];
            solution[best].push_back(weights[i]);
         }
      }
      // can't put anybody, create new ride
      if (min == elevator+1){
         remaning[rides] = elevator - weights[i];
         solution[rides].push_back(weights[i]);
         rides++;
      }
      else remaning[best] -= weights[i]; // enter a person
      
   }
   print_rides(solution);
   return rides;
}


int main(){
   std::sort(weights.rbegin(), weights.rend());
   printf("RIDES: %d, OPTIMAL: %d\n", calculate_rides(), get_optimal());
}
