#include <iostream>

// This can not handle the case when a or b is function call or "a++"
// Consider using std::max or inline function
#define MAX(a, b) ((a) > (b) ? (a) : (b))


// If neccessary use temp variables
#define MAX2(a, b)          \
    ({                      \
        decltype(a) _a = a; \
        decltype(b) _b = b; \
        _a > _b ? _a : _b;  \
    })

// Better alternative:
template <typename T>
inline T max(T&& a, T&& b) {
    return a > b ? a : b;
}

template <typename T>
inline T max(const T& a, const T& b) {
    return a > b ? a : b;
}

int main(int argc, char** argv) {
    int a = 1, b = 1;

    // Correct: 1
    std::cout << MAX(a, b) << std::endl;

    // Incorrect: should be 2 but got 3
    std::cout << MAX(++a, b) << std::endl;

    a = 1, b = 1;
    // This oututs 2, avoid re-executing expression
    std::cout << MAX2(++a, b) << std::endl;

    a = 1, b = 1;
    std::cout << max(a + 1, b) << std::endl;

    return 0;
}