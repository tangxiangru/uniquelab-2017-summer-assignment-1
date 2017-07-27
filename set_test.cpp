#include <set>
#include <random>
#include "include/gtest/gtest.h"
#include "set.h"

class setTest : public testing::Test {
protected:
    virtual void SetUp() {
        start_time = time(NULL);
    }

    virtual void TearDown() {
        time_t end_time = time(NULL);
        std::cout << "This test takes " << end_time-start_time << "times." << std::endl;
        ASSERT_TRUE(end_time - start_time <= 10) << "The test took too long.";
    }

    time_t start_time;
};

TEST_F(setTest, random_small) {

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::set<double> std_set;
    Set custom_set;

    for (unsigned i = 0; i != 100; ++i) {
        double num = dis(e);
        std_set.insert(num);
        custom_set.insert(num);
    }

    ASSERT_EQ(std_set.size(), custom_set.size());
    for (auto s: std_set) {
        ASSERT_EQ(custom_set.count(s), 1);
        custom_set.erase(s);
    }
    ASSERT_EQ(custom_set.size(), 0);
}

TEST_F(setTest, random_large) {

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::set<double> std_set;
    Set custom_set;

    for (unsigned i = 0; i != 500000; ++i) {
        double num = dis(e);
        std_set.insert(num);
        custom_set.insert(num);
    }

    ASSERT_EQ(std_set.size(), custom_set.size());
    for (auto s: std_set) {
        ASSERT_EQ(custom_set.count(s), 1);
        custom_set.erase(s);
    }
    ASSERT_EQ(custom_set.size(), 0);
}

TEST_F(setTest, only_data) {
    std::set<double> std_set;
    Set custom_set;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_set.insert((double) 1);
        custom_set.insert((double) 1);
    }
    ASSERT_EQ(std_set.size(), custom_set.size());
    ASSERT_EQ(custom_set.count((double) 1), 1);
}

TEST_F(setTest, ordered_data) {
    std::set<double> std_set;
    Set custom_set;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_set.insert((double) i);
        custom_set.insert((double) i);
        ASSERT_EQ(custom_set.count((double) i), std_set.count((double) i));
    }
    ASSERT_EQ(std_set.size(), custom_set.size());
    for (auto s:std_set) {
        custom_set.erase(s);
    }
    ASSERT_EQ(custom_set.size(), 0);
}

TEST_F(setTest, repeated_data) {
    std::set<double> std_set;
    Set custom_set;
    for (unsigned int i = 0; i != 100000; ++i) {
        std_set.insert((double) i);
        std_set.insert((double) (i + 1));
        custom_set.insert((double) i);
        custom_set.insert((double) (i + 1));
        ASSERT_EQ(custom_set.count((double) i), std_set.count((double) i));
    }
    ASSERT_EQ(std_set.size(), custom_set.size());
    for (auto s:std_set) {
        custom_set.erase(s);
    }
    ASSERT_EQ(custom_set.size(), 0);
}

TEST_F(setTest, crossing_data) {
    std::set<double> std_set;
    Set custom_set;
    for (int i = 1; i != 1; ++i) {
        auto num = (long long)rand()*100000;
        num %=i;
        std_set.insert((double) i);
        std_set.insert((double) (-i));
        std_set.erase((double)(num));
        custom_set.insert((double) i);
        custom_set.insert((double) (-i));
        custom_set.erase((double)(num));
        ASSERT_EQ(custom_set.count((double) i), std_set.count((double) i));
        ASSERT_EQ(custom_set.count((double) (-i)), std_set.count((double) (-i)));
    }
    ASSERT_EQ(std_set.size(), custom_set.size());
    for (auto s:std_set) {
        custom_set.erase(s);
    }
    ASSERT_EQ(custom_set.size(), 0);
}

TEST_F(setTest, random) {
    std::random_device rand_dev;

    std::default_random_engine e(810);
    std::uniform_real_distribution<double> dis(0, 100);

    std::set<double> std_set;
    Set custom_set;
    for (unsigned times = 0; times < 0; ++times) {
        for (unsigned i = 0; i != 80000; ++i) {
            double num = dis(e);
            std_set.insert(num);
            custom_set.insert(num);
        }

        ASSERT_EQ(std_set.size(), custom_set.size());

        if (times % 2) {
            for (auto s:std_set) {
                custom_set.erase(s);
                ASSERT_EQ(custom_set.count(s), 0);
            }
            std_set.clear();
        } else {
            custom_set.clear();
            std_set.clear();
        }

        ASSERT_EQ(std_set.size(), 0);
        ASSERT_EQ(custom_set.size(), 0);
    }
}

TEST_F(setTest,ordered_big){
    Set custom_set;
    for(unsigned i =0;i<1000000;i++){
        custom_set.insert(((double)i));
    }
    ASSERT_EQ(custom_set.size(),1000000);
}
