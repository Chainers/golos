#ifndef GOLOS_FOLLOW_EVALUATORS_HPP
#define GOLOS_FOLLOW_EVALUATORS_HPP

#include <steemit/plugins/follow/follow_operations.hpp>

#include <steemit/chain/evaluator.hpp>

namespace steemit {
    namespace plugins {
        namespace follow {
            class follow_evaluator
                    : public steemit::chain::evaluator<follow_evaluator, 0, 17, 0, follow_plugin_operation> {
            public:
                typedef follow_operation operation_type;

                follow_evaluator(chain::database &db, follow_plugin *plugin)
                        : steemit::chain::evaluator<follow_evaluator, 0, 17, 0, follow_plugin_operation>(db),
                          _plugin(plugin) {
                }

                void do_apply(const follow_operation &o);

                follow_plugin *_plugin;
            };

            class reblog_evaluator
                    : public steemit::chain::evaluator<reblog_evaluator, 0, 17, 0, follow_plugin_operation> {
            public:
                typedef reblog_operation operation_type;

                reblog_evaluator(chain::database &db, follow_plugin *plugin)
                        : steemit::chain::evaluator<reblog_evaluator, 0, 17, 0, follow_plugin_operation>(db),
                          _plugin(plugin) {
                }

                void do_apply(const reblog_operation &o);

                follow_plugin *_plugin;
            };
        }
    }
}

#endif //GOLOS_FOLLOW_EVALUATORS_HPP
