#include <cassert>
#include <iostream>

// Queue of int implemented with linked list
class queue
{
public:
  queue() = default;

  ~queue()   // O(n)
  {
    while (!empty())
    {
      pop();
    }
  }

  queue(const queue& q) // O(n)
  {
    node* n = q.m_front;
    while(n)
    {
      push(n->m_i);
      n = n->m_next;
    }
  }

  friend void swap(queue& q1, queue& q2) // O(1)
  {
    using std::swap;
    swap(q1.m_front, q2.m_front);
    swap(q1.m_back, q2.m_back);
  }

  queue& operator=(queue q) // copy ctor called here, so O(n)
  {
    swap(*this, q);
    return *this;
  }

  int front() const // O(1)
  {
    assert(!empty());
    return m_front->m_i;
  }

  void pop()  // O(1)
  {
    assert(!empty());
    node* next = m_front->m_next;
    delete m_front;
    m_front = next;

    if (empty())
    {
      m_back = nullptr;
    }
  }

  void push(int i) // O(1)
  {
    node* n = new node { i, nullptr };
    if (m_back)
    {
      // Append new node to end of list
      m_back->m_next = n;
    }
    else
    {
      // First list node
      m_front = n;
    }
    // Point to back so we can add new node in O(1)
    m_back = n;
  }

  bool empty() const // O(1)
  {
    return !m_front;
  }

private:
  // linked list node
  struct node
  {
    int m_i;
    node* m_next;
  };

  node* m_front = nullptr;
  node* m_back = nullptr;
};

int main()
{
  std::cout << "Queue\n";

  queue q;
  assert(q.empty());
  q.push(1);
  assert(!q.empty());
  assert(q.front() == 1);
  q.push(2);
  assert(q.front() == 1);

  queue q2 = q; // copy ctor

  queue q3;
  q3 = q2; // assignment op

  q.pop();
  assert(q.front() == 2);
  q.pop();
  assert(q.empty());

  assert(!q2.empty());
  assert(q2.front() == 1);
  q2.pop();
  assert(q2.front() == 2);
  q2.pop();
  assert(q2.empty());

  assert(!q3.empty());
  assert(q3.front() == 1);
  q3.pop();
  assert(q3.front() == 2);
  q3.pop();
  assert(q3.empty());

  std::cout << " is awesome.\n";
}



