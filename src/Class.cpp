#include <Class/Class.h>
#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace ClassStu;
using namespace std;

InfoGroupCounts::InfoGroupCounts(const int numGroups, const int numSubGroups)
{
    _numSubGroups = numSubGroups;
    _numGroups = numGroups;
}


int InfoGroupCounts::get_num_subgroups() const
{
    return _numSubGroups;
}

int InfoGroupCounts::get_num_groups() const
{
    return _numGroups;
}

ItemClass::ItemClass() : _hours(0) {};

ItemClass::ItemClass(std::string name, int hours) : _name(name), _hours(hours) {};

string ItemClass::get_name() const
{
    return _name;
}

int ItemClass::get_hours() const
{
    return _hours;
}


ClassLecture::ClassLecture() : ItemClass("", 0) {};

ClassLecture::ClassLecture(std::string name, int hours) : ItemClass(name, hours) {};

unique_ptr<ItemClass> ClassLecture::clone() const
{
    return std::make_unique<ClassLecture>(*this);
};

int ClassLecture::calc_hours(const InfoGroupCounts& groupInfo) const
{
    return get_hours();
}

void ClassLecture::print(std::ostream& stream) const
{
    stream << left << setw(11) << "Lecture: " << left << setw(12) << get_name() << get_hours() << " hours" << std::endl;
};

ClassPractice::ClassPractice() : ItemClass("", 0) {};

ClassPractice::ClassPractice(std::string name, int hours) : ItemClass(name, hours) {};

unique_ptr<ItemClass> ClassPractice::clone() const
{
    return std::make_unique<ClassPractice>(*this);
};

int ClassPractice::calc_hours(const InfoGroupCounts& groupInfo) const
{
    return groupInfo.get_num_groups() * get_hours();
}

void ClassPractice::print(std::ostream& stream) const
{
    stream << left << setw(11) << "Practice: " << left << setw(12) << get_name() << get_hours() << " hours" << std::endl;
}



ClassLab::ClassLab() : ItemClass("", 0) {};

ClassLab::ClassLab(std::string name, int hours) : ItemClass(name, hours) {};

unique_ptr<ItemClass> ClassLab::clone() const
{
    return std::make_unique<ClassLab>(*this);
};

int ClassLab::calc_hours(const InfoGroupCounts& groupInfo) const
{
    return groupInfo.get_num_subgroups() * get_hours();
}

void ClassLab::print(ostream& stream) const
{
    stream << left << setw(11) << "Lab: " << left << setw(12) << get_name() << get_hours() << " hours" << std::endl;
}






