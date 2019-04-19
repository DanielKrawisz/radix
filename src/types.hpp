#ifndef RADIX_TYPES
#define RADIX_TYPES

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <data/io/main.hpp>
#include <data/list/linked_list.hpp>
#include <data/map/rb.hpp>

namespace radix {

    template <typename X>
    using vector = const std::vector<X>;

    using string = std::string;
    
    using filepath = boost::filesystem::path;
    
    using output = const data::output;
    
    using ostream = std::ostream;
    using istream = std::istream;
    
    template <typename X>
    using ptr = std::shared_ptr<X>;
    
    template <typename X>
    using list = data::linked_list<X>;
    
    template <typename X, typename Y>
    using map = data::rb_map<X, Y>;

}

#endif
