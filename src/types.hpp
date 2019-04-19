#ifndef RADIX_TYPES
#define RADIX_TYPES

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <data/io/main.hpp>
#include <data/io/unimplemented.hpp>
#include <data/list/linked_list.hpp>
#include <data/map/rb.hpp>
#include <data/crypto/secp256k1.hpp>
#include <abstractions/key.hpp>

namespace radix {

    template <typename X>
    using vector = const std::vector<X>;

    using string = std::string;
    
    using filepath = boost::filesystem::path;
    
    using program_output = data::program::output;
    
    using ostream = std::ostream;
    using istream = std::istream;
    
    template <typename X>
    using ptr = std::shared_ptr<X>;
    
    template <typename X>
    using list = data::linked_list<X>;
    
    template <typename X, typename Y>
    using map = data::rb_map<X, Y>;
    
    using pubkey = abstractions::key::pubkey_claim<data::secp256k1::secret, data::secp256k1::pubkey>;
    using secret = abstractions::key::pair<data::secp256k1::secret, data::secp256k1::pubkey>;
    
    using unimplemented = data::method::unimplemented;

}

#endif
