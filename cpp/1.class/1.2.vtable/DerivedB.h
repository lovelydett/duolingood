#ifndef DERIVEDB_H
#define DERIVEDB_H

#include "Base.h"

namespace ex_1_2 {
class DerivedB : public Base {
public:
    char m_data_b;
    void funcC() override;
    ~DerivedB() override = default;
};
}   // namespace ex_1_2

#endif