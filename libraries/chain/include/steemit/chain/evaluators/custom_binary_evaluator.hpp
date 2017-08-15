#ifndef GOLOS_CUSTOM_BINARY_EVALUATOR_HPP
#define GOLOS_CUSTOM_BINARY_EVALUATOR_HPP

#include "forward.hpp"

namespace steemit {
    namespace chain {

        class custom_binary_evaluator : public evaluator_impl<database_tag, custom_binary_evaluator> {
        public:
            typedef protocol::custom_binary_operation operation_type;

            template<typename DataBase>
            custom_binary_evaluator(DataBase &db) : evaluator_impl<database_tag, custom_binary_evaluator>(db) {
            }

            void do_apply(const protocol::custom_binary_operation &o);
        };
    }
}
#endif //GOLOS_CUSTOM_BINARY_EVALUATOR_HPP
