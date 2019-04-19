#include "wallet.hpp"

namespace radix {

    string read_file_as_string(std::ifstream& file) {
        std::stringstream sstr;
        sstr << file.rdbuf();
        return sstr.str();
    }

    template <typename f>
    output manage_wallet(f fun, options opts) {
        filepath input_filepath = opts.input_file();
        std::ifstream input_file{input_filepath.c_str(), std::ifstream::in};
        if (!input_file.is_open()) return {true, fail::cannot_read_file(input_filepath)};
        
        filepath output_filepath = opts.output_file();
        std::ofstream output_file{opts.output_file().c_str(), std::ifstream::out};
        if (!output_file.is_open()) return {true, fail::cannot_read_file(output_filepath)};
        
        output_file << save_wallet(fun(restore_wallet(json::parse(read_file_as_string(input_file))))).dump();
        
        return {};
    };

}
