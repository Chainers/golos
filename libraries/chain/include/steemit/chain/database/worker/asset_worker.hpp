#ifndef GOLOS_ASSET_WORKER_HPP
#define GOLOS_ASSET_WORKER_HPP

#include <steemit/chain/database/database_worker.hpp>
#include <steemit/protocol/config.hpp>
#include <steemit/chain/chain_objects/global_property_object.hpp>
#include <steemit/chain/database/database_policy.hpp>

namespace steemit {
    namespace chain {

        class asset_worker final : public database_worker_t<database_t> {
        public:
            asset_worker(database_t &);
        };
    }
}

#endif //GOLOS_ASSET_WORKER_HPP
