#ifndef RADIX_WALLET
#define RADIX_WALLET

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

#include <nlohmann/json.hpp>

#include <abstractions/wallet/proto.hpp>

#include "types.hpp"
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

    using wallet = abstractions::wallet::proto;

    wallet restore_wallet(json);

    json save_wallet(wallet);

    template <typename f>
    output manage_wallet(f fun, options opts);

}

#endif
