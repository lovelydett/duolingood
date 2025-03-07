#include <format>
#include <stdexcept>

#define CHECK_BOUND(II, SS)                                                          \
    do {                                                                             \
        const int I = (II), S = (SS);                                                \
        \                                                           
        if (I < 0 || I >= S) {                                                       \
            throw std::runtime_error(std::format("Index {} out of bound {}", I, S)); \
        }                                                                            \
    } while (0);

#define SAFE_DELETE(P)        \
    do {                      \
        if ((P) != nullptr) { \
            delete ((P));     \
            (P) = nullptr;    \
        }                     \
    } while (0);