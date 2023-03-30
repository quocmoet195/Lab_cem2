#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(FunctionListTests, CapacityCheck) {
    ClassList classes;
    auto f = Classes::Classes("OOP", 8, ClassType::Lekture);
    for (int i = 0; i < ClassList::CAPACITY; ++i) {
        classes.add(f);
    }
    ASSERT_ANY_THROW(classes.add(f));
}

TEST(CalcTotal, NoResult) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(Classes::Classes("OOP", 8, ClassType::Lekture));
    classes.add(Classes::Classes("OOP", 8, ClassType::Practice));
    classes.add(Classes::Classes("OOP", 16, ClassType::Lab));
    int total = classes.calc_total(classes[0].get_name(), InfoOOP);
    ASSERT_EQ(total, 168);
}


TEST(NameOfClassWithMaxValue, P61) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(Classes::Classes("OOP", 8, ClassType::Lekture));
    classes.add(Classes::Classes("OOP", 8, ClassType::Practice));
    classes.add(Classes::Classes("OOP", 16, ClassType::Lab));
    classes.add(Classes::Classes("Math", 12, ClassType::Lekture));
    classes.add(Classes::Classes("Math", 12, ClassType::Practice));
    classes.add(Classes::Classes("Fizra", 32, ClassType::Practice));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "OOP");
}


TEST(NameOfClassWithMaxValue, P51) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(2, 2);
    classes.add(Classes::Classes("OOP", 8, ClassType::Lekture));
    classes.add(Classes::Classes("OOP", 8, ClassType::Practice));
    classes.add(Classes::Classes("OOP", 16, ClassType::Lab));
    classes.add(Classes::Classes("Math", 12, ClassType::Lekture));
    classes.add(Classes::Classes("Math", 12, ClassType::Practice));
    classes.add(Classes::Classes("Fizra", 32, ClassType::Practice));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "Fizra");
}

