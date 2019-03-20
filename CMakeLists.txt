cmake_minimum_required(VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)

project (radix)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

#find_package(libbitcoin REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# swap this out for other things when we want to work with other coins. 
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-consensus/include")

find_package(Boost 1.67.0 COMPONENTS system regex program_options thread log_setup log REQUIRED)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../boost_1_69_0/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../nlohmann/json/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../data/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../wallet-abstractions/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-system/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-system/build-libbitcoin-system/secp256k1/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-database/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-network/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-blockchain/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-node/include")

find_package (Threads)

add_executable(radix

    radix.cpp
    libbitcoin.cpp
    options.cpp
    
    ../wallet-abstractions/src/abstractions/wallet/wallet.cpp
    
    ../../libbitcoin/libbitcoin-system/src/error.cpp
    ../../libbitcoin/libbitcoin-system/src/settings.cpp
    
    ../../libbitcoin/libbitcoin-system/src/config/authority.cpp
    ../../libbitcoin/libbitcoin-system/src/config/checkpoint.cpp
    ../../libbitcoin/libbitcoin-system/src/config/endpoint.cpp
    ../../libbitcoin/libbitcoin-system/src/config/block.cpp
    ../../libbitcoin/libbitcoin-system/src/config/base16.cpp
    
    ../../libbitcoin/libbitcoin-system/src/formats/base_16.cpp
    
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_en.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_es.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_ja.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_it.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_fr.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_ko.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_zh_Hans.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/dictionary_zh_Hant.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_en.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_es.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_ja.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_pt.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_zh_Hans.cpp
    
    ../../libbitcoin/libbitcoin-system/src/unicode/ifstream.cpp
    ../../libbitcoin/libbitcoin-system/src/unicode/ofstream.cpp
    
    ../../libbitcoin/libbitcoin-system/src/utility/deadline.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/dispatcher.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/istream_reader.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/ostream_writer.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/pseudo_random.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/sequencer.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/socket.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/thread.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/threadpool.cpp
    ../../libbitcoin/libbitcoin-system/src/utility/work.cpp

    ../../libbitcoin/libbitcoin-system/src/math/hash.cpp
    ../../libbitcoin/libbitcoin-system/src/math/ec_scalar.cpp
    ../../libbitcoin/libbitcoin-system/src/math/ec_point.cpp
    ../../libbitcoin/libbitcoin-system/src/math/elliptic_curve.cpp
    ../../libbitcoin/libbitcoin-system/src/math/secp256k1_initializer.cpp
    ../../libbitcoin/libbitcoin-system/src/math/external/crypto_scrypt.c
    ../../libbitcoin/libbitcoin-system/src/math/external/pkcs5_pbkdf2.c
    ../../libbitcoin/libbitcoin-system/src/math/external/ripemd160.c
    ../../libbitcoin/libbitcoin-system/src/math/external/sha1.c
    ../../libbitcoin/libbitcoin-system/src/math/external/sha256.c
    ../../libbitcoin/libbitcoin-system/src/math/external/sha512.c
    ../../libbitcoin/libbitcoin-system/src/math/external/hmac_sha256.c
    ../../libbitcoin/libbitcoin-system/src/math/external/hmac_sha512.c
    
    ../../libbitcoin/libbitcoin-system/src/wallet/ec_private.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/ec_public.cpp
    ../../libbitcoin/libbitcoin-system/src/wallet/payment_address.cpp
    
    ../../libbitcoin/libbitcoin-system/src/machine/number.cpp
    ../../libbitcoin/libbitcoin-system/src/machine/interpreter.cpp
    ../../libbitcoin/libbitcoin-system/src/machine/program.cpp
                                                                                                                                                                                                                                                                
    ../../libbitcoin/libbitcoin-system/src/chain/block.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/compact.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/chain_state.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/header.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/point.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/input.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/output.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/transaction.cpp
    ../../libbitcoin/libbitcoin-system/src/chain/script.cpp
                                                                                                                                                                                                                                                                
    ../../libbitcoin/libbitcoin-system/src/message/address.cpp
    ../../libbitcoin/libbitcoin-system/src/message/alert.cpp
    ../../libbitcoin/libbitcoin-system/src/message/block_transactions.cpp
    ../../libbitcoin/libbitcoin-system/src/message/block.cpp
    ../../libbitcoin/libbitcoin-system/src/message/compact_block.cpp
    ../../libbitcoin/libbitcoin-system/src/message/fee_filter.cpp
    ../../libbitcoin/libbitcoin-system/src/message/filter_add.cpp
    ../../libbitcoin/libbitcoin-system/src/message/filter_clear.cpp
    ../../libbitcoin/libbitcoin-system/src/message/filter_load.cpp
    ../../libbitcoin/libbitcoin-system/src/message/get_address.cpp
    ../../libbitcoin/libbitcoin-system/src/message/get_block_transactions.cpp
    ../../libbitcoin/libbitcoin-system/src/message/get_blocks.cpp
    ../../libbitcoin/libbitcoin-system/src/message/get_data.cpp
    ../../libbitcoin/libbitcoin-system/src/message/get_headers.cpp
    ../../libbitcoin/libbitcoin-system/src/message/header.cpp
    ../../libbitcoin/libbitcoin-system/src/message/headers.cpp
    ../../libbitcoin/libbitcoin-system/src/message/heading.cpp
    ../../libbitcoin/libbitcoin-system/src/message/inventory.cpp
    ../../libbitcoin/libbitcoin-system/src/message/inventory_vector.cpp
    ../../libbitcoin/libbitcoin-system/src/message/memory_pool.cpp
    ../../libbitcoin/libbitcoin-system/src/message/messages.cpp
    ../../libbitcoin/libbitcoin-system/src/message/merkle_block.cpp
    ../../libbitcoin/libbitcoin-system/src/message/network_address.cpp
    ../../libbitcoin/libbitcoin-system/src/message/not_found.cpp
    ../../libbitcoin/libbitcoin-system/src/message/prefilled_transaction.cpp
    ../../libbitcoin/libbitcoin-system/src/message/ping.cpp
    ../../libbitcoin/libbitcoin-system/src/message/pong.cpp
    ../../libbitcoin/libbitcoin-system/src/message/reject.cpp
    ../../libbitcoin/libbitcoin-system/src/message/send_compact.cpp
    ../../libbitcoin/libbitcoin-system/src/message/send_headers.cpp
    ../../libbitcoin/libbitcoin-system/src/message/transaction.cpp
    ../../libbitcoin/libbitcoin-system/src/message/verack.cpp
    ../../libbitcoin/libbitcoin-system/src/message/version.cpp
    
    ../../libbitcoin/libbitcoin-network/src/sessions/session.cpp
    ../../libbitcoin/libbitcoin-network/src/sessions/session_seed.cpp
    
    ../../libbitcoin/libbitcoin-network/src/acceptor.cpp
    ../../libbitcoin/libbitcoin-network/src/channel.cpp
    ../../libbitcoin/libbitcoin-network/src/settings.cpp
    ../../libbitcoin/libbitcoin-network/src/hosts.cpp
    ../../libbitcoin/libbitcoin-network/src/connector.cpp
    ../../libbitcoin/libbitcoin-network/src/message_subscriber.cpp
    ../../libbitcoin/libbitcoin-network/src/p2p.cpp
    ../../libbitcoin/libbitcoin-network/src/proxy.cpp
    
    ../../libbitcoin/libbitcoin-node/src/utility/reservations.cpp
    
    ../../libbitcoin/libbitcoin-node/src/full_node.cpp
)

#target_link_libraries(abstractions ${LIBBITCOIN_LIBRARIES})
    
target_link_libraries(radix ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(radix ${Boost_LIBRARIES})
target_compile_options(radix PUBLIC -fext-numeric-literals)
