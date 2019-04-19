#include <iostream>

#include "types.hpp"
#include "options.hpp"
#include "command.hpp"

namespace radix {
    output main(list<string> args) {
        return execute(read_command(data::first(args)), options::read(data::rest(args)));
    };

}
 
int main(int argc, char *argv[]){
    return data::main(radix::main, argc, argv);
}
