#pragma once

#include <iostream>
#include <typeinfo>

#include "literal/macro_helper.h"

namespace literal
{

// llvm include/llvm/Support/ErrorHandling.h llvm_unreachable
void
literal_unreachable_internal(const char *msg = nullptr, const char *file = nullptr, unsigned line = 0);

} // namepace literal

// macros

#define DBGEXPR(expr) \
    MACRO_BLOCK_BEGIN \
    std::cout \
        << "[DBGEXPR] { " << #expr << " } -> " << "(" << typeid(expr).name() << ") " << (expr) << std::endl; \
    MACRO_BLOCK_END

// llvm include/llvm/Support/ErrorHandling.h llvm_unreachable

#ifndef NDEBUG
#define literal_unreachable(msg) \
    ::literal::literal_unreachable_internal(msg, __FILE__, __LINE__)
#else
#define literal_unreachable(msg) \
    ::literal::literal_unreachable_internal()
#endif
