cmake_minimum_required(VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)
project (radix)
find_package(Boost 1.67.0 COMPONENTS system REQUIRED)
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
add_executable(radix radix.cpp)
target_compile_options(radix PUBLIC -fext-numeric-literals)
