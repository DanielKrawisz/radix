#ifndef RADIX_COMMAND
#define RADIX_COMMAND

#include "types.hpp"
#include "options.hpp"

namespace radix {
    
    program_output do_help(const list<string>, const options);
    
    program_output do_version(const list<string>, const options);
    
    program_output do_run(const list<string>, const options);
    
    program_output do_apply(const list<string>, const options);
    
    struct command {
        
        using function = program_output (*)(const list<string>, const options);
        
        enum name {
            error = 0,
            help = 1, 
            version = 2,
            run = 3, 
            apply = 4, 
        };
        
        static function from_name(name n);
        
        name Name;
        
        const list<string> Arguments;
        
        const options Options;
        
        program_output execute() const {
            function f = from_name(Name);
            if (f == nullptr) return {true, "Unrecognized command"};
            return f(Arguments, Options);
        }
        
        static const command read(data::program::input);
    
    };
    
    inline program_output execute(data::program::input arg) {
        return command::read(arg).execute();
    }
    
}

#endif
