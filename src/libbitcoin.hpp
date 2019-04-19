#ifndef RADIX_LIBBITCOIN
#define RADIX_LIBBITCOIN

#include <bitcoin/node/full_node.hpp>

#include <boost/filesystem.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/format.hpp>

#include <functional>

#include "types.hpp"
#include "options.hpp"
#include "command.hpp" 

namespace radix {
    
    using node = libbitcoin::node::full_node;
        
    typedef std::error_code code;
    
    class node_manager {
        
        static std::promise<code> ExitResponse;
        
        ptr<node> Node;
        
        // Manage the race between console stop and server stop.
        void stop(const code& ec);

        // This is the end of the run sequence.
        void handle_running(const code& ec);

        // This is the end of the stop sequence.
        void handle_stopped(const code& ec);
        
        // Handle the completion of the start sequence and begin the run sequence.
        void handle_started(const code& ec);
    
    public:
        node_manager(libbitcoin::node::configuration config) : Node{std::make_shared<node>(config)} {}
        
        code start();
        
        code stop();
    
    };
    
}

#endif
