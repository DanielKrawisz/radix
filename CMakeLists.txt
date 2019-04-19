cmake_minimum_required(VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)

project (radix)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# swap this out for other things when we want to work with other coins. 
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-consensus/include")

find_package(Boost 1.62.0 COMPONENTS system regex program_options thread log_setup log REQUIRED)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../boost/1_62_0/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../nlohmann/json/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../data/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../wallet-abstractions/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/secp256k1/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-system/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-database/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-network/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-consensus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-blockchain/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-node/include")

find_package (Threads)

add_compile_definitions(WITH_CONSENSUS)

add_executable(radix

    src/radix.cpp
    src/libbitcoin.cpp
    src/options.cpp
    src/command.cpp
    
    ../wallet-abstractions/src/abstractions/wallet/wallet.cpp
    
    ../data/src/data/map/rb.cpp

    #put consensus critical files here. 
    
    ../../libbitcoin/libbitcoin-blockchain/src/interface/block_chain.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/organizers/organize_header.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/organizers/organize_block.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/organizers/organize_transaction.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/validate/validate_block.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/validate/validate_header.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/validate/validate_input.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/validate/validate_transaction.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/populate/populate_base.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/populate/populate_block.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/populate/populate_chain_state.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/populate/populate_header.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/populate/populate_transaction.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/pools/block_pool.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/block_entry.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/header_entry.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/header_pool.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/header_branch.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/transaction_entry.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/transaction_pool.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/anchor_converter.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/child_closure_calculator.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/conflicting_spend_remover.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/priority_calculator.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/parent_closure_calculator.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/stack_evaluator.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/transaction_order_calculator.cpp
    ../../libbitcoin/libbitcoin-blockchain/src/pools/utilities/transaction_pool_state.cpp
    
    ../../libbitcoin/libbitcoin-blockchain/src/settings.cpp
    
    ../../libbitcoin/libbitcoin-node/src/protocols/protocol_block_in.cpp
    ../../libbitcoin/libbitcoin-node/src/protocols/protocol_header_in.cpp
    ../../libbitcoin/libbitcoin-node/src/protocols/protocol_transaction_in.cpp
    ../../libbitcoin/libbitcoin-node/src/protocols/protocol_transaction_out.cpp
    
    ../../libbitcoin/libbitcoin-node/src/utility/check_list.cpp
    ../../libbitcoin/libbitcoin-node/src/utility/performance.cpp
    ../../libbitcoin/libbitcoin-node/src/utility/reservation.cpp
    ../../libbitcoin/libbitcoin-node/src/utility/reservations.cpp
    
    ../../libbitcoin/libbitcoin-node/src/sessions/session_inbound.cpp
    ../../libbitcoin/libbitcoin-node/src/sessions/session_manual.cpp
    ../../libbitcoin/libbitcoin-node/src/sessions/session_outbound.cpp
    
    ../../libbitcoin/libbitcoin-node/src/full_node.cpp
    ../../libbitcoin/libbitcoin-node/src/settings.cpp
)

#target_link_libraries(abstractions ${LIBBITCOIN_LIBRARIES})
    
target_link_libraries(radix ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(radix ${Boost_LIBRARIES})
target_link_libraries(radix libsecp256k1.so)
target_link_libraries(radix libbitcoin-system.so)
target_link_libraries(radix libbitcoin-network.so)
target_link_libraries(radix libbitcoin-database.so)
target_link_libraries(radix libbitcoin-consensus.so)
target_compile_options(radix PUBLIC -fext-numeric-literals)
