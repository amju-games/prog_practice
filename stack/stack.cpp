// j.c. programming practice

#include <cassert>
#include <iostream>

class stack
{
public:
  stack() 
  {
    realloc(10); // initial stack space - better to wait for first push?
  }

  stack(const stack& s)
  {
    realloc(s.m_max);
    m_size = s.m_size;
    for (int i = 0; i < m_size; i++)
    {
      m_s[i] = s.m_s[i];
    }
  }

  // Awesome assignment: written in terms of copy ctor; is exception
  //  safe; handles self-assignment
  /*
  stack& operator=(const stack& s)
  {
    stack tmp(other);
    // swap all members
    swap(*this, tmp);
    return *this;
  }
  */
  // Even better is to do the copying in the parameter pass:
  // (This allows copiler to optimise away the copy when param is an
  //  r-value.)
  stack& operator=(stack s) // s is passed by value, i.e.  copied
  {
    swap(*this, s);
    return *this;
  }

  ~stack()
  {
    delete [] m_s;
  }

  void push(int i)
  {
    assert(m_size < m_max);

    // Realloc if we have run out of space.
    // Amortized constant time, like vector push_back.
    if (m_size + 1 == m_max)
    {
      realloc(m_max * 2);
    }
    m_s[m_size] = i;
    m_size++;

    assert(m_size < m_max);
  }

  void pop() 
  {
    assert(m_size > 0);
    m_size--; 
  }

  bool empty() const { return m_size == 0; }

  int top() const 
  {
    assert(!empty()); 
    return m_s[m_size - 1]; 
  }

private:
  void realloc(int new_size)
  {
    int* new_s = new int[new_size];
    for (int i = 0; i < m_size; i++)
    {
      new_s[i] = m_s[i];
    }
    delete [] m_s;
    m_s = new_s;
    m_max = new_size;
  }

  friend void swap(stack& s1, stack& s2) // refs, but not to const!
  {
    using std::swap;
    swap(s1.m_s, s2.m_s);
    swap(s1.m_size, s2.m_size);
    swap(s1.m_max, s2.m_max);
  }

private:
  int m_size = 0;
  int m_max = 0;
  int* m_s = nullptr;
};

int main()
{
  std::cout << "Stack\n";

  stack s;
  assert(s.empty());
  s.push(1);
  assert(!s.empty());
  assert(s.top() == 1);
  s.pop(); 
  assert(s.empty());

  s.push(1);
  s.push(2);

  stack s2 = s; // copy ctor
  assert(s2.top() == 2);
  s2.pop();
  assert(s2.top() == 1);
 
  stack s3;
  s3 = s2; // assignment
  assert(s3.top() == 1);
  s3.pop();
  assert(s3.empty());  

  std::cout << " is awesome\n";
}



