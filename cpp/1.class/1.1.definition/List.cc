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
    ++_size;
}

int& List::operator[](const int idx) const {
    return _at(idx);
}

void List::push_front(const int value) {
    this->_push_front(value);
    ++_size;
}

void List::pop_front() {
    if (_size == 0) {
        return;
    }
    this->_pop_front();
    --_size;
}

void List::push_back(const int value) {
    this->_push_back(value);
    ++_size;
}

void List::pop_back() {
    if (_size == 0) {
        return;
    }
    this->_pop_back();
    --_size;
}

}   // namespace ex_1_1
