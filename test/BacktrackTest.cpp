#include <gtest/gtest.h>
#include "../src/ImprovedBacktrack.h"

class BacktrackTest : public ::testing::Test {
protected:
    Solver* solver;

    std::vector<int> ints1;
    std::vector<int> ints2;

    virtual void SetUp() {
        solver = new ImprovedBacktrack();

        int intArr1[8] = {0,7,1,2,2,1,5,0};
        int intArr2[12] = {3,11,0,1,3,5,2,4,1,0,9,3};

        ints1.insert(ints1.begin(), intArr1, intArr1 + 8);
        ints2.insert(ints2.begin(), intArr2, intArr2 + 12);
    }

    virtual void TearDown() {
        delete solver;
    }
};

TEST_F(BacktrackTest, listWithOptimal) {
    size_t solution = solver->getSolution(ints1);
    ASSERT_EQ(solution, (size_t)0);
}

TEST_F(BacktrackTest, listWithoutOptimal) {
    size_t solution = solver->getSolution(ints2);
    ASSERT_EQ(solution, (size_t)2);
}