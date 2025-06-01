
#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_insert, AddFunction)
{
    SortError error = SE_SUCCESS;

    // add your test here

    ASSERT_EQ(error, SE_SUCCESS);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}