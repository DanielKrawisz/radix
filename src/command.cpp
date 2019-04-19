#include "command.hpp"
#include "help.hpp"
#include "version.hpp"

namespace radix {
    
    const output do_help(const options o) {
        print_help_message(o.output_stream());
        return {};
    }
    
    output do_version(const options o) {
        print_version(o.output_stream());
        return {};
    }
    
    output do_run(const options o) {
        
    }
    
    output execute(command c, const options o) {
        switch (c) {
            default:
            case error:
                return {true, "Unrecognized command"};
            case help:
                return do_help(o);
            case version:
                return do_version(o);
            case run:
                return do_run(o);
        }
        
    }
    
}
