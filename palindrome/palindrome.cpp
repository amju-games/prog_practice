// j.c. find longest palindrome in a string

#include <iostream>
#include <string>
#include <vector>

// Find longest palindrome in a string.

// I tried doing this recursively, was not fun.

// Another approach: at each index, calculate the length of the pal. ending
//  at this index. E.g.:
// l e v e l p u p
// 1 1 1 3 5 1 1 3
// Can do this in O(n).
std::string pal(const std::string& s)
{
  int best_c = 0; // result: best so far
  int best_i = 0;
  int len = s.length();
  std::vector<int> a { 1 }; // 'array' of lengths of palindrome ending at index
  
  for (int i = 1; i < len; i++)
  {
    // Treat element i as the end of a palindrome. Find the start of that
    //  pal., and add the length to a.
    // j is the index of the start of the palindrome ending at i.
    int j = i - a.back() - 1;
//    std::cout << "i: " << i << " (" << s[i] << ")  j: " << j << "\n";
    int c = 1;
    // Check if s[i] and s[j] are the same. If so, we have found more 
    //  letters in the pal.
    if (j >= 0)
    {
      if (s[i] == s[j])
      {
        c = i - j + 1;
      }
      else
      {
        // Could be a another pal overlapping, or extending another
        // E.g.: 
        // p u p u p
        // 1 1 3 *
        // Value of c at * should be 3
        // OR, we could be at the second of 2 letters in the middle of a
        //  pal, e.g. the 2nd 'l' in:
        // e l l e
        // 1 1 2 4
        if (j > 1 && s[i] == s[i - 2])
        {
          c = 3;
        }
        else if (j > 0 && s[i] == s[i - 1])
        {
          c = 2;
        }
      }
    }
    if (c > 1)
    {
      // Found something
      std::cout << "Found: " << s.substr(i - c + 1, c) << "\n";
    }
    if (c > best_c)
    {
      best_c = c;
      best_i = i;
    }
    a.push_back(c); // add the length of the palindrome ending at this index
//    std::cout << "a[" << i << "]: " << a[i] << "\n";
  }
  std::string s1, s2;
  for (int i = 0; i < len; i++)
  {
    s1.push_back(s[i]);
    s1 += "  ";
    s2 += std::to_string(i) + (i < 10 ? "  " : " ");
  }
  std::cout << s1 << "\n" << s2 << "\n";

  std::cout << "Best c: " << best_c << " Best i: " << best_i << "\n";
  int n = best_i - best_c;
  return s.substr(n + 1, best_c); 
}

int main()
{
  std::cout << pal("puplevellevelenursesrun") << "\n";
}


