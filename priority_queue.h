#include <algorithm>
#include <vector>
//#pragma once
using value_type = typename container_type::value_type;
template <typename T, typename Cmp = std::less<T>>
//using T = double;
using std::vector;
class Priority_queue {
public:
  bool empty() const;
  size_t size() const;
  const T& top() const;
  void push(const T& val);
  const T& pop();
  void swap(Priority_queue &other);

      void swap(priority_queue &other);

  void swap(priority_queue &other)；
private:
  void sift_up(int i);
  void sift_down(int i);
  int parent(int i);
  int left_child(int i);
  int right_child(int i);
private:
  Cmp m_cmp;
  container_type m_heap;

};
