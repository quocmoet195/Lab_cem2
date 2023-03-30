#include <Class/Class.h>
#include <cassert>
#include <cmath>
#include <string>
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

Classes::Classes()
{
    _name = " ";
    _hours = 0;
    _type = ClassType::Lekture;
};

Classes::Classes(const std::string name, const int hours, const ClassType type)
{
    _name = name;
    _hours = hours;
    _type = type;
};

string Classes::get_name()
{
    return _name;
}

int Classes::get_hours()
{
    return _hours;
}

ClassType Classes::get_type() const {
    return _type;
}

int Classes::calc_hours(const InfoGroupCounts& groupInfo)
{
    switch (_type) {
    case ClassType::Lekture:
        return _hours;
    case ClassType::Practice:
        return groupInfo.get_num_groups() * _hours;
    case ClassType::Lab:
        return groupInfo.get_num_subgroups() * _hours;
    default:
        throw runtime_error("[Classes::compute_value] Invalid classes type.");
    }
}






