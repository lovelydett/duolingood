#include "./LinkedList.h"

#include <gtest/gtest.h>


TEST(LinkedListTest, Insert) {
    auto llist = ex_1_1::LinkedList();

    EXPECT_EQ(llist.size(), 0);

    llist.push_back(1);

    EXPECT_EQ(llist.size(), 1);

    llist.pop_back();

    EXPECT_EQ(llist.size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
