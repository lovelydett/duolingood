#include "./LinkedList.h"
#include "./utils.h"

#include <cassert>

namespace ex_1_1 {

LinkedList::Node::Node(const int data, Node* next)
    : data(data)
    , next(next) {}

LinkedList::LinkedList()
    : _dummy(new LinkedList::Node) {}

void LinkedList::_insert(const int idx, const int value) {
    CHECK_BOUND(idx, _size);
    Node* cur = _dummy;
    int   i   = 0;
    while (cur && i < idx) {
        cur = cur->next;
        ++i;
    }
    if (!cur) {
        return;
    }

    cur->next = new Node(value, cur->next);
}

int& LinkedList::_at(const int idx) const {
    CHECK_BOUND(idx, _size);
    Node* cur = _dummy;
    int   i   = 0;
    while (i < idx) {
        cur = cur->next;
        ++i;
    }

    return cur->data;
}

void LinkedList::_push_back(const int value) {
    Node* cur = _dummy;
    for (int i = 0; i < _size; ++i) {
        cur = cur->next;
    }

    assert(cur->next == nullptr);

    cur->next = new Node(value, nullptr);
}

void LinkedList::_push_front(const int value) {
    _dummy->next = new Node(value, _dummy->next);
}

void LinkedList::_pop_back() {
    Node* cur = _dummy;
    for (int i = 0; i < _size - 1; ++i) {
        cur = cur->next;
    }
    SAFE_DELETE(cur->next);
}

void LinkedList::_pop_front() {
    Node* front = _dummy->next;
    if (front) {
        _dummy->next = front->next;
    }

    SAFE_DELETE(front);
}

LinkedList::~LinkedList() {
    Node* cur = _dummy;
    while (cur) {
        Node* next = cur->next;
        SAFE_DELETE(cur);
        cur = next;
    }
}

}   // namespace ex_1_1
