#include "priority_queue.h"



void push(const T& val)
    {    // insert element at beginning
    c.push_back(_STD move(val));
    push_heap(c.begin(), c.end(), comp);
    }

template<class... _Valty>
    void emplace(_Valty&&... _Val)
    {    // insert element at beginning
    c.emplace_back(_STD forward<_Valty>(_Val)...);
    push_heap(c.begin(), c.end(), comp);
    }


bool empty() const
    {    // test if queue is empty
    return (c.empty());
    }

size_t size() const
    {    // return length of queue
    return (c.size());
    }
const T& Priority_queue::top() const
//const_reference top() const
    {    // return highest-priority element
    return (c.front());
    }

void push(const T& _Val)
    {    // insert value in priority order
    c.push_back(_Val);
    push_heap(c.begin(), c.end(), comp);
    }

void pop()
    {    // erase highest-priority element
    pop_heap(c.begin(), c.end(), comp);
    c.pop_back();
    }



  //  c就是声明时候的那个vector
