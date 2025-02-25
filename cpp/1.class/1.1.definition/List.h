#include "./Container.h"

namespace ex_1_1 {
class List : public Container {
  struct Node {
    int data;
    struct Node *next = nullptr;
  };

public:
  List();

protected:
  struct Node *_dummy;
  void _push_back(const int);
  void _push_front(const int);
  void _pop_back(const int);
  void _pop_front(const int);
  int _at(const int);
};
} // namespace ex_1_1