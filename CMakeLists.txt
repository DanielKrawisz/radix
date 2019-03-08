cmake_minimum_required(VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)

project (radix)
find_package(Boost 1.67.0 COMPONENTS system regex program_options REQUIRED)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../boost_1_69_0/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../nlohmann/json/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../data/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../wallet-abstractions/include")

# swap this out for other things when we want to work with other coins. 
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-consensus/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-system/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-database/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-network/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-blockchain/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libbitcoin/libbitcoin-node/include")

find_package (Threads)

add_executable(radix

    radix.cpp
    
    ../wallet-abstractions/src/abstractions/wallet/wallet.cpp
    
    ../../libbitcoin/libbitcoin-system/src/config/checkpoint.cpp
    ../../libbitcoin/libbitcoin-system/src/formats/base_16.cpp
    ../../libbitcoin/libbitcoin-system/src/machine/number.cpp
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
    ../../libbitcoin/libbitcoin-system/src/wallet/electrum_dictionary_zh_Hans.cpp)
    
target_link_libraries(radix ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(radix ${Boost_LIBRARIES})
target_compile_options(radix PUBLIC -fext-numeric-literals)
