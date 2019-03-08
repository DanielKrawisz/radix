#ifndef RADIX_TYPES_HPP
#define RADIX_TYPES_HPP

#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace radix {

    template <typename X>
    using vector = const std::vector<X>;

    using string = std::string;
    
    using filepath = boost::filesystem::path;

}

#endif
