#include "libbitcoin.hpp"

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
    
    // Manage the race between console stop and server stop.
    void node_manager::stop(const code& ec) {
        throw unimplemented{}; // TODO
    }

    // This is the end of the run sequence.
    void node_manager::handle_running(const code& ec) {
        if (ec)  {
            LOG_INFO(LOG_NODE) << boost::format(BN_NODE_START_FAIL) % ec.message();
            stop(ec);
            return;
        }

        LOG_INFO(LOG_NODE) << BN_NODE_STARTED;
    }

    // This is the end of the stop sequence.
    void node_manager::handle_stopped(const code& ec) {
        stop(ec);
    }
    
    // Handle the completion of the start sequence and begin the run sequence.
    void node_manager::handle_started(const code& ec) {
        if (ec) {
            LOG_ERROR(LOG_NODE) << boost::format(BN_NODE_START_FAIL) % ec.message();
            stop(ec);
            return;
        }

        LOG_INFO(LOG_NODE) << BN_NODE_SEEDED;

        // This is the beginning of the stop sequence.
        Node->subscribe_stop(
            std::bind(&node_manager::handle_stopped,
                this, std::placeholders::_1));

        // This is the beginning of the run sequence.
        Node->run(
            std::bind(&node_manager::handle_running,
                this, std::placeholders::_1));
    }
        
    /*code node_manager::start(){
        
        LOG_INFO(LOG_NODE) << BN_NODE_STARTING;
        
        // The callback may be returned on the same thread.
        Node->start(
            std::bind(&node_manager::handle_started,
                this, std::placeholders::_1));

        // Wait for stop.
        ExitResponse.get_future().wait();

        LOG_INFO(LOG_NODE) << BN_NODE_STOPPING;

        // Close must be called from main thread.
        if (Node->close())
            LOG_INFO(LOG_NODE) << BN_NODE_STOPPED;
        else
            LOG_INFO(LOG_NODE) << BN_NODE_STOP_FAIL;
            
            
        }
    
    };*/
    
}

