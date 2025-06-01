#include <gtest/gtest.h>
#include <vector> // potrzebne, bo używamy std::vector
#include "Sorter.h"
#include "SortData.h" // konieczne, żeby korzystać z SortData<>

//
// 1) Test sprawdzający samą klasę Sorter (AddFunction)
//
TEST(test_sort1, AddFunction)
{
    Sorter* sorter = new Sorter();
    ASSERT_NE(sorter, nullptr);

    delete sorter;
    sorter = nullptr;
    ASSERT_EQ(sorter, nullptr);
}

//
// 2) Domyślna technika sortuje int-y
//
TEST(test_sort1, DefaultTechniqueSortsInt)
{
    // Przygotowujemy nieposortowany wektor intów:
    std::vector<int> input{ 5, 3, 1, 4, 2 };

    // Tworzymy obiekt SortData<int, std::vector>
    SortData<int, std::vector> data;
    // Zgodnie ze wskazówką: najpierw przypisujemy input.data() do nazwanego
    // wskaźnika:
    const decltype(input)::value_type* d = input.data();
    data.add(d, static_cast<unsigned int>(input.size()));

    // Sortujemy używając domyślnej techniki:
    Sorter sorter;
    sorter.sort(data);

    // Pobieramy posortowane dane i sprawdzamy, czy rosnąco:
    const auto& v = data.data();
    for (size_t i = 1; i < v.size(); ++i)
    {
        ASSERT_LE(v[i - 1], v[i])
            << "Wektor intów nie jest posortowany na pozycji " << i;
    }
}

//
// 3) Domyślna technika sortuje float-y
//
TEST(test_sort1, DefaultTechniqueSortsFloat)
{
    std::vector<float> input{ 3.14f, 2.71f, 0.0f, -1.0f, 1.23f };

    SortData<float, std::vector> data;
    const decltype(input)::value_type* d = input.data();
    data.add(d, static_cast<unsigned int>(input.size()));

    Sorter sorter;
    sorter.sort(data);

    const auto& v = data.data();
    for (size_t i = 1; i < v.size(); ++i)
    {
        ASSERT_LE(v[i - 1], v[i])
            << "Wektor floatów nie jest posortowany na pozycji " << i;
    }
}

//
// 4) Domyślna technika sortuje double-y
//
TEST(test_sort1, DefaultTechniqueSortsDouble)
{
    std::vector<double> input{ 9.99, 3.33, 7.77, 1.11, 5.55 };

    SortData<double, std::vector> data;
    const decltype(input)::value_type* d = input.data();
    data.add(d, static_cast<unsigned int>(input.size()));

    Sorter sorter;
    sorter.sort(data);

    const auto& v = data.data();
    for (size_t i = 1; i < v.size(); ++i)
    {
        ASSERT_LE(v[i - 1], v[i])
            << "Wektor double nie jest posortowany na pozycji " << i;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
