#include "./List.h"

namespace ex_1_1 {

List::List(const int size)
    : _size(size) {}

List::List(const int size, const int cap)
    : _size(size)
    , _cap(cap) {}

int List::size() const {
    return _size;
}

void List::insert(const int idx, const int value) {
    this->_insert(idx, value);
}

int& List::operator[](const int idx) const {
    return _at(idx);
}

}   // namespace ex_1_1
