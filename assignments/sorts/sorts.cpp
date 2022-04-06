#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

using namespace std;


//This function will print the vector
void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a, int start_index, int stop_index)
{
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a)
{
    int i,min_index,j,tmp;
    int len = a.size();
    // loop through the vector from 0 to end
    for (i=0;i<len; i++)
    {
        // find the smallest value from i to the end
        min_index = find_min_index(a,i,len);

        // swap it into position i
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;

    }
    return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() &&
	 r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }
  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
  return merged;
}

/**
 * Divide the vector into two part and sort the two part
 * seperately. then combine them in a sorted form.
*/
std::vector<int> msort(std::vector<int> v)
{
    std::vector<int> result;
    std::vector<int> left;
    std::vector<int> right;
    if(v.size() < 2)
    {
        return v;
    }
    else{
            int evenSize = v.size()/2;
            for (int i = 0; i < evenSize; i++)
            {
                left.push_back(v[i]);
            }
            for (int i = evenSize; i < v.size(); i++)
            {
              right.push_back(v[i]);
            }
            left = ssort(left);
            right = ssort(right);
            result = merge(left, right);
     }
    return result;
}

std::vector<int> qsort(std::vector<int> list){

  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select a pivot value.
  // for now, just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }

  list[i] = pivot;
  i++;

  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}

/*
Choose the median value of the list as the pivot point\
test it on he sorted data set with the qsort
*/
/*Got the source code from "The polyglot developer"
https://www.thepolyglotdeveloper.com/2019/04/sort-vector-integers-quicksort-algorithm-cpp/
*/
int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void qsort2(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        qsort2(values, left, pivotIndex - 1);
        qsort2(values, pivotIndex, right);
    }

}

void print_help(char *command_name){
  std::cout << "Usage: "<< command_name;
  std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
  std::cout << " -m MAX_ELEMENT_SIZE\n";
  std::cout << " -s DATA_SET_SIZE\n";
  std::cout << " -a[s|m]: s - selection, m - merge\n";
}




extern char *optarg;

int main(int argc, char *argv[])
  {
    int size = 20; // default vector size
    int max_val = 100; // default max value for entries

    char algorithm = 's' ; //default to selection sort
    bool print = false; // do we print before and after sorting?
    char c;


    while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){

      switch (c) {
      case 'h' :
	print_help(argv[0]);
	exit(0);
	break;
      case 'p' :
	print = true;
	break;
      case 's' :
	size = std::stoi(optarg);
	break;
      case 'm' :
	max_val = std::stoi(optarg);
	break;
      case 'a':
	algorithm = optarg[0]; // or *optarg
      }
    }

    srand(time(nullptr));
    //std::vector<int> a = {};
    std::vector<int> a(size);
    int i;
    for (i=0;i<size; i++){
      a[i] = rand()%max_val;
    }


    if (print) {
      print_vector(a);
      std::cout << "\n";
    }

    std::cout << "Starting the sort!\n";
    struct timeval tp;

    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's'){
      a = ssort(a);
    } else if (algorithm == 'm'){

      a = msort(a);
    } else if (algorithm == 'q'){
      a = qsort(a);
    }
    else if(algorithm == 'r'){
       qsort2(a, 0, a.size()-1);
    }


    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;

    if (print) {
      print_vector(a);
    }
    std::cout << "Algorithm: " << algorithm << "\n";
    std::cout << "Time: " << elapsed << "\n";

    return 0;
  }

