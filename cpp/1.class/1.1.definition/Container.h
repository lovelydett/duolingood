namespace ex_1_1 {
class Container {
public:
  Container() = default;
  Container(const int);
  Container(const int, const int);
  virtual ~Container() = 0;
  void push_front(const int);
  void pop_front();
  void push_back(const int);
  void pop_back();
  void insert(const int idx, const int value);
  int operator[](const int idx) const;
  int size() const;

protected:
  virtual void _push_front(const int) = 0;
  virtual void _pop_front(const int) = 0;
  virtual void _push_back(const int) = 0;
  virtual void _pop_back(const int) = 0;
  virtual int _at(const int idx) = 0;

  int _size = 0;
  int _cap = 0;
};
} // namespace ex_1_1
