#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(CalcTotal, NoResult) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>(string("OOP"), 8));
    classes.add(make_unique<ClassPractice>(string("OOP"), 8));
    classes.add(make_unique<ClassLab>(string("OOP"), 16));
    int total = 0;
    total += classes.calc_total(classes[0]->get_name(), InfoOOP);
    ASSERT_EQ(total, 168);
}



TEST(NameOfClassWithMaxValue, P61) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>(string("OOP"), 8));
    classes.add(make_unique<ClassPractice>(string("OOP"), 8));
    classes.add(make_unique<ClassLab>(string("OOP"), 16));
    classes.add(make_unique<ClassLecture>(string("Math"), 12));
    classes.add(make_unique<ClassPractice>(string("Math"), 12));
    classes.add(make_unique<ClassPractice>(string("Fizra"), 32));

    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "OOP");
}


TEST(NameOfClassWithMaxValue, P51) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(2, 2);
    classes.add(make_unique<ClassLecture>(string("OOP"), 8));
    classes.add(make_unique<ClassPractice>(string("OOP"), 8));
    classes.add(make_unique<ClassLab>(string("OOP"), 16));
    classes.add(make_unique<ClassLecture>(string("Math"), 12));
    classes.add(make_unique<ClassPractice>(string("Math"), 12));
    classes.add(make_unique<ClassPractice>(string("Fizra"), 32));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "Fizra");
}

