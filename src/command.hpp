#ifndef RADIX_COMMAND
#define RADIX_COMMAND

#include "types.hpp"
#include "options.hpp"

namespace radix {
        
    enum command {
        error = 0,
        help = 1, 
        version = 2,
        run = 3, 
    };
    
    command read_command(string);
    
    output do_help(options);
    
    output do_version(options);
    
    output do_run(options);
        
    output execute(command, options);
    
}

#endif
