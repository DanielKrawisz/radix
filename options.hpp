#ifndef RADIX_OPTIONS_HPP
#define RADIX_OPTIONS_HPP

//#include <cxxopts.hpp>

#include "types.hpp"

namespace radix {
    
    struct options {
        filepath InputWalletPath;
        filepath OutputWalletPath;
        filepath BlockchainDatabasePath;
    };
    
    options read_options(int argc, char *argv[]);
    
}

#endif
