#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include "funcs.h"

int main()
{
  int size=20;
  int max_val=100;

  srand(time(nullptr));
  std::vector<int> a(size);
  int i;
  for (i=0;i<size; i++){
    a[i] = rand()%max_val;
  }
  /*
    print_vector(a);
  std::cout << "\n";
  a = ssort(a);
  print_vector(a);
  */
//   std::vector<int> left = {1,2,5,6,10,15};
//   std::vector<int> right = {3,7,8,12,16,19,20};
//   print_vector(left);
//   print_vector(right);
//   std::vector<int> m = merge(left,right);
//   print_vector(m);
std::vector<int> left = {1,2,5,6,10,15};
std::vector<int> v1 = msort(left);
print_vector(v1);
//std::cout<<left.size();"\n";
  return 0;
}
