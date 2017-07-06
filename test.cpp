#include "set.h"
#include "priority_queue.h"
#include <iostream>

int main() {
    Priority_queue pq;

    pq.push(3);
    pq.push(1);
    pq.push(5);
    pq.push(10);
    pq.push(20);
    pq.push(15);

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}
