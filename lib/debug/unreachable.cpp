// #include <iostream>
#include <cstdio>
#include <cstdlib>

#include "literal/debug.h"

void literal::literal_unreachable_internal(const char *msg, const char *file, unsigned line)
{
    // if (msg)
    //     std::cerr << msg << "\n";
    // std::cerr << "UNREACHABLE executed";
    // if (file)
    //     std::cerr << " at " << file << ":" << line;
    // std::cerr << "!\n";
    if ( msg  ) fputs(msg, stderr);
    fprintf(stderr, "UNREACHABLE executed");
    if ( file ) fprintf(stderr, " at %s:%u", file, line);
    fputs("!", stderr);
    abort();
}
