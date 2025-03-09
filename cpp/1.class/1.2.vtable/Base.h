#ifndef BASE_H
#define BASE_H

namespace ex_1_2 {

class Base {
public:
    int          m_data_base;
    virtual void funcA();
    virtual void funcB();
    virtual void funcC();
    void         funcD();
    virtual ~Base() = default;
};


}   // namespace ex_1_2

#endif