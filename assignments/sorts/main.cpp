 #include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include "sorts.h"

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

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting ssort\n";
  std::cout<<"---------------------------\n";
  std::cout<<"Original Vector\n";
  print_vector(a);
  std::cout<<"\nSorted Vector\n";
  a = ssort(a);
  print_vector(a);

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting merge\n";
  std::cout<<"---------------------------\n";
  std::cout<<"Original Vecotr\n";
  std::vector<int> left = {1,2,5,6,10,15};
  std::vector<int> right = {3,7,8,12,16,19,20};
  print_vector(left);
  print_vector(right);
  std::vector<int> m = merge(left,right);
  std::cout<<"Sorted Vector\n";
  print_vector(m);

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting msort\n";
  std::cout<<"---------------------------\n";
  std::cout<<"Even Size\n";
  std::vector<int> v1 = {33,43,24,55,10,9};
  std::vector<int> resultMsort = msort(v1);
  std::cout<<"Original Vector\n";
  print_vector(v1);
  std::cout<<"Sorted Vector\n";
  print_vector(resultMsort);

  std::cout<<"\nOdd Size\n";
  std::vector<int> v2 = {33,43,24,55,10,3,-1};
  std::vector<int> resultMsort2 = msort(v2);
  std::cout<<"Original Vector\n";
  print_vector(v2);
  std::cout<<"Sorted Vector\n";
  print_vector(resultMsort2);

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting count\n";
  std::cout<<"---------------------------\n";
  std::vector<int> v3 = {1,4,1,9,0,3,-1};
  int x = count(v3, 1);
  std::cout<<"Original vector: ";
  print_vector(v3);
  std::cout<<"1's in the vection = "<<x<<"\n";
  size = 10;
  std::vector<int> v6(size);
  for (int i=0;i<size; i++){
    v6[i] = rand()%max_val;
  }
  x = count(v6, 2);
  std::cout<<"Original vector: ";
  print_vector(v6);
  std::cout<<"2's in the vection = "<<x<<"\n";

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting largest\n";
  std::cout<<"---------------------------\n";
  int size2 = 10;
  std::vector<int> v4(size2);
  for (int i=0;i<size2; i++){
    v4[i] = rand()%max_val;
  }
  int y = largest(v4);
  std::cout<<"Original vector: ";
  print_vector(v4);
  std::cout<<"The largest values in the vector = "<<y<<"\n";

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting mode\n";
  std::cout<<"---------------------------\n";
  std::vector<int> v5 = {1,62,4,60,8,62,62,60,60,12,6,22};
  int z = mode(v5);
  std::cout<<"Original vector: ";
  print_vector(v5);
  std::cout<<"The most frequesnt value in the vector = "<<z<<"\n";

  size=20;
  max_val=100;
  std::vector<int> b(size);
  for (int i=0;i<size; i++){
    b[i] = rand()%max_val;
  }
   z = mode(b);
  std::cout<<"Original vector: ";
  print_vector(b);
  std::cout<<"The most frequent value in the vector = "<<z<<"\n";

  std::cout<<"\n---------------------------";
  std::cout<<"\nTesting mode2\n";
  std::cout<<"---------------------------\n";
  std::vector<int> newMode2 = {1,2,2,2,1,6,1,2,1,2,2,2};
  int n = mode2(newMode2);
  int k = mode(newMode2);
  std::cout<<"Original vector: ";
  print_vector(newMode2);
  std::cout<<"The most frequent value in the vector with mode2: "<<n<<"\n";
  std::cout<<"The most frequent value in the vector mode: "<<k<<"\n";


  size=10000000;
  max_val=100;
  std::vector<int> c(size);
  for (int i=0;i<size; i++){
    c[i] = rand()%max_val;
  }
  z = mode2(c);
  //int h = mode(c);
  std::cout<<"Original vector: ";
  //print_vector(c);
  std::cout<<"The most frequent value in the vector with mode2: "<<z<<"\n";
  //std::cout<<"The most frequent value in the vector mode: "<<h<<"\n";

  return 0;
}
