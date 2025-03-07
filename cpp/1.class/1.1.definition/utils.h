#include <format>
#include <stdexcept>

#define CHECK_BOUND(II, SS)                                                          \
    do {                                                                             \
        if ((II) < 0 || (II) >= (SS)) {                                                       \
            throw std::runtime_error(std::format("Index {} out of bound {}", (II), (SS))); \
        }                                                                            \
    } while (0);

#define SAFE_DELETE(P)        \
    do {                      \
        if ((P) != nullptr) { \
            delete ((P));     \
            (P) = nullptr;    \
        }                     \
    } while (0);
