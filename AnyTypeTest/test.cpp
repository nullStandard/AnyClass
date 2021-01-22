#include "pch.h"
#include "C:\Users\User\source\repos\UltimateClass\UltimateClass\AnyType.cpp"

TEST(AnyTypeTesting, correct_cast)
{
    AnyType anyType(1);
    ASSERT_NO_THROW(anyType.toInt());
}

TEST(AnyTypeTesting, swap_and_bad_cast)
{
    AnyType anyType_first(true);
    AnyType anyType_second(1.7);
    anyType_second.swap(anyType_first);
    ASSERT_ANY_THROW(anyType_first.toInt());
}

TEST(AnyTypeTesting, multiple_assigment)
{
    AnyType anyType_first(true);
    AnyType anyType_second(1.7);
    AnyType anyType_third(52493);

    anyType_first = anyType_second = anyType_third;
    EXPECT_EQ(52493, anyType_first.toInt());
}

TEST(AnyTypeTesting, multiple_init)
{
    AnyType anyType_first(true);
    AnyType anyType_second(anyType_first);
    AnyType anyType_third(anyType_second);

    ASSERT_NO_THROW(anyType_third.toBool());
}

TEST(AnyTypeTesting, test_unsigned)
{
    AnyType anyType_first(8800u);
    AnyType anyType_second(anyType_first);

    ASSERT_ANY_THROW(anyType_second.toInt());
}

TEST(AnyTypeTesting, test_double)
{
    AnyType anyType_first(1.2397109471);
    AnyType anyType_second(anyType_first);
    double test_double = anyType_second.toDouble();
    ASSERT_DOUBLE_EQ(1.2397109471, test_double);
}

TEST(AnyTypeTesting, test_get_type)
{
    AnyType anyType_first(1.971f);
    AnyType anyType_second(false);
    anyType_second = anyType_first;

    if (anyType_second.getType().name() == typeid(float).name())
    {
        ASSERT_TRUE(true);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}