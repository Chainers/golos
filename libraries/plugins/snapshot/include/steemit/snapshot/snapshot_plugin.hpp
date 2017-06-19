#ifndef GOLOS_SNAPSHOT_PLUGIN_HPP
#define GOLOS_SNAPSHOT_PLUGIN_HPP

#include <steemit/application/application.hpp>
#include <steemit/application/plugin.hpp>

#include <boost/bimap.hpp>

#include <sstream>
#include <string>

#define SNAPSHOT_PLUGIN_NAME "snapshot"

namespace steemit {
    namespace plugin {
        namespace snapshot {

            class snapshot_plugin : public steemit::application::plugin {
            public:
                /**
                 * The plugin requires a constructor which takes app.  This is called regardless of whether the plugin is loaded.
                 * The app parameter should be passed up to the superclass constructor.
                 */
                snapshot_plugin(steemit::application::application *app);

                /**
                 * Plugin is destroyed via base class pointer, so a virtual destructor must be provided.
                 */
                virtual ~snapshot_plugin();

                /**
                 * Every plugin needs a name.
                 */
                virtual std::string plugin_name() const override;

                /**
                 * Called when the plugin is enabled, but before the database has been created.
                 */
                virtual void plugin_initialize(const boost::program_options::variables_map &options) override;

                virtual void plugin_set_program_options(
                        boost::program_options::options_description &command_line_options,
                        boost::program_options::options_description &config_file_options) override;

                /**
                 * Called when the plugin is enabled.
                 */
                virtual void plugin_startup() override;

                const boost::bimap<std::string, std::string> &get_loaded_snapshots() const;

            private:
                void load_snapshots(const std::vector<std::string> &snapshots);

                boost::program_options::variables_map options;

                boost::bimap<std::string, std::string> loaded_snapshots;

                struct snapshot_plugin_impl;

                steemit::application::application *application;

                std::unique_ptr<snapshot_plugin_impl> pimpl;
            };
        }
    }
}

#endif //GOLOS_SNAPSHOT_PLUGIN_HPP