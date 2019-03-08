#include <iostream>
#include <fstream>
#include <sstream>

#include <nlohmann/json.hpp>

#include <abstractions/wallet/proto.hpp>

#include <bitcoin/node/configuration.hpp>

#include "types.hpp"
#include "options.hpp"

namespace abstractions {
    namespace wallet {
        const satoshi dust = 0; // TODO
    }
}

namespace radix {

    string run_libbitcoin_node(libbitcoin::node::configuration config);
    
    string concatinate() { return ""; }
    
    string concatinate(string s) { return s; }
    
    template <typename first>
    void attach(std::ostringstream& x, first s) {
        x << s;
    }
    
    template <typename first, typename... rest>
    void attach(std::ostringstream& x, first f, rest... a) {
        x << f;
        attach<rest...>(x, a...);
    }
    
    template <typename... args>
    string concatinate(args... a) {
        std::ostringstream x{};
        attach(x, a...);
        return x.str();
    }

    namespace fail {
        const string help = "Provide a single file name as input.";
        
        string cannot_read_file(filepath path) {
            return concatinate("Cannot read ", path.native(), ". ");
        }
        
        string cannot_write_file(filepath path) {
            return concatinate("Cannot write to ", path.native(), ". ");
        }
        
        string invalid_format(filepath path) {
            return concatinate("Invalid format in ", path.native(), ". ");
        }
    }

    using json = nlohmann::json;

    string read_file_as_string(filepath path) {
        std::ifstream ifs{path.c_str(), std::ifstream::in};
        if (!ifs.is_open()) return std::string("");
        std::stringstream sstr;
        sstr << ifs.rdbuf();
        return sstr.str();
    }

    using wallet = abstractions::wallet::proto;

    wallet restore_wallet(json);

    json save_wallet(wallet);

    string main(options opts) {
        /*if (!output_file.is_open()) return fail::cannot_read_file(opts.OutputWalletPath);
        
        string input_string = read_file_as_string(opts.InputWalletPath);
        if (input_string == "") return fail::cannot_read_file(opts.InputWalletPath);
        
        json input_json = json::parse(input_string);
        
        wallet w = restore_wallet(input_json);
        
        output_file << save_wallet(w).dump();*/
        
        return "";
    };

}
 
int main(int argc, char *argv[]){
    return radix::main(radix::read_options(argc, argv)) == "" ? 0 : 1;
}
