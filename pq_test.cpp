#include <queue>
#include <random>
#include "include/gtest/gtest.h"

#include "priority_queue.h"

class  priorityQueueTest: public testing::Test {
protected:
    virtual void SetUp() {
        start_time = time(NULL);
    }

    virtual void TearDown() {
        time_t end_time = time(NULL);
        EXPECT_TRUE(end_time-start_time <=10)<< "The test took too long.";
    }
    time_t start_time;
};

TEST_F(priorityQueueTest, random_small) {
    std::random_device rand_dev;

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::priority_queue<double> std_pq;
    Priority_queue pq;

    for (unsigned i = 0; i != 100; ++i) {
        double num = dis(e);
        std_pq.push(num);
        pq.push(num);
    }

    ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
    ASSERT_EQ(std_pq.size(), pq.size());
}

TEST_F(priorityQueueTest,random_large) {
    std::random_device rand_dev;

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::priority_queue<double> std_pq;
    Priority_queue pq;

    for (unsigned i = 0; i != 5000000; ++i) {
        double num = dis(e);
        std_pq.push(num);
        pq.push(num);
    }
    ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
    ASSERT_EQ(std_pq.size(), pq.size());
}

TEST_F(priorityQueueTest, only_data) {
    std::priority_queue<double> std_pq;
    Priority_queue pq;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_pq.push((double) 1);
        pq.push((double) 1);
    }
    ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
    ASSERT_EQ(std_pq.size(), pq.size());
    while (!pq.empty()) {
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        std_pq.pop();
        pq.pop();
    }
    ASSERT_EQ(pq.size(), 0);
    ASSERT_EQ(std_pq.size(), 0);

}

TEST_F(priorityQueueTest, ordered_data) {
    std::priority_queue<double> std_pq;
    Priority_queue pq;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_pq.push((double) i);
        pq.push((double) i);
    }
    ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
    ASSERT_EQ(std_pq.size(), pq.size());
    while (!pq.empty()) {
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        std_pq.pop();
        pq.pop();
    }
    ASSERT_EQ(pq.size(), 0);
    ASSERT_EQ(std_pq.size(), 0);
}

TEST_F(priorityQueueTest, repeated_data) {
    std::priority_queue<double> std_pq;
    Priority_queue pq;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_pq.push((double) i);
        pq.push((double) i);
        std_pq.push((double) (i + 1));
        pq.push((double) (i + 1));
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        ASSERT_EQ(std_pq.size(), pq.size());
    }
    ASSERT_EQ(std_pq.size(), pq.size());
    while (!pq.empty()) {
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        std_pq.pop();
        pq.pop();
    }
    ASSERT_EQ(pq.size(), 0);
    ASSERT_EQ(std_pq.size(), 0);
}

TEST_F(priorityQueueTest, crossing_data) {
    std::priority_queue<double> std_pq;
    Priority_queue pq;
    for (int i = 0; i != 100000; ++i) {
        std_pq.push((double) i);
        pq.push((double) i);
        std_pq.push((double) -i);
        pq.push((double) -i);
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        ASSERT_EQ(std_pq.size(), pq.size());
    }
    ASSERT_EQ(std_pq.size(), pq.size());
    while (!pq.empty()) {
        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        std_pq.pop();
        pq.pop();
    }
    ASSERT_EQ(pq.size(), 0);
    ASSERT_EQ(std_pq.size(), 0);
}

TEST_F(priorityQueueTest, random) {
    std::random_device rand_dev;

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::priority_queue<double> std_pq;
    Priority_queue pq;
    for (unsigned times = 0; times < 10; ++times) {
        for (unsigned i = 0; i != 100000; ++i) {
            double num = dis(e);
            std_pq.push(num);
            pq.push(num);
        }

        ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
        ASSERT_EQ(std_pq.size(), pq.size());

        while (!std_pq.empty()) {
            ASSERT_DOUBLE_EQ(std_pq.top(), pq.top());
            ASSERT_EQ(std_pq.size(), pq.size());
            std_pq.pop();
            pq.pop();
        }

        ASSERT_EQ(pq.size(), 0);
        ASSERT_EQ(std_pq.size(), 0);
    }
}
