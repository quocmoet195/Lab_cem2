#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(ClassTests, OPP_Lekture)
{
    Classes OOP = Classes::Classes("OOP", 8, ClassType::Lekture);
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 8);
}

TEST(ClassTests, OPP_Practice)
{
    Classes OOP = Classes::Classes("OOP", 8, ClassType::Practice);
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 32);
}

TEST(ClassTests, OPP_Lab)
{
    Classes OOP = Classes::Classes("OOP", 8, ClassType::Lab);
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 64);
}














