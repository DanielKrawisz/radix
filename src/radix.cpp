#include "command.hpp"
 
int main(int argc, char *argv[]){
    return data::program::main{radix::execute, data::program::input_parser{{}, {}}}(argc, argv);
}
