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

#define BN_NODE_STARTING \
    "Please wait while the node is starting..."
#define BN_NODE_START_FAIL \
    "Node failed to start with error, %1%."
#define BN_NODE_SEEDED \
    "Seeding is complete."
#define BN_NODE_STARTED \
    "Node is started."
#define BN_NODE_STOPPING \
    "Please wait while the node is stopping..."
#define BN_NODE_STOP_FAIL \
    "Node failed to stop properly, see log."
#define BN_NODE_STOPPED \
    "Node stopped successfully."

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
    
    output command_run(options);
    
    code run_libbitcoin_node(libbitcoin::node::configuration config);
    
}

#endif
