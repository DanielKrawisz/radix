#include "command.hpp"
#include "help.hpp"
#include "version.hpp"
#include "wallet.hpp"

namespace radix {
        
    command::function command::from_name(name n) {
        switch (n) {
            default:
            case error:
                return nullptr;
            case help:
                return do_help;
            case version:
                return do_version;
            case run: 
                return do_run;
            case apply:
                return do_apply;
        }
    }
    
    const command command::read(data::program::input) {
        throw unimplemented{}; // TODO
    }
    
    program_output do_help(const list<string>, const options o) {
        print_help_message(o.output_stream());
        return {};
    }
    
    program_output do_version(const list<string>, const options o) {
        print_version(o.output_stream());
        return {};
    }
    
    program_output do_apply(const list<string>, const options o) {
        throw unimplemented{}; // TODO
    }
    
    program_output do_run(const list<string>, const options o) {
        throw unimplemented{}; // TODO
    }
    
}
