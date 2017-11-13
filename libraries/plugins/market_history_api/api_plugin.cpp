#include <golos/plugins/market_history_api/api_plugin.hpp>
#include <golos/plugins/market_history_api/api.hpp>

namespace golos {
    namespace plugins {
        namespace market_history {

            api_plugin::api_plugin() {
            }

            api_plugin::~api_plugin() {
            }

            void api_plugin::set_program_options(boost::program_options::options_description &cli, boost::program_options::options_description &cfg) {
            }

            void api_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
                api_ptr = std::make_shared<api>();
            }

            void api_plugin::plugin_startup() {
            }

            void api_plugin::plugin_shutdown() {
            }
        }
    }
} // golos::plugins::chain