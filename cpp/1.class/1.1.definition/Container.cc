#include "./Container.h"

namespace ex_1_1 {
Container::Container(const int size) : _size(size) {}
Container::Container(const int size, const int cap) : _size(size), _cap(cap) {}
int Container::size() const { return _size; }
} // namespace ex_1_1
