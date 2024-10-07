#include "gtest/gtest.h"

extern "C"
{
#include "NumberOfRoutes.h"
}

TEST(NumberOfRoutesAllTest, Invalidsize)
{
	EXPECT_EQ(NumberOfRoutesAll(-1, 1), 0);
}

TEST(NumberOfRoutesAllTest, Invalidstepsize)
{
	EXPECT_EQ(NumberOfRoutesAll(1, -1), 0);
}

TEST(NumberOfRoutesAllTest, SingularValues)
{
	EXPECT_EQ(NumberOfRoutesAll(1, 1), 1);
}

TEST(NumberOfRoutesAllTest, stepsizeLongersize)
{
	EXPECT_EQ(NumberOfRoutesAll(2, 5), 2);
}

TEST(NumberOfRoutesAllTest, sizeLongerstepsize)
{
	EXPECT_EQ(NumberOfRoutesAll(5, 2), 8);
}