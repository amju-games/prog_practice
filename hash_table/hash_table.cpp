// j.c. programming practice
// Hash table: map string to int
// (Prog Pearls ch. 15)

#include <fstream>
#include <iostream>

// Prime number is good for hash table size?
// (TODO why is that?)
const int HASH_TABLE_SIZE = 31;

class hash_table
{
public:
  hash_table()
  {
    for (int i = 0; i  < HASH_TABLE_SIZE; i++)
    {
      m_array[i] = nullptr;
    }
  }

  void insert(const char* s)
  {
    // This table is for counting occurrences of words. 
    // So if this word exists already, inc the count.
    // Otherwise, add the new node, with count = 1.
    unsigned int h = hash(s);

    std::cout << "Word: '" << s << "' hash: " << h << "\n";
 
    node* n = m_array[h];
    if (n)
    {
      std::cout << " ..found node(s) in bin:\n";
      // There is at least one node in this bucket
      while (n)
      {
        std::cout << "  " << n->m_str << " " << n->m_count << "\n";

        if (strcmp(n->m_str, s) == 0)
        {
          // Found string, inc count
          n->m_count++;
          std::cout << "  Incremented count of " << n->m_str 
            << " to: " << n->m_count << "\n";

          return;
        }
        n = n->m_next;
      }
      // Reached end of list in this bin, add new node to head of list
      node* new_node = new node(s, 1);
      new_node->m_next = m_array[h];
      m_array[h] = new_node;
    }
    else 
    {
      std::cout << " ..nothing in that bin yet.\n";
      m_array[h] = new node(s, 1);
    }
  }

  unsigned int hash(const char* s)
  {
    // This hash algo from Prog Pearls, p.163.

    // Jon Bentley says this value (31) is a popular choice - similar in Marmalade,
    //  but I think with MULT=33 IIRC

    const unsigned int MULT = 31;

    unsigned int h = 0;
    while (*s)
    {
      h = h * MULT + *s;
      s++;
    }    
    return h % HASH_TABLE_SIZE;
  }

private:
  struct node
  {
    node(const char* s, int count)
    {
      int size = strlen(s);
      m_str = (char*)malloc(size + 1);
      strcpy(m_str, s); // dest, src
      m_count = count;
    }

    char* m_str = nullptr;
    int m_count = 0;
    node* m_next = nullptr;
  };

  node* m_array[HASH_TABLE_SIZE]; // obviously fixed size prevents rehashing 
};

int main()
{
  std::cout << "Hash table\n";

  hash_table h;

  std::ifstream ifs("words.txt");
  std::string s;
  while (ifs >> s)
  {
    std::cout << s << "\n"; 
    h.insert(s.c_str());
  }
}




