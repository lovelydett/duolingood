#include "./List.h"

namespace ex_1_1 {
class LinkedList : public List {
    struct Node {
        int   data;
        Node* next = nullptr;
        Node()     = default;
        Node(const int data, Node* next = nullptr);
    };

public:
    LinkedList();
    int _front();
    int _back();

protected:
    Node* const _dummy;
    void        _push_back(const int);
    void        _push_front(const int);
    void        _pop_back();
    void        _pop_front();
    void        _insert(const int idx, const int value);
    int&        _at(const int) const;
};
}   // namespace ex_1_1