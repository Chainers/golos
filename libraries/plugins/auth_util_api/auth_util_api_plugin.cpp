#include <golos/plugins/auth_util_api/auth_util_api.hpp>
#include <golos/plugins/auth_util_api/auth_util_api_plugin.hpp>

namespace golos {
    namespace plugins {
        namespace auth_util_api {

            auth_util_api_plugin::auth_util_api_plugin() {
            }

            void auth_util_api_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
                api = std::make_shared<auth_util_api>();
            }

            void auth_util_api_plugin::plugin_startup() {
            }

            void auth_util_api_plugin::plugin_shutdown() {
            }

        }
    }
} // golos::plugins::auth_util_api
