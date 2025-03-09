#include "Base.h"
#include "DerivedA.h"
#include "DerivedB.h"

#include <iostream>

int main() {
    // Check the vtable of Base, DerivedA, DerivedB
    ex_1_2::Base     base;
    ex_1_2::DerivedA derived_a;
    ex_1_2::DerivedB derived_b;

    // Goal: Check the address of three classes
    // Expected: Should be different
    std::cout << "Check the address of three classes" << std::endl;
    std::cout << "Base address: " << &base << std::endl;
    std::cout << "DerivedA address: " << &derived_a << std::endl;
    std::cout << "DerivedB address: " << &derived_b << std::endl;
    std::cout << std::endl;

    // Goal: Get the vtable address of Base, DerivedA, DerivedB
    // Expected: Should be the same
    auto raw_base     = reinterpret_cast<void**>(&base);  // First get the address of the object and cast it to a pointer to a (void*) pointer
    auto raw_derived_a = reinterpret_cast<void**>(&derived_a);
    auto raw_derived_b = reinterpret_cast<void**>(&derived_b);

    std::cout << "Check the vtable address of three classes" << std::endl;
    std::cout << "Base vtable address: " << *raw_base << std::endl;  // And then deref the pointer to get the vtable address value
    std::cout << "DerivedA vtable address: " << *raw_derived_a << std::endl;
    std::cout << "DerivedB vtable address: " << *raw_derived_b << std::endl;
    std::cout << std::endl;

    // Goal: Check the vtable items of Base
    // Expected: The address of Base::funcA, Base::funcB, Base::funcC, Base::~Base
    std::cout << "Check the vtable items of Base" << std::endl;
    void **func_ptr = reinterpret_cast<void**>(*raw_base);  // Must deref to get the first item in the vtable
    for (int i = 0; i < 4; ++i) {
        std::cout << "Item " << i << ": " << func_ptr[i] << std::endl;
    }
    std::cout << std::endl;

    // Goal: Check the vtable items of DerivedA
    // Expected: A and B are different, C is the same as Base::funcC
    std::cout << "Check the vtable items of DerivedA" << std::endl;
    func_ptr = reinterpret_cast<void**>(*raw_derived_a);
    for (int i = 0; i < 4; ++i) {
        std::cout << "Item " << i << ": " << func_ptr[i] << std::endl;
    }
    std::cout << std::endl;

    // Goal: Check the vtable items of DerivedB
    // Expected: A, B are the same as Base::funcA, Base::funcB, C is different
    std::cout << "Check the vtable items of DerivedB" << std::endl;
    func_ptr = reinterpret_cast<void**>(*raw_derived_b);
    for (int i = 0; i < 4; ++i) {
        std::cout << "Item " << i << ": " << func_ptr[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}