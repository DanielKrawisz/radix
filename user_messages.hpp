#ifndef RADIX_USER_MESSAGES_HPP
#define RADIX_USER_MESSAGES_HPP

#include "types.hpp"

namespace radix {
    
    string concatinate() { return ""; }
    
    string concatinate(string s) { return s; }
    
    template <typename first>
    void attach(std::ostringstream& x, first s) {
        x << s;
    }
    
    template <typename first, typename... rest>
    void attach(std::ostringstream& x, first f, rest... a) {
        x << f;
        attach<rest...>(x, a...);
    }
    
    template <typename... args>
    string concatinate(args... a) {
        std::ostringstream x{};
        attach(x, a...);
        return x.str();
    }

    namespace fail {
        const string help = "Provide a single file name as input.";
        
        string cannot_read_file(filepath path) {
            return concatinate("Cannot read ", path.native(), ". ");
        }
        
        string cannot_write_file(filepath path) {
            return concatinate("Cannot write to ", path.native(), ". ");
        }
        
        string invalid_format(filepath path) {
            return concatinate("Invalid format in ", path.native(), ". ");
        }
    }

}

#endif
