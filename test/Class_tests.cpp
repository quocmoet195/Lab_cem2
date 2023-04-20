#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(ClassTests, OPP_Lekture)
{
    ClassLecture OOP = ClassLecture("OOP", 8);
    InfoGroupCounts InfoOOP = InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 8);
}

TEST(ClassTests, OPP_Practice)
{
    ClassPractice OOP = ClassPractice::ClassPractice("OOP", 8);
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 32);
}

TEST(ClassTests, OPP_Lab)
{
    ClassLab OOP = ClassLab::ClassLab("OOP", 8);
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    EXPECT_EQ(OOP.calc_hours(InfoOOP), 64);
}














