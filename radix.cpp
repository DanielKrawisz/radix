#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

#include<nlohmann/json.hpp>

#include<abstractions/wallet/proto.hpp>

#include<bitcoin/node.hpp>

template <typename X>
using vector = const std::vector<X>;

using string = std::string;

namespace fail {
    const string help = "Provide a single file name as input.";
    
    string cannot_read_file(string filename) {
        return "Cannot read " + filename + ". ";
    }
    
    string cannot_write_file(string filename) {
        return "Cannot write to " + filename + ". ";
    }
    
    string invalid_format(string filename) {
        return "Invalid format in " + filename + ". ";
    }
}

using json = nlohmann::json;

string read_file_as_string(string filepath) {
    std::ifstream ifs{filepath.c_str(), std::ifstream::in};
    if (!ifs.is_open()) return "";
    std::stringstream sstr;
    sstr << ifs.rdbuf();
    return sstr.str();
}

using wallet = abstractions::wallet::proto;

wallet restore_wallet(json);

json save_wallet(wallet);

string radix_proto_main(vector<string> opts) {
    if (opts.size() != 1) return fail::help;
    string input_filepath = opts[0];
    string output_filepath = input_filepath + ".next";
    
    std::ofstream output_file(output_filepath);
    if (!output_file.is_open()) return fail::cannot_read_file(output_filepath);
    
    string input_string = read_file_as_string(input_filepath);
    if (input_string == "") return fail::cannot_read_file(input_filepath);
    
    json input_json = json::parse(input_string);
    
    wallet w = restore_wallet(input_json);
    
    output_file << save_wallet(w).dump();
    
    return "";
};

vector<string> read_options(int argc, char *argv[]) {
    std::vector<std::string> options{static_cast<size_t>(argc)};
    for (int i = 0; i < argc; i ++) options[i] = std::string(argv[i]);
    return options;
}
 
int main(int argc, char *argv[]){
    return radix_proto_main(read_options(argc, argv)) == "" ? 0 : 1;
}
