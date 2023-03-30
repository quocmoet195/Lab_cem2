#include <Class/Class.h>
#include <stdexcept>

using namespace ClassStu;
using namespace std;

ClassList::ClassList() : _size(0) { }

int ClassList::size() const {
    return _size;
}

Classes ClassList::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw out_of_range("[ClassList::operator[]] Index is out of range.");
    }
    return _classes[index];
}

void ClassList::add(const Classes f) {
    if (_size == CAPACITY) {
        throw runtime_error("[ClassList::add] Size error.");
    }
    _classes[_size] = f;
    ++_size;
}


void ClassList::swap(ClassList& other) {
    std::swap(this->_classes, other._classes);
    std::swap(this->_size, other._size);
}


int ClassList::calc_total(const string class_name, const InfoGroupCounts& groupInfo)
{
    int total = 0;
    for (int i = 0; i < _size; ++i) {
        if (class_name == _classes[i].get_name())
        {
            total += _classes[i].calc_hours(groupInfo);
        }
    }
    return total;
}

string ClassList::name_of_max_value(const InfoGroupCounts& groupInfo)
{
    if (_size == 0)
        return string();
    int max_index = 0;
    auto max_value = calc_total(_classes[0].get_name(), groupInfo);
    for (int i = 1; i < _size; ++i)
    {
        const auto value = calc_total(_classes[i].get_name(), groupInfo);
        if (max_value < value) {
            max_index = i;
            max_value = value;
        }
    }
    return _classes[max_index].get_name();
}

