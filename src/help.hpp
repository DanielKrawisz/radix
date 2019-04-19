#ifndef RADIX_HELP
#define RADIX_HELP

#include "types.hpp"

namespace radix {
    
    const string Help = "I don't know.";
    
    inline void print_help_message(ostream& out) {
        out << Help;
    }
    
}

#endif
