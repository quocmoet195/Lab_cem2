#include <Class/Class.h>
#include <stdexcept>

using namespace ClassStu;
using namespace std;

ClassList::ClassList(const ClassList& other) {
    for (int i = 0; i < other.size(); i++)
    {
        _items.push_back(other._items[i]->clone());
    }
    /*std::transform(
        other._items.begin(), 
        other._items.end(), 
        back_inserter(_items),
        [](ItemClassPtr item) { return item->clone(); }
    );*/
}

int ClassList::size() const
{
    return _items.size();
};

ItemClassPtr ClassList::operator[](const int index) const {
    if (index < 0 || _items.size() <= index) {
        throw out_of_range("[ClassList::operator[]] Index is out of range.");
    }
    return _items[index];
}

void ClassList::add(ItemClassPtr f)
{
    _items.push_back(f);
}

void ClassList::add(ItemClassPtr f, int index)
{
    if (index < 0 || _items.size() <= index) {
        throw out_of_range("[ClassList::operator[]] Index is out of range.");
    }
    _items.insert(_items.begin() + index, f);
}

void ClassList::remove(int index)
{
    if (index < 0 || _items.size() <= index) {
        throw out_of_range("[ClassList::operator[]] Index is out of range.");
    }
    _items.erase(_items.begin() + index);
}


void ClassList::clear()
{
    _items.clear();
}

void ClassList::swap(ClassList& other) {
    std::swap(this->_items, other._items);
    std::swap(this->_items, other._items);
}


int ClassList::calc_total(const string class_name, const InfoGroupCounts& groupInfo)
{
    int size = _items.size();
    int total = 0;
    for (int i = 0; i < size; ++i) {
        if (class_name == _items[i]->get_name())
        {
            total += _items[i]->calc_hours(groupInfo);
        }
    }
    return total;
}

string ClassList::name_of_max_value(const InfoGroupCounts& groupInfo)
{
    int size = _items.size();
    if (size == 0)
        return string();
    int max_index = 0;
    auto max_value = calc_total(_items[0]->get_name(), groupInfo);
    for (int i = 1; i < size; ++i) {

        const auto value = calc_total(_items[i]->get_name(), groupInfo);
        if (max_value < value) {
            max_index = i;
            max_value = value;
        }
    }
    return _items[max_index]->get_name();
}

