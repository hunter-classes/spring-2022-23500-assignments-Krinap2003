#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include "sorts.cpp"


/**
 * Return the amount of tiem the values appears in the vector
*/
int count(std::vector<int> v, int value)
{
  int result = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] == value)
    {
      result++;
    }
  }
  return result;
}


/**
 * Return the largest values in the vector
*/
int largest(std::vector<int> v)
{
  int result = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] > result)
    {
      result = v[i];
    }
  }
  return result;
}

/**
 * Return the most frequently appeared value in the vector
*/
int mode(std::vector<int> v)
{
  int max = 0;
  int result=0;
  int freq = 0;

  for(int i = 0; i < v.size(); i++)
  {
      freq = count(v, v[i]);
      if(freq > max)
      {
        max = freq;
        result = v[i];
      }
  }
  return result;
}

/**
 * Return the most frequently appeared value in the vector using the 
 * memoization technique
*/
int mode2(std::vector<int> v)
{
    int large = largest(v);
    int arr[large];
    for(int i = 0; i < large; i++)
    {
        arr[i] = 0;
    }
    int max = 0;
    int index = 0;
    for(int i = 0; i < v.size(); i++)
    {
        arr[v[i]] += 1;
    }
    for(int i = 0; i < large; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            index = i; 
        }
    }
    return index;
}
