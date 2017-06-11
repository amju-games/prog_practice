#include <iostream>
#include <string>

using namespace std;
  
void find_longest_substr(const string& s1, const string& s2)
{
  int len1 = (int)s1.size();
  int len2 = (int)s2.size();
  int best = 0;
  for (int i = 0; i < len1; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      // If chars in s1 and s2 match, iterate over both strings
      //   to check the next char is in both strings, etc
 
      int ii = i; // Copy of i and j, which we iterate for as long as
      int jj = j; //  the substrings in s1 and s2 match

      int num_same = 0;
      while (ii < len1 && jj < len2 && s1[ii] == s2[jj])
      {
        num_same++;
        ii++;
        jj++; 
      }
      if (num_same > best)
      {
        best = num_same;
      
        std::cout << "Best so far: " 
          << i << "-" << ii << ", "  // range in s1
          << j << "-" << jj << ": "  // range in s2
          << s1.substr(i, ii - i) << ", "  // string in s1
          << s2.substr(j, jj - j) << "\n";  // string in s2
      }
    }
  }
}


int main()
{
  string s1("abcdef0123zabc");
  string s2("xyzzabc");

  find_longest_substr(s1, s2);
}


