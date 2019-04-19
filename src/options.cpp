#include "options.hpp"

namespace radix {
    
    const options options::read(const list<string>) {
        throw unimplemented{}; // TODO
    }
     
    filepath options::input_file() const {
        throw unimplemented{}; // TODO
    }
    
    filepath options::output_file() const {
        throw unimplemented{}; // TODO
    }
    
    libbitcoin::node::configuration options::libbitcoin_configuration() const {
        throw unimplemented{}; // TODO
    }
    
    ostream& options::output_stream() const {
        throw unimplemented{}; // TODO
    }
    
    ostream& options::error_stream() const {
        throw unimplemented{}; // TODO
    }
    
    istream& options::input_stream() const {
        throw unimplemented{}; // TODO
    }
    
}
