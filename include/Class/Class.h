#pragma once
#include <string>

using namespace std;
namespace ClassStu {

    enum class ClassType {
        Lekture,
        Practice,
        Lab
    };

    class InfoGroupCounts
    {
    private:
        int _numSubGroups;
        int _numGroups;
    public:
        InfoGroupCounts(const int numGroups, const int numSubGroups);
        int  get_num_subgroups() const;
        int get_num_groups() const;

    };

    class Classes
    {
    private:
        string _name;
        int _hours;
        ClassType _type;
    public:
        Classes();
        Classes(const string name, const int hours, const ClassType type);
        string get_name();
        int  get_hours();
        ClassType get_type() const;
        int calc_hours(const InfoGroupCounts& groupInfo);
    };

    class ClassList {
    public:
        static const int CAPACITY = 10;
    private:
        Classes _classes[CAPACITY];
        int _size;
    public:
        ClassList();
        int size() const;
        Classes operator[](int index) const;
        void add(Classes f);
        void remove(int index);
        void swap(ClassList& other);
        int calc_total(const string class_name, const InfoGroupCounts& groupInfo);
        string name_of_max_value(const InfoGroupCounts& groupInfo);
    };
}




