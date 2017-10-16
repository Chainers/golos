#pragma once
#include <steemit/plugins/json_rpc/json_rpc_plugin.hpp>
#include <steemit/plugins/chain/chain_plugin.hpp>
#include <steemit/plugins/p2p/p2p_plugin.hpp>

#include <appbase/application.hpp>

#define STEEM_NETWORK_BROADCAST_API_PLUGIN_NAME "network_broadcast_api"

namespace steemit { namespace plugins { namespace network_broadcast_api {

            using namespace appbase;

            class network_broadcast_api_plugin final : public appbase::plugin< network_broadcast_api_plugin > {
            public:
                APPBASE_PLUGIN_REQUIRES(
                        (json_rpc::json_rpc_plugin)
                        (chain::chain_plugin)
                        (p2p::p2p_plugin)
                )

                network_broadcast_api_plugin();
                ~network_broadcast_api_plugin();

                static const std::string& name() { static std::string name = STEEM_NETWORK_BROADCAST_API_PLUGIN_NAME; return name; }

                void set_program_options( options_description& cli, options_description& cfg ) override;
                void plugin_initialize( const variables_map& options ) override;
                void plugin_startup() override;
                void plugin_shutdown() override;

                boost::signals2::connection on_applied_block_connection;

                std::shared_ptr< class network_broadcast_api > api;
            };

        } } }
