#ifndef RADIX_OPTIONS
#define RADIX_OPTIONS

//#include <cxxopts.hpp>

#include <bitcoin/node/configuration.hpp>

#include "types.hpp"

namespace radix {
    
    struct options {
        filepath input_file() const;
        filepath output_file() const;
        libbitcoin::node::configuration libbitcoin_configuration() const;
        ostream& output_stream() const;
        ostream& error_stream() const;
        istream& input_stream() const;
        
        static const options read(const list<string>);
    };
    
}

#endif
