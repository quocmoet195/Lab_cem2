#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;
namespace ClassStu {

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

    class ItemClass;
    using ItemClassPtr = shared_ptr<ItemClass>;

    class ItemClass {
    private:
        std::string _name;
        int _hours;
    public:
        ItemClass();
        ItemClass(const std::string name, const int hours);
        std::string get_name() const;
        int get_hours() const;
        virtual int calc_hours(const InfoGroupCounts& groupInfo) const = 0;
        virtual std::unique_ptr<ItemClass> clone() const = 0;
        virtual void print(std::ostream& stream) const = 0;
    };

    class ClassLecture : public ItemClass {
    public:
        ClassLecture();
        ClassLecture(string name = " ", int hours = 0);
        std::unique_ptr<ItemClass> clone() const;
        int calc_hours(const InfoGroupCounts& groupInfo) const;
        virtual void print(std::ostream& stream) const;
    };

    class ClassPractice : public ItemClass {
    public:
        ClassPractice();
        ClassPractice(std::string name = " ", int hours = 0);
        virtual std::unique_ptr<ItemClass> clone() const override;
        int calc_hours(const InfoGroupCounts& groupInfo) const;
        virtual void print(std::ostream& stream) const;
    };

    class ClassLab : public ItemClass {
    public:
        ClassLab();
        ClassLab(string name = " ", int hours = 0);
        virtual unique_ptr<ItemClass> clone() const override;
        int calc_hours(const InfoGroupCounts& groupInfo) const;
        virtual void print(ostream& stream) const;
    };

    class ClassList {
    private:
        vector<ItemClassPtr> _items;
    public:
        ClassList() = default;
        ClassList(const ClassList& other);
        int size() const;
        ItemClassPtr operator[](int index) const;
        void add(ItemClassPtr f);
        void add(ItemClassPtr f, int index);
        void remove(int index);
        void clear();
        void swap(ClassList& other);
        int calc_total(const string class_name, const InfoGroupCounts& groupInfo);
        string name_of_max_value(const InfoGroupCounts& groupInfo);
    };

}
