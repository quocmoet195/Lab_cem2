#include <Class/Class.h>
#include <stdexcept>

using namespace ClassStu;
using namespace std;

ClassList::ClassList() : _classes(nullptr), _size(0) { }

ClassList::ClassList(const ClassList& other) {
    _classes = new ClassesPtr[other._size];
    _size = other._size;
    for (int i = 0; i < _size; ++i) {
        _classes[i] = new Classes(other[i]->get_name(), other[i]->get_hours(), other[i]->get_type());
    }
}

int ClassList::size() const {
    return _size;
}

ClassesPtr ClassList::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw out_of_range("[ClassList::operator[]] Index is out of range.");
    }
    return _classes[index];
}

void ClassList::add(ClassesPtr const f) {
    auto new_classes = new ClassesPtr[_size + 1];

    for (int i = 0; i < _size; ++i) {
        new_classes[i] = _classes[i];
    }
    new_classes[_size] = f;

    delete[] _classes;
    _classes = new_classes;

    ++_size;
}

void ClassList::add(ClassesPtr f, int index) {
    auto new_classes = new ClassesPtr[_size + 1];

    for (int i = 0; i < index; ++i) {
        new_classes[i] = _classes[i];
    }
    new_classes[index] = f;
    for (int i = index + 1; i < _size + 1; ++i) {
        new_classes[i] = _classes[i - 1];
    }
    delete[] _classes;
    _classes = new_classes;

    ++_size;
}

void ClassList::remove(int index) {
    if (index < 0 || _size <= index) {
        throw runtime_error("[ClassList::remove] Capacity is reached.");
    }
    auto* new_classes = new ClassesPtr[_size - 1];

    for (int i = 0; i < index; i++) {
        new_classes[i] = _classes[i];
    }
    for (int i = index; i < _size - 1; i++) {
        new_classes[i] = _classes[i + 1];
    }

    delete[] _classes;
    _classes = new_classes;

    _size--;
}

void ClassList::swap(ClassList& other) {
    std::swap(this->_classes, other._classes);
    std::swap(this->_size, other._size);
}

ClassList::~ClassList() {
    for (int i = 0; i < _size; ++i) {
        delete _classes[i];
    }
    delete[] _classes;
}

int ClassList::calc_total(const string class_name, const InfoGroupCounts& groupInfo)
{
    int total = 0;
    for (int i = 0; i < _size; ++i) {
        if (class_name == _classes[i]->get_name())
        {
            total += _classes[i]->calc_hours(groupInfo);
        }
    }
    return total;
}

string ClassList::name_of_max_value(const InfoGroupCounts& groupInfo)
{
    if (_size == 0)
        return string();
    int max_index = 0;
    auto max_value = calc_total(_classes[0]->get_name(), groupInfo);
    for (int i = 1; i < _size; ++i) {

        const auto value = calc_total(_classes[i]->get_name(), groupInfo);
        if (max_value < value) {
            max_index = i;
            max_value = value;
        }
    }
    return _classes[max_index]->get_name();
}

