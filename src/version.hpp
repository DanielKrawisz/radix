#ifndef RADIX_VERSION
#define RADIX_VERSION

#include "types.hpp"

namespace radix {
    
    const string Version = "Radix Wallet version negative infinity.";
    
    inline void print_version(ostream& out) {
        out << Version;
    }
    
}

#endif

