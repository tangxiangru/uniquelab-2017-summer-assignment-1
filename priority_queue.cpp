#pragma once

#include <algorithm>
#include <vector>

namespace util {

template <typename T, typename Cmp = std::less<T>>
class priority_queue {
public:
    using container_type = std::vector<T>;
    using value_type = typename container_type::value_type;

public:
    T& top() {
        return m_heap.front();
    }

    const T& top() const {
        return m_heap.front();
    }

    void pop() {
        int last_leaf = m_heap.size() - 1;
        std::swap(m_heap.front(), m_heap[last_leaf]);
        m_heap.pop_back();
        sift_down(0);
    }

    template <typename V>
    void push(V &&v) {
        m_heap.push_back(std::forward<V>(v));
        sift_up(m_heap.size() - 1);
    }

    template <typename... Args>
    void emplace(Args&&... args) {
        m_heap.emplace_back(std::forward<Args>(args)...);
    }

    size_t size() const {
        return m_heap.size();
    }

    bool empty() const {
        return m_heap.empty();
    }

    void swap(priority_queue &other) {
        std::swap(m_heap, other.m_heap);
        std::swap(m_cmp, other.m_cmp);
    }

private:
    void sift_up(int i) {
        T t(std::move(m_heap[i]));

        while (true) {
            int p = parent(i);

            if (i > 0 && m_cmp(m_heap[p], t)) {
                m_heap[i] = std::move(m_heap[p]);
                i = p;
            } else {
                m_heap[i] = std::move(t);
                break;
            }
        }
    }

    void sift_down(int i) {
        while (true) {
            int left = left_child(i);
            int right = right_child(i);

            int max = i;

            if (left < m_heap.size() && m_cmp(m_heap[max], m_heap[left])) {
                max = left;
            }

            if (right < m_heap.size() && m_cmp(m_heap[max], m_heap[right])) {
                max = right;
            }

            if (max == i) {
                break;
            }

            std::swap(m_heap[i], m_heap[max]);

            i = max;
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left_child(int i) {
        return 2 * i + 1;
    }

    int right_child(int i) {
        return 2 * i + 2;
    }

private:
    Cmp m_cmp;
    container_type m_heap;
};

}
