#include <iostream>
#include <algorithm>
#include <vector>
//#pragma once
using T = double;
using std::vector;
using std::cout;
using std::endl;
//using value_type = typename container_type::value_type;
//template <typename T, typename Cmp = std::less<T>>


class Priority_queue {
public:
  bool empty() const;
  size_t size() const;
  const T& top() const;
  void push(const T& val);
  void swap(Priority_queue &other);

  //void swap(priority_queue &other);

  //void swap(priority_queue &other)；

  void pop();

  private:
    void sift_up(int i);
    void sift_down(int i);
    int parent(int i);
    int left_child(int i);
    int right_child(int i);
  private:
  //  Cmp m_cmp;
  //  container_type m_heap;
    vector<T> c;
    int c_size = 0; //属性：当前队列大小
};
