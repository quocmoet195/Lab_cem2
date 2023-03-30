#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(CalcTotal, NoResult) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(new Classes("OOP", 8, ClassType::Lekture));
    classes.add(new Classes("OOP", 8, ClassType::Practice));
    classes.add(new Classes("OOP", 16, ClassType::Lab));
    int total = 0;
    int size = classes.size();
    total += classes.calc_total(classes[0]->get_name(), InfoOOP);
    ASSERT_EQ(total, 168);
}


TEST(NameOfClassWithMaxValue, P61) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(new Classes("OOP", 8, ClassType::Lekture));
    classes.add(new Classes("OOP", 8, ClassType::Practice));
    classes.add(new Classes("OOP", 16, ClassType::Lab));
    classes.add(new Classes("Math", 12, ClassType::Lekture));
    classes.add(new Classes("Math", 12, ClassType::Practice));
    classes.add(new Classes("Fizra", 32, ClassType::Practice));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "OOP");
}


TEST(NameOfClassWithMaxValue, P51) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(2, 2);
    classes.add(new Classes("OOP", 8, ClassType::Lekture));
    classes.add(new Classes("OOP", 8, ClassType::Practice));
    classes.add(new Classes("OOP", 16, ClassType::Lab));
    classes.add(new Classes("Math", 12, ClassType::Lekture));
    classes.add(new Classes("Math", 12, ClassType::Practice));
    classes.add(new Classes("Fizra", 32, ClassType::Practice));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "Fizra");
}

