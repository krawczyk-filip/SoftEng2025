
#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_select, AddFunction)
{
    Sorter* sorter = new Sorter();
    SortData<float, std::vector> data;

    int dsize = 128 + rand() % 100;
    for (unsigned i = 0; i < dsize; i++) data.add(float(rand() % 1024) / 4096);
    auto error = sorter->sort<float, std::vector, STT_SELECT>(data);

    ASSERT_TRUE(std::is_sorted(data.data().begin(), data.data().end()));
    ASSERT_EQ(error, SE_SUCCESS);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}