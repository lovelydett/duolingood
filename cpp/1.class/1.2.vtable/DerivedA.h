#ifndef DERVEDA_H
#define DERVEDA_H

#include "Base.h"


namespace ex_1_2 {
    class DerivedA : public Base {
    public:
        char m_data_a;
        void funcA() override;
        void funcB() override;
        ~DerivedA() override = default;
    };
}


#endif