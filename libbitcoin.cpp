#include <bitcoin/node/full_node.hpp>

#include <boost/filesystem.hpp>

#include "types.hpp"
#include "options.hpp"

namespace radix {
    
    libbitcoin::node::configuration read_libbitcoin_options(options o) {
        throw 0;
    }
    
    string run_libbitcoin_node(libbitcoin::node::configuration config) {
        // TODO check if directory exists. 
        
        using node = libbitcoin::node::full_node;
        
        // Now that the directory is verified we can create the node for it.
        ptr<node> n = std::make_shared<node>(config);

        // The callback may be returned on the same thread.
        /*n->start(
            std::bind(&executor::handle_started,
                this, _1));

        // Wait for stop.
        stopping_.get_future().wait();

        LOG_INFO(LOG_NODE) << BN_NODE_STOPPING;

        // Close must be called from main thread.
        if (n->close())
            LOG_INFO(LOG_NODE) << BN_NODE_STOPPED;
        else
            LOG_INFO(LOG_NODE) << BN_NODE_STOP_FAIL;

        return true;*/
        
        throw 0;
    }
    
}

