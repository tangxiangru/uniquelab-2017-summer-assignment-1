#include "priority_queue.h"
#include <algorithm>
#include <vector>

bool Priority_queue::empty() const {
    if (c_size == 0)
        return true;
    else
        return false;
}

size_t Priority_queue::size() const {
    return c_size;
}

const T& Priority_queue::top() const {
        return c[1];
}

void Priority_queue::push(const T& val) {
    if (c.size() == 0)
        c.resize(1);
    if (c_size == c.size() - 1)
        c.resize(c.size() * 2);
    int k = ++c_size;
    for ( ; k > 1 && val > c[k / 2]; k /= 2)
        c[k] = c[k / 2];
    c[k] = val;
}


void Priority_queue::pop() {
    if (empty())
        return;
    int i, child;
    T temp = c[c_size--];
    for (i = 1; i * 2 <= c_size; i = child) {
      child = i * 2;
      if (child != c_size && c[child] < c[child + 1])
        child++;
      if (temp < c[child])
        c[i] = c[child];
      else
        break;
    }
    c[i] = temp;

}
