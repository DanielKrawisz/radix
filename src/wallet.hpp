#ifndef RADIX_WALLET
#define RADIX_WALLET

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

#include <nlohmann/json.hpp>

#include <abstractions/wallet/proto.hpp>

#include "options.hpp"
#include "user_messages.hpp"
#include "command.hpp"

namespace abstractions {
    namespace wallet {
        const satoshi dust = 0; // TODO
    }
}

namespace radix {

    using json = nlohmann::json;

    string read_file_as_string(std::ifstream& file);

    using wallet = const abstractions::wallet::proto;

    wallet restore_wallet(const json);

    json save_wallet(const wallet);
    
    void print(const wallet, ostream&);
    
    wallet import_key(const wallet, const secret);
    
    //transaction sign_transaction(const wallet, const transaction);

    template <typename f>
    program_output manage_wallet(f fun, const options opts);
    
    namespace instruction {
        
        struct print {
            ostream& Out;
            
            wallet operator()(const wallet w) {
                radix::print(w, Out);
                return w;
            }
        };
    
        struct import_key {
            ostream& Out;
            secret Secret;
            
            wallet operator()(const wallet w) {
                wallet imported = radix::import_key(w, Secret);
                radix::print(imported, Out);
                return imported;
            };
        
        };
    
    }
    
    struct manager {
        wallet Wallet; 
        options Options;
            
        program_output operator()(list<string> instruction);
    };

}

#endif
