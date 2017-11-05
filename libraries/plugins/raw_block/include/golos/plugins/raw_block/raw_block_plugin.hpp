#pragma once

#include <appbase/application.hpp>

namespace golos {
    namespace plugin {
        namespace raw_block {

            class raw_block_plugin : public appbase::plugin<raw_block_plugin> {
            public:
                APPBASE_PLUGIN_REQUIRES()

                constexpr const static char *plugin_name = "raw_block";

                static const std::string &name() {
                    static std::string name = plugin_name;
                    return name;
                }

                raw_block_plugin();

                virtual ~raw_block_plugin();

                void plugin_initialize(const boost::program_options::variables_map &options) override;

                void plugin_startup() override;

                void plugin_shutdown() override;
            };

        }
    }
}
