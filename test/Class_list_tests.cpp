#include <gtest/gtest.h>
#include <Class/Class.h>
#include <string>
using namespace std;
using namespace ClassStu;

TEST(ClassListTest, FunctionSize) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    int temp = classes.size();
    ASSERT_EQ(temp, 3);
}

TEST(ClassListTest, FunctionRemove) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    classes.remove(1);
    int temp = classes.size();
    ASSERT_EQ(temp, 2);
}


TEST(ClassListTest, FunctionClear) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    classes.clear();
    int temp = classes.size();
    ASSERT_EQ(temp, 0);
}

TEST(ClassListTest, FunctionSwap) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 16));
    ClassList classes1;
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes1.add(make_unique<ClassPractice>("Math", 12));
    classes1.add(make_unique<ClassPractice>("Fizra", 32));
    classes.swap(classes1);
    int temp = classes.size();
    ASSERT_EQ(temp, 3);
}


TEST(ClassListTest, CalcTotal) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    int total = 0;
    total += classes.calc_total(classes[0]->get_name(), InfoOOP);
    ASSERT_EQ(total, 168);
}



TEST(ClassListTest, NameOfClassWithMaxValue) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(4, 8);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    classes.add(make_unique<ClassLecture>("Math", 12));
    classes.add(make_unique<ClassPractice>("Math", 12));
    classes.add(make_unique<ClassPractice>("Fizra", 32));

    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "OOP");
}


TEST(ClassListTest, NameOfClassWithMaxValue1) {
    ClassList classes;
    InfoGroupCounts InfoOOP = InfoGroupCounts::InfoGroupCounts(2, 2);
    classes.add(make_unique<ClassLecture>("OOP", 8));
    classes.add(make_unique<ClassPractice>("OOP", 8));
    classes.add(make_unique<ClassLab>("OOP", 16));
    classes.add(make_unique<ClassLecture>("Math", 12));
    classes.add(make_unique<ClassPractice>("Math", 12));
    classes.add(make_unique<ClassPractice>("Fizra", 32));
    const string name = classes.name_of_max_value(InfoOOP);
    ASSERT_EQ(name, "Fizra");
}

