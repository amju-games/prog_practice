/*
https://projecteuler.net/problem=24

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

/*
Using this algorithm, from Wikipedia
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.

Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
Find the largest index l such that a[k] < a[l]. Since k + 1 is such an index, l is well defined and satisfies k < l.
Swap a[k] with a[l].
Reverse the sequence from a[k + 1] up to and including the final element a[n].

*/

#include <iostream>

void swap(int& i, int& j)
{
  //std::cout << "Swapping " << i << " with " << j << "\n";
  int t = i;
  i = j;
  j = t;
}

void reverse(int* first, int* last)
{
  int n = (last - first) / 2;
  for (int i = 0; i < n; i++)
  {
    swap(*(first + i), *(last - i - 1));
  }
}

bool next_perm(int* first, int* last)
{
  // Empty?
  if (first >= last)
  {
    return false;
  }

  int* k = last;
  k--;

  // Seek from end to find largest index k such that a[k] < a[k + 1].
  while (k > first)
  {
    k--;
    //std::cout << "Considering pair: " << *k << " and " << *(k - 1) << "\n";
    if (*k < *(k + 1))
    {
      //std::cout << "Found k=" << *k << ", now find L such that a[k] < a[L]..\n";
      int* L = last;
      L--;
      while (L >= first)
      {
        if (*k < *L)
        {
          //std::cout << "Found L=" << *L << ". Now swap k and L, and reverse from k+1 to the end.\n";
          swap(*k, *L);
          reverse(k + 1, last);
          return true;
        }
        L--;
      }
    }
  }

  return false;
}

void print(int* first, int* last)
{
  while (first < last)
  {
    std::cout << *first;
    first++;
  }
  std::cout << "\n";
}

int main()
{
  int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int n = 0;
  do 
  {
    n++;
    if (n == 1e6)
    {
      std::cout << n << ":\t";
      print(arr, arr + 10);
    }
  }
  while (next_perm(arr, arr + 10));
}


