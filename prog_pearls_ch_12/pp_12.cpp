#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

/* 
From Bentley, J., Programming Pearls, 2nd Ed.
Ch 12
Generate a sorted list of m random ints from a list of length n. 
No duplicates in output.
m < n. E.g. m=20, n=200.
*/

/*
My first solution: generate list of n ints, random shuffle, then sort and
 output the first n.


void shuffle(std::vector<int>& v)
{
  int size = v.size();
  for (int i = 0; i < size; i++)
  {
    int r = randint(0, size); // we are given this function, returns random int
                              //  in range [i, j) 
    std::swap(v[i], v[r]);
  }
}

int main()
{
  int m = 20;
  int n = 200;

  std::vector<int> vec;
  // Fill vec with ascending ints
  // (std::fill is what we want? Or is it std::iota??)
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    vec.push_back(i);
  }
  shuffle(vec);
  // TODO implement quicksort in another exercise
  std::sort(vec.begin(), vec.begin() + m);
  // Output first m ints
}
*/

// Assuming rand() result is only up to 15 bits. bigrand() combines 2 rands()
int bigrand()
{
  int r = rand() & 0x7fff; // 15 bits
  r |= ((rand() & 0x7fff) << 15);
  return r;
}

// Knuth's Algorithm S is much better! We pick numbers based on probability.
void knuth_s()
{
  int m = 20;
  int n = 200;

  int select = m;
  int remaining = n;
  for (int i = 0; i < n; i++)
  {
    if ((bigrand() % remaining) < select)
    {
      std::cout << i << "\n";
      select--;
    }
    remaining--;
  }
}

// How about:
// Pick number at random, then check if already used? Could have nasty complexity.
// Jump a random number of elements each time, jump again if used (set element to -1)

// Here is the set-based algorithm: 
void set_based()
{
  int m = 20;
  int n = 200;

  std::set<int> s;
  for (int i = 0; i < m; i++)
  {
     int r = 0;
     do
     {
       r = bigrand() % n;
     } 
     while (!s.insert(r).second); // keep trying until we successfully insert
  }
  /*
  // Jon Bentley's implementation of the above loop is so much better:
  while (s.count() < m)
  {
    s.insert(bigrand() % n);
  }
  */

  // Output the sorted m ints: set is sorted already :)
  // clang requires -std=c++11
  for (int i : s)
  {
    std::cout << i << "\n";
  }
}

int main()
{
  set_based();
}


