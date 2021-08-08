#pragma once
#ifndef LITERAL_MACRO_HELPER_H
#define LITERAL_MACRO_HELPER_H

#define MACRO_BLOCK_BEGIN    do
#define MACRO_BLOCK_END      } while (0)

#define MACRO_CONCAT(a, b) a##b

#endif /* LITERAL_MACRO_HELPER_H */